/*
 * GPIO_Toggler.c
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#include <structs.h>
#include "MK22F51212.h"
#include "pin_mux.h"
#include "LEDS.h"
#include "structs.h"

uint32_t right_color_mode = 0;
uint32_t left_color_mode = 0;

void TurnOnFrontLEDs(led_counter_t* _counter){
	LEDTurnOn(CONST_LED_F_L_RED_LED, _counter);
	LEDTurnOn(CONST_LED_F_R_RED_LED, _counter);
}

void TurnOnRearLEDs(led_counter_t* _counter){
	LEDTurnOn(CONST_LED_R_L_RED_LED, _counter);
	LEDTurnOn(CONST_LED_R_R_RED_LED, _counter);
}

void GoToNextLEDColorLeft(led_counter_t* _counter){
	left_color_mode += 1;
	left_color_mode %= 5;
	switch(left_color_mode){
		case 0:
			LEDTurnOff(CONST_LED_F_L_GREEN_LED);
			LEDTurnOff(CONST_LED_F_L_BLUE_LED);
			LEDTurnOn(CONST_LED_F_L_RED_LED, _counter);
			break;
		case 1:
			LEDTurnOff(CONST_LED_F_L_RED_LED);
			LEDTurnOn(CONST_LED_F_L_GREEN_LED, _counter);
			break;
		case 2:
			LEDTurnOff(CONST_LED_F_L_GREEN_LED);
			LEDTurnOn(CONST_LED_F_L_BLUE_LED, _counter);
			break;
		case 3:
			LEDTurnOff(CONST_LED_F_L_BLUE_LED);
			LEDTurnOn(CONST_LED_F_L_RED_LED, _counter);
			LEDTurnOn(CONST_LED_F_L_GREEN_LED, _counter);
			break;
		case 4:
			LEDTurnOff(CONST_LED_F_L_GREEN_LED);
			LEDTurnOn(CONST_LED_F_L_BLUE_LED, _counter);
			break;
		default:
			break;
	}
}

void GoToNextLEDColorRight(led_counter_t* _counter){
	right_color_mode += 1;
	right_color_mode %= 5;
	switch(right_color_mode){
		case 0:
			LEDTurnOff(CONST_LED_F_R_GREEN_LED);
			LEDTurnOff(CONST_LED_F_R_BLUE_LED);
			LEDTurnOn(CONST_LED_F_R_RED_LED, _counter);
			break;
		case 1:
			LEDTurnOff(CONST_LED_F_R_RED_LED);
			LEDTurnOn(CONST_LED_F_R_GREEN_LED, _counter);
			break;
		case 2:
			LEDTurnOff(CONST_LED_F_R_GREEN_LED);
			LEDTurnOn(CONST_LED_F_R_BLUE_LED, _counter);
			break;
		case 3:
			LEDTurnOff(CONST_LED_F_R_BLUE_LED);
			LEDTurnOn(CONST_LED_F_R_RED_LED, _counter);
			LEDTurnOn(CONST_LED_F_R_GREEN_LED, _counter);
			break;
		case 4:
			LEDTurnOff(CONST_LED_F_R_GREEN_LED);
			LEDTurnOn(CONST_LED_F_R_BLUE_LED, _counter);
			break;
		default:
			break;
	}
}

void TurnOffAllLEDs(){
	LEDTurnOff(CONST_LED_F_L_RED_LED);
	LEDTurnOff(CONST_LED_F_R_RED_LED);
	LEDTurnOff(CONST_LED_F_L_GREEN_LED);
	LEDTurnOff(CONST_LED_F_R_GREEN_LED);
	LEDTurnOff(CONST_LED_F_L_BLUE_LED);
	LEDTurnOff(CONST_LED_F_R_BLUE_LED);
	LEDTurnOff(CONST_LED_R_L_RED_LED);
	LEDTurnOff(CONST_LED_R_R_RED_LED);

	right_color_mode = 0;
	left_color_mode = 0;
}

