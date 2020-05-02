/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         terminal program
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          19.03.2018
 *
 *--------------------------------------------------------------------
 */
#include <stdio.h>

#include "platform.h"
#include "term.h"
#include "uart.h"
#include "string.h"
#include "stdarg.h"
#include "utils/util.h"

typedef enum
{
  uart0 = 1,
  uart1 = 2,
  lpuart0 = 4,
  uartAll = (uart0 | uart1 | lpuart0)
} tUart;


static tUart destination;
static tCommandLineHandler *head = NULL;

void term_register_command_line_handler(tCommandLineHandler *clh, char* cmd, char *cmdDesc, cmdHandler h)
{
  clh->next = head;
  head = clh;

  strncpy(clh->cmd, cmd, sizeof(clh->cmd));
  strcat(clh->cmd, " ");
  strncpy(clh->cmdDesc, cmdDesc, sizeof(clh->cmdDesc));
  clh->cmdHandler = h;
}

/**
 * Writes a character to the uart
 * The output is sent to the uart which received the last command
 *
 * @param[in] ch
 *   the character to send
 */
void term_write_char(char ch)
{
  if (TGT_IS_MCCAR)
  {
    // check if uart0 is enabled
    #if (UART0_EN)
      if (destination & uart0) uart0WriteChar(ch);
    #endif

    // check if lpuart0 is enabled
    #if (LPUART0_EN)
      if (destination & lpuart0) lpuart0WriteChar(ch);
    #endif
  }

  if (TGT_IS_TINYK22)
  {
    // check if uart1 is enabled
    #if (UART1_EN)
      if (destination & uart1) uart1WriteChar(ch);
    #endif
  }
}

/**
 * Writes a null terminated string in the send buffer. If the
 * string is null, the function returns immediately.
 *
 * @param[in] str
 *   the null terminated string to send
 */
void term_write(const char *str)
{
  if (str == NULL) return;
  while (*str != '\0') term_write_char(*str++);
}

void term_write_num32s(int32_t value)
{
  char str[sizeof("-2147483648")];
  utilNum32sToStr(str, sizeof(str), value);
  term_write(str);
}

void term_write_num16s(int16_t value)
{
  char str[sizeof("-32768")];
  utilNum16sToStr(str, sizeof(str), value);
  term_write(str);
}

/**
 * Writes a null terminated string in the send buffer. If the
 * string is null, only a new new line character is sent.
 *
 * @param[in] str
 *   the null terminated string to send
 */
void term_write_line(const char *str)
{
  term_write(str);
  term_write_char(NEW_LINE);
}

void term_write_line_format(const char *format, ...)
{
  // buffer max 100
  char buffer[100];

  va_list arglist;
  va_start( arglist, format );
  vsnprintf(buffer, 100, format, arglist);
  va_end( arglist );

  term_write_line(buffer);
}

/**
 * Writes a substring in the send buffer.
 *
 * @param[in] str
 *   the null terminated string to send
 * @param[in] start
 *   the start position of the substring to send
 * @param[in] length
 *   the number of characters to send
 */
void term_write_sub_string(char *str, uint8_t start, uint8_t length)
{
  str += start;
  while(length--) term_write_char(*str++);
}

/**
 * Parses one command line and executes the appropriate command.
 *
 * @param[in] cmd
 *   the null terminated string to process
 */
void term_parse_command(char *cmd)
{
  uint8_t subCmdLength = 0;
  tError result = EC_INVALID_CMD;
  tCommandLineHandler *clh = head;
  char buf[16];

  if (strcmp(cmd, "help") == 0)
  {
    term_write_line(NULL);
    term_write_line(">>> MC-Car v2 terminal ready <<<");
    term_write_line("valid commands are:");
    while(clh != NULL)
    {
      term_write("  ");
      term_write(clh->cmd);
      term_write("-> ");
      term_write_line(clh->cmdDesc);
      clh = clh->next;
    }
    result = EC_SUCCESS;
  }
  else
  {
    while(clh != NULL)
    {
      if (strncmp(cmd, clh->cmd, strlen(clh->cmd)) == 0)
      {
        subCmdLength = strlen(clh->cmd);
        result = clh->cmdHandler(cmd + strlen(clh->cmd));
        break;
      }
      clh = clh->next;
    }
  }

  if (result != EC_SUCCESS)
  {
    term_write_line(NULL);
    term_write(cmd);
    term_write_line(": command not found!");
    term_write("Error Code: ");
    buf[0] = '\0';
    utilNum16uToStr(buf, sizeof(buf), result);
    term_write_line(buf);
    term_write("Enter '");
    term_write_sub_string(cmd, 0, subCmdLength);
    term_write_line("help' for a list of valid commands.");
  }
}

/**
 * @brief Terminal do work
 *
 * This function reads a line from the uart and calls the
 * termParseCommand function to process the command.
 */
void term_do_work(void)
{
  char cmd[512];
  if (TGT_IS_MCCAR)
  {
    #if (UART0_EN)
      if (uart0HasLineReceived())
      {
        destination = uart0;
        uart0ReadLine(cmd, sizeof(cmd));            // process uart data from debug interface
        term_parse_command(cmd);
      }
    #endif

    #if (LPUART0_EN)
      if (lpuart0HasLineReceived())                 // process uart data from bluetooth interface
      {
        destination = lpuart0;
        lpuart0ReadLine(cmd, sizeof(cmd));
        term_parse_command(cmd);
      }
    #endif
  }

  if (TGT_IS_TINYK22)
  {
    #if (UART1_EN)
      if (uart1HasLineReceived())                   // process uart data from debug interface
      {
        destination = uart1;
        uart1ReadLine(cmd, sizeof(cmd));
        term_parse_command(cmd);
      }
    #endif
  }
}

/**
 * Initialize the terminal with the desired baudrate.
 */
void term_init(void)
{
	// baudrate define by config tool => Periperals > UART
  uint16_t baudrate = 0;
  // Send the first message to all uarts
  destination = uartAll;

  if (TGT_IS_MCCAR)
  {
    // initialize uart0 only if the uart is enabled
    #if (UART0_EN)
      uart0Init();
    #endif

    // initialize lpuart0 only if the uart is enabled
    #if (LPUART0_EN)
      lpuart0Init(baudrate);
    #endif

    //termWriteLine(NULL);
    //termWriteLine("MC-Car ready... :-)");
  }

  if (TGT_IS_TINYK22)
  {
    // initialize uart1 only if the uart is enabled
    #if (UART1_EN)
      uart1Init(baudrate);
    #endif
    term_write_line(NULL);
    term_write_line("tinyk22 ready... :-)");
  }
}

