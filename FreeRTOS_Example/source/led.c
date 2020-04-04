/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

/**
 * @brief implementation of led.h
 */
#include "led.h"

#include <stdio.h>
#include <stdint.h>

#include "MK22F51212.h"
#include "pin_mux.h"
#include "fsl_gpio.h"

// contains the counts of the leds turned on
static struct {
    int32_t back_r;
    int32_t back_l;
    int32_t front_l_r;
    int32_t front_l_g;
    int32_t front_l_b;
    int32_t front_r_r;
    int32_t front_r_g;
    int32_t front_r_b;
} led_count;

/**
 * @details print the current led count of the car counted
 * by the set_led function to to console with printf
 */
void led_print_count(void) {
    printf("\r\n Show LED count:\n");
    printf("front LEDs [r|g|b]:\nleft: [%4d|%4d|%4d] right: [%4d|%4d|%4d]\n",
            led_count.front_l_r, led_count.front_l_g, led_count.front_l_b,
            led_count.front_r_r, led_count.front_r_g, led_count.front_r_b);
    printf("back LEDs:\nleft: [%4d] | right: [%4d]\n", led_count.back_l, led_count.back_r);
}

void toggle_led(const enum BOARD_CAR_LEDS_TYPE car_led, const uint8_t turn_on) {
    if(BOARD_CAR_LED_CHANGES_TO_ON(car_led, !turn_on)) {
        if(BOARD_CAR_LED_FRONT_RIGHT_RED == car_led) led_count.front_r_r++;
        if(BOARD_CAR_LED_FRONT_RIGHT_GREEN == car_led) led_count.front_r_g++;
        if(BOARD_CAR_LED_FRONT_RIGHT_BLUE == car_led) led_count.front_r_b++;

        if(BOARD_CAR_LED_FRONT_LEFT_RED == car_led) led_count.front_l_r++;
        if(BOARD_CAR_LED_FRONT_LEFT_GREEN == car_led) led_count.front_l_g++;
        if(BOARD_CAR_LED_FRONT_LEFT_BLUE == car_led) led_count.front_l_b++;

    	if(BOARD_CAR_LED_REAR_LEFT_BREAK == car_led) led_count.back_l++;
        if(BOARD_CAR_LED_REAR_RIGHT_BREAK == car_led) led_count.back_r++;
    }

    GPIO_PinWrite(
        BOARD_CAR_LEDS_GET_BASE(car_led),
        BOARD_CAR_LEDS_PIN(car_led),
        !turn_on
    );
}

/**
 * @details Using GPIO_LED_ defines to turn on / off the leds
 */
void led_toggle_front(uint8_t rgb) {
    // set front right rgb color
    toggle_led(BOARD_CAR_LED_FRONT_RIGHT_RED, rgb & 0x01);
    toggle_led(BOARD_CAR_LED_FRONT_RIGHT_GREEN, rgb & 0x02);
    toggle_led(BOARD_CAR_LED_FRONT_RIGHT_BLUE, rgb & 0x04);

    // set front left rgb color
    toggle_led(BOARD_CAR_LED_FRONT_LEFT_RED, rgb & 0x01);
    toggle_led(BOARD_CAR_LED_FRONT_LEFT_GREEN, rgb & 0x02);
    toggle_led(BOARD_CAR_LED_FRONT_LEFT_BLUE, rgb & 0x04);
}

/**
 * @details Using GPIO_LED_ defines to turn on / off the leds
 */
void led_toggle_back(uint8_t led_state_on) {
    toggle_led(BOARD_CAR_LED_REAR_LEFT_BREAK, led_state_on);
    toggle_led(BOARD_CAR_LED_REAR_LEFT_RED, led_state_on);
    toggle_led(BOARD_CAR_LED_REAR_RIGHT_BREAK, led_state_on);
    toggle_led(BOARD_CAR_LED_REAR_RIGHT_RED, led_state_on);
}
