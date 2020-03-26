/*
 * GPIO_Toggler.h
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "structs.h"


#define CONST_LED_F_L_RED_LED 0
#define CONST_LED_F_L_GREEN_LED 1
#define CONST_LED_F_L_BLUE_LED 2
#define CONST_LED_F_R_RED_LED 3
#define CONST_LED_F_R_GREEN_LED 4
#define CONST_LED_F_R_BLUE_LED 5
#define CONST_LED_R_L_RED_LED 6
#define CONST_LED_R_R_RED_LED 7

void LEDTurnOn(uint32_t led, led_counter* _counter);
void LEDTurnOff(uint32_t led);
void LEDToggle(uint32_t led);

#endif /* LEDS_H_ */
