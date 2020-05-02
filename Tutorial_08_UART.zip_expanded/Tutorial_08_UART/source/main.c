/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

/**
 * @brief   Application entry for tutorial solution.
 */
#define TUTORIAL_SOLUTION   "Tutorial 07 UART"

#include <stdio.h>

#include "platform.h"

#include "peripherals/joystick.h"
#include "peripherals/led.h"
#include "peripherals/adc.h"
#include "com/term.h"
#include "led_cmd.h"

#include <utils/util.h>

/*
 * @brief   Application entry point.
 */
int main(void) {
      /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

	termInit(19200);
	ledInit();

    // will now newly print over UART
    utils_print_tutorial(TUTORIAL_SOLUTION);

    // main application loop
    while(1) {
        termDoWork();
    }
    return 0 ;
}
