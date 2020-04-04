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

/**
 * Macro prints tutorial information
 */
#define utils_print_tutorial(tutorial)  (printf("Proposed solution for %s\n", tutorial))

void utils_delay(const uint32_t timeout_in_ns);

#endif /* _UTILS_H_ */
