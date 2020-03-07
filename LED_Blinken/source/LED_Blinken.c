/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    LED_Blinken.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK22F51212.h"
#include "fsl_gpio.h"

/* TODO: insert other include files here. */
#include "Delay.h"
#include "GPIO_Toggler.h"
/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_RED_RL_GPIO, BOARD_INITPINS_LED_RED_RL_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_RED_RL_GPIO, BOARD_INITPINS_LED_RED_RL_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_RED_RR_GPIO, BOARD_INITPINS_LED_RED_RR_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_RED_RR_GPIO, BOARD_INITPINS_LED_RED_RR_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_RED_FL_GPIO, BOARD_INITPINS_LED_RED_FL_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_RED_FL_GPIO, BOARD_INITPINS_LED_RED_FL_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_GREEN_FL_GPIO, BOARD_INITPINS_LED_GREEN_FL_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_GREEN_FL_GPIO, BOARD_INITPINS_LED_GREEN_FL_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_BLUE_FL_GPIO, BOARD_INITPINS_LED_RED_FL_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_BLUE_FL_GPIO, BOARD_INITPINS_LED_RED_FL_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_RED_FR_GPIO, BOARD_INITPINS_LED_RED_FR_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_RED_FR_GPIO, BOARD_INITPINS_LED_RED_FR_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_GREEN_FR_GPIO, BOARD_INITPINS_LED_GREEN_FR_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_GREEN_FR_GPIO, BOARD_INITPINS_LED_GREEN_FR_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_BLUE_FR_GPIO, BOARD_INITPINS_LED_RED_FR_PIN);
        Delay(0.5);
        GPIO_PinToggle(BOARD_INITPINS_LED_BLUE_FR_GPIO, BOARD_INITPINS_LED_RED_FR_PIN);



        // Toggle LED_A (Port A, Pin 15)
        /*state = GPIO_PinRead(BOARD_INITPINS_LED_RED_RL_GPIO, BOARD_INITPINS_LED_RED_RL_PIN) == 0;
        GPIO_PinWrite(BOARD_INITPINS_LED_RED_RL_GPIO, BOARD_INITPINS_LED_RED_RL_PIN, state);


        Delay(500000U);
        state = GPIO_PinRead(BOARD_INITPINS_LED_RED_RR_GPIO, BOARD_INITPINS_LED_RED_RR_PIN) == 0;
        GPIO_PinWrite(BOARD_INITPINS_LED_RED_RR_GPIO, BOARD_INITPINS_LED_RED_RR_PIN, state);*/


        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}
