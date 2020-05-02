/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         Global definitions for the whole project.
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          12.03.20018
 *
 *--------------------------------------------------------------------
 */
#ifndef INCLUDES_PLATFORM_H_
#define INCLUDES_PLATFORM_H_

#include "MK22F51212.h"
#include <stdbool.h>

#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"

#include "fsl_pit.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

#define MC_CAR                            1
#define TINYK22                           2
#define AUTO                              (MC_CAR | TINYK22)
#define SOLUTION                          0

// ====================================================================================================================
// Configuration
// ====================================================================================================================
#define PLATFORM                        AUTO   // [TINYK22|MC_CAR|AUTO] select target platform
#define DEBUG_LED                          1   // [1|0] enable/disable green debug led of the MC-CAR

#define TERMINAL_BAUDRATE              57600
#define PRIO_UART0                         8  // [0..15] set interrupt priority: 0=max Prio
#define PRIO_UART1                         8  // [0..15] set interrupt priority: 0=max Prio
#define PRIO_LPUART0                       8  // [0..15] set interrupt priority: 0=max Prio
#define PRIO_FTM0                         12


// ====================================================================================================================
#define CORECLOCK                  120000000  // 120 MHZ (CPU, UART0, UART1)
#define BUSCLOCK                    60000000  // 60 MHz
#define FIXED_SYSTEM_CLOCK            250000  // 250 kHz


#define TGT_IS_MCCAR                        ((SIM->SDID & SIM_SDID_PINID_MASK) == 0x08) // 100-pin
#define TGT_IS_TINYK22                      ((SIM->SDID & SIM_SDID_PINID_MASK) == 0x05) // 64-pin

#define NULL                     ((void *)0)
#define TRUE                               1
#define FALSE                              0
//typedef char bool;


/**
 * @brief Disable External Interrupt
 *
 * The function disables a device-specific interrupt in the NVIC interrupt controller
 * and executes a DSB and ISB instruction.
 *
 * @see
 *   4.6. Disabling Interrupts using NVIC
 *   \n
 *   http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dai0321a/BIHHFHJD.html
 *   \n
 *   if it is necessary to ensure an interrupt will not be triggered after disabling it in the NVIC,
 *   add a DSB instruction and then an ISB instruction.
 */
__STATIC_INLINE void NVIC_DisableIRQEx(IRQn_Type IRQn)
{
  NVIC_DisableIRQ(IRQn);
  __asm volatile("dsb");   // data synchronization barrier
  __asm volatile("isb");   // instruction synchronization barrier
}


typedef enum
{
  EC_SUCCESS = 0,           // no error

  EC_INVALID_CMD,           // invalid or unknown command
  EC_INVALID_ARG,           // invalid or unknown argument(s)
  EC_OVERFLOW,              // overflow

} tError;


#if DEBUG_LED
#define LED_GREEN_FL_ON()                       (GPIOC->PCOR = (1<<8))   // PTC8
#define LED_GREEN_FL_OFF()                      (GPIOC->PSOR = (1<<8))
#define LED_GREEN_FR_ON()                       (GPIOC->PCOR = (1<<11))  // PTC11
#define LED_GREEN_FR_OFF()                      (GPIOC->PSOR = (1<<11))

// switch on led for debug purposes
#define OnEnterUart0RxTxISR()                   LED_GREEN_FL_ON()
#define OnEnterUart1RxTxISR()                   LED_GREEN_FL_ON()
#define OnEnterLpUart0ISR()                     LED_GREEN_FL_ON()

// switch off led for debug purposes
#define OnExitUart0RxTxISR()                    LED_GREEN_FL_OFF()
#define OnExitUart1RxTxISR()                    LED_GREEN_FL_OFF()
#define OnExitLpUart0ISR()                      LED_GREEN_FL_OFF()

__STATIC_INLINE void EnableDebugLeds(void)
{
  PORTC->PCR[8] = PORTC->PCR[11] = PORT_PCR_MUX(1);
  GPIOC->PDDR |= ((1<<8) | (1<<1));
}

#else
#define OnEnterUart0RxTxISR()
#define OnEnterUart1RxTxISR()
#define OnEnterLpUart0ISR()

#define OnExitUart0RxTxISR()
#define OnExitUart1RxTxISR()
#define OnExitLpUart0ISR()

__STATIC_INLINE void EnableDebugLeds(void) {}

#endif



#define FTM_CnSC_ELSx_MASK                       (FTM_CnSC_ELSA_MASK | FTM_CnSC_ELSB_MASK)
#define FTM_CnSC_ELSx_SHIFT                      2
#define FTM_CnSC_ELSx_WIDTH                      2
#define FTM_CnSC_ELSx(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSx_SHIFT))&FTM_CnSC_ELSx_MASK)

#define FTM_CnSC_MSx_MASK                        (FTM_CnSC_MSA_MASK | FTM_CnSC_MSB_MASK)
#define FTM_CnSC_MSx_SHIFT                       4
#define FTM_CnSC_MSx_WIDTH                       1
#define FTM_CnSC_MSx(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSx_SHIFT))&FTM_CnSC_MSx_MASK)




#endif /* INCLUDES_PLATFORM_H_ */
