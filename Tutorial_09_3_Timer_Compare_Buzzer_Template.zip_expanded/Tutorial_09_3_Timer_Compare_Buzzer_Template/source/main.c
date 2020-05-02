/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

/**
 * @brief   Application entry for tutorial solution.
 */
#define TUTORIAL_TITLE   "Tutorial 09 Timer Compare"

#include <stdio.h>

#include "platform.h"
#include "clock_config.h"
#include "peripherals.h"
#include "pin_mux.h"

#include "term.h"
#include "uart.h"

#include "ftm0.h"
#include "sound.h"
#include "sound_player.h"

#include "util.h"

/*
 * @brief   Application entry point.
 */
int main(void) {
    /* Init board hardware. */
	BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitUart0();

    // components initialisation
    term_init();
    // init FTM0
    ftm0_init();
    // initialize buzzer
    sound_init();
    // initialize player
    sound_player_init();

    // first beep
    sound_beep(4000, 100);

    // print over UART and JTag
    utils_print_tutorial(TUTORIAL_TITLE);

    // main application loop
    while(1) {
		term_do_work();
    }
    return 0 ;
}
