/*
 * GPIO_Toggler.c
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#include <stdio.h>
#include "MK22F51212.h"
#include "fsl_gpio.h"
#include "GPIO_Toggler.h"
#include "pin_mux.h"
#include "Car_Joystick.h"

uint32_t states = 0;


void MaskJoystickValues(uint32_t input){
	input = ~input;
	uint32_t maskedValue = 0;
	if (input & (1 << BOARD_JOYSTICK_UP_PIN)){
		maskedValue |= JS_UP;
	}
	if (input & (1 << BOARD_JOYSTICK_RIGHT_PIN)){
		maskedValue |= JS_RIGHT;
	}
	if(input & (1 << BOARD_JOYSTICK_DOWN_PIN)){
		maskedValue |= JS_DOWN;
	}
	if(input & (1 << BOARD_JOYSTICK_LEFT_PIN)){
		maskedValue |= JS_LEFT;
	}
	if(input & (1 << BOARD_JOYSTICK_PUSH_PIN)){
		maskedValue |= JS_PUSH;
	}
	states = maskedValue;
}

uint32_t GetJoystickValues(){
	return states;
}
void ResetJoystickValues(){
	states = 0;
}

