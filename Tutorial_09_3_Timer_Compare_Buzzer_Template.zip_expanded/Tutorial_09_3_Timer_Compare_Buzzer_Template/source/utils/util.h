/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

/**
 * @brief Utility functions for Cortex-M Microcontroller - NXP.
 */
#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdint.h>

#include "platform.h"

#include "mc_util.h"

#include "fsl_pit.h"

#include "com/term.h"

#ifdef _SOLUTION
#define INFO_FORMAT "Proposed solution for %s\n"
#else
#define INFO_FORMAT "Template for %s\n"
#endif

/**
 * Macro prints tutorial information
 */
#define utils_print_tutorial(tutorial)  { \
	term_write_line_format(INFO_FORMAT, tutorial); \
	printf(INFO_FORMAT, tutorial); \
}

void utils_delay(const uint32_t timeout_in_ns);

/**
 * @brief configures pit with default configs, needs to be called before
 * 		  utils_pit_interrupt_config.
 */
void utils_setup_default_pit();

/**
 * @brief Setup and start pit interrupt clock on channel with a given interval,
 * 		  pit needs to be configured before (check utils_setup_default_pit())
 * @param interrupt The IRQ number.
 * @param channel Timer channel number
 * @param count   Timer period in units of ticks
 * @retval kStatus_Success Interrupt enabled successfully
 * @retval kStatus_Fail Failed to enable the interrupt
 */
status_t utils_pit_interrupt_config(IRQn_Type interrupt, pit_chnl_t channel, uint32_t count);

#endif /* _UTILS_H_ */
