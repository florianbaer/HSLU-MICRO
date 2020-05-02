/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

/**
 * @brief   implementation of joystick functions
 */

#include "joystick.h"

#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "MK22F51212.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "pin_mux.h"

#include "led.h"

// contains joystick states
static uint8_t state = 0;

/**
 * @details convert binary pins to custom defined joystick mapping
 */
static uint8_t joystick_map_state(const uint32_t input) {
    return ~(
        (((input >> BOARD_JOYSTICK_DOWN_PIN) & 0x01U)   << 0) |
        (((input >> BOARD_JOYSTICK_UP_PIN) & 0x01U)     << 1) |
        (((input >> BOARD_JOYSTICK_RIGHT_PIN) & 0x01U)  << 2) |
        (((input >> BOARD_JOYSTICK_LEFT_PIN) & 0x01U)   << 3) |
        (((input >> BOARD_JOYSTICK_PUSH_PIN) & 0x01U)   << 4)
    );
}

/**
 * @details Update internal state with given interrupt flags,
 * 			by adding this set bits to the state
 */
void joystick_update_interrupt(const uint32_t interrupt_flags) {
    state |= ~joystick_map_state(interrupt_flags);
}

/**
 * @details Update internal state
 */
void joystick_update() {
	state = joystick_map_state(GPIOB->PDIR);
}

/**
 * @details return internal state
 */
uint8_t joystick_get(void) {
    return state;
}

/**
 * @details resets internal state to 0
 */
void joystick_clear(void) {
    state = 0;
}

/**
 * @details check if joystick is pressed AND combine state and joystick button value
 */
uint8_t joystick_is_pressed(const uint8_t joystick_button) {
    // use xor to check for change and AND combine with new state for pressed
    return joystick_button & state;
}

/**
 * @details check if joystick is pressed AND combine state and joystick button value
 * 			after that, clear the bit.
 */
uint8_t joystick_is_pressed_and_clear(const uint8_t joystick_button) {
    if((joystick_button & state) > 0) {
        state &= ~joystick_button;
        return 1;
    } else {
        return 0;
    }
}
