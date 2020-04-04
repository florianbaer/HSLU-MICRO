/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

/**
 * @brief   Application entry point.
 */

#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#include <stdint.h>

// possible joystick inputs
#define JOYSTICK_DOWN 	1 << 0
#define JOYSTICK_UP 	1 << 1
#define JOYSTICK_RIGHT 	1 << 2
#define JOYSTICK_LEFT 	1 << 3
#define JOYSTICK_PUSH 	1 << 4

/**
 * @brief Update current joystick state by reading appropriate registers.
 */
void joysick_update();

/**
 * @brief Return current state of joystick
 * @return joystick state as:
 *      bit   | 7 | 6 | 5 | 4       | 3    | 2     | 1  | 0    |
 *      value | x | x | x |[PRESSED]|[LEFT]|[RIGHT]|[UP]|[DOWN]|
 */
uint8_t joystick_get(void);

/**
 * @brief check if joystick is has been pressed
 * @param joystick_button one of the possible joystick inputs
 * @return true if joystick input has been pressed
 */
uint8_t joystick_is_pressed(uint8_t joystick_button);

/**
 * @brief check if joystick is has been pressed and clear given button value
 * @param joystick_button one of the possible joystick inputs
 * @return true if joystick input has been pressed
 */
uint8_t joystick_is_pressed_and_clear(uint8_t joystick_button);

/**
 * @brief clear internal joystick state, useful to cleanup after checking state.
 * 		  Interrupt will only set the received joystick input, it should therefore
 * 		  be used like an interrupt flag and the internal state should be cleared.
 */
void joystick_clear(void);

#endif /* _JOYSTICK_H_ */
