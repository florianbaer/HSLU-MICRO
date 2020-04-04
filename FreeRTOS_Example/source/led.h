/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

/**
 * @brief contains functions to manage car leds
 */
#ifndef _LED_H_
#define _LED_H_

#include <stdint.h>

#include "MK22F51212.h"

#include "pin_mux.h"
#include "fsl_gpio.h"

// Create BOARD_CAR_LEDS_TYPE by base and pin of led
#define LED_DEFINE(base, pin) ((UINT64_C(base) << 32) | UINT64_C(pin))

// Get GPIO_Type from BOARD_CAR_LEDS_TYPE
#define BOARD_CAR_LEDS_GET_BASE(led_type) ((GPIO_Type*)(uint32_t)(led_type >> 32))

// Get GPIO_Type from BOARD_CAR_LEDS_TYPE
#define BOARD_CAR_LEDS_PIN(led_type) (((uint32_t)led_type))

/*
 * Compare current led value with new value, if current output
 * is 1 and new value is 0, it is detected as change of turning
 * on the led. Returns a 1 for true and 0 for false.
 */
#define BOARD_CAR_LED_CHANGES_TO_ON(led_type, new_value) (GPIO_PinRead(BOARD_CAR_LEDS_GET_BASE(led_type), BOARD_CAR_LEDS_PIN(led_type)) && !new_value)

/**
 * Write the value to the led
 */
#define LED_WRITE(car_led, turn_on) \
	GPIO_PinWrite( \
		BOARD_CAR_LEDS_GET_BASE(car_led), \
		BOARD_CAR_LEDS_PIN(car_led), \
		!turn_on \
	)

/**
 * read the current value of the led
 */
#define LED_READ(car_led) \
	!GPIO_PinRead( \
		BOARD_CAR_LEDS_GET_BASE(car_led), \
		BOARD_CAR_LEDS_PIN(car_led) \
	)

/**
 * Toggle the given led
 */
#define LED_TOGGLE(car_led) \
	LED_WRITE( \
		car_led, !LED_READ(car_led) \
	)

#define LED_OFF	0
#define LED_ON 	1

enum BOARD_CAR_LEDS_TYPE {
    // front left
    BOARD_CAR_LED_FRONT_LEFT_RED = LED_DEFINE(BOARD_LED_RED_F_L_GPIO, BOARD_LED_RED_F_L_PIN),
    BOARD_CAR_LED_FRONT_LEFT_GREEN = LED_DEFINE(BOARD_LED_GREEN_F_L_GPIO, BOARD_LED_GREEN_F_L_PIN),
    BOARD_CAR_LED_FRONT_LEFT_BLUE = LED_DEFINE(BOARD_LED_BLUE_F_L_GPIO, BOARD_LED_BLUE_F_L_PIN),

    // front right
    BOARD_CAR_LED_FRONT_RIGHT_RED = LED_DEFINE(BOARD_LED_RED_F_R_GPIO, BOARD_LED_RED_F_R_PIN),
    BOARD_CAR_LED_FRONT_RIGHT_GREEN = LED_DEFINE(BOARD_LED_GREEN_F_R_GPIO, BOARD_LED_GREEN_F_R_PIN),
    BOARD_CAR_LED_FRONT_RIGHT_BLUE = LED_DEFINE(BOARD_LED_BLUE_F_R_GPIO, BOARD_LED_BLUE_F_R_PIN),

    // front rear left
    BOARD_CAR_LED_REAR_LEFT_BREAK = LED_DEFINE(BOARD_LED_RED_R_L_BREAK_GPIO, BOARD_LED_RED_R_L_BREAK_PIN),
    BOARD_CAR_LED_REAR_LEFT_RED = LED_DEFINE(BOARD_LED_RED_R_L_GPIO, BOARD_LED_RED_R_L_PIN),

    // front rear right
    BOARD_CAR_LED_REAR_RIGHT_BREAK = LED_DEFINE(BOARD_LED_RED_R_R_BREAK_GPIO, BOARD_LED_RED_R_R_BREAK_PIN),
    BOARD_CAR_LED_REAR_RIGHT_RED = LED_DEFINE(BOARD_LED_RED_R_R_GPIO, BOARD_LED_RED_R_R_PIN)
};

/**
 * Toggle an LED to the given state
 * @param car_led the location of the car LED (BOARD_CAR_LEDS_TYPE)
 * @param turn_on 1 = turn on led / 0 = turn off
 */
void toggle_led(const enum BOARD_CAR_LEDS_TYPE car_led, const uint8_t turn_on);

/**
 * @brief print current count of leds
 */
void led_print_count(void);

/**
 * @brief set front led
 * @param rgb |R|G|B| = if 0 = leds off
 */
void led_toggle_front(uint8_t rgb);

/**
 * @brief set back led
 * @param led_state_off 0 = on / 1 = off
 */
void led_toggle_back(uint8_t led_state_off);

#endif /* _LED_H_ */
