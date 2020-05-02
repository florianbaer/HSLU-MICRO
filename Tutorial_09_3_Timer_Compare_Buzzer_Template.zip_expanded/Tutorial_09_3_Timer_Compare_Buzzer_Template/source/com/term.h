/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         terminal program
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          10.03.2020
 *
 *--------------------------------------------------------------------
 */

#ifndef SOURCES_TERM_H_
#define SOURCES_TERM_H_

typedef tError (*cmdHandler)(const char *cmd);

typedef struct commandLineHandler
{
  char cmd[16];
  char cmdDesc[32];
  cmdHandler cmdHandler;
  struct commandLineHandler *next;
} tCommandLineHandler;

void term_register_command_line_handler(tCommandLineHandler *clh, char* cmd, char *cmdDesc, cmdHandler h);

void term_write(const char *str);
void term_write_num32s(int32_t value);
void term_write_num16s(int16_t value);

void term_write_line(const char *str);
void term_write_line_format(const char *format, ...);
void term_do_work(void);
void term_init(void);

#endif /* SOURCES_TERM_H_ */
