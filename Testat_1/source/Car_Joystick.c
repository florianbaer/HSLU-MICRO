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

#define JS_UP		0b00000001
#define JS_RIGHT	0b00000010
#define JS_DOWN		0b00000100
#define JS_LEFT 	0b00001000
#define JS_PUSH		0b00010000

uint32_t states = 0;

uint32_t GetJoyStickInputs(){
	uint32_t returnValue = 0;
	if (!GPIO_PinRead(JOYSTICK_JS_UP_GPIO, JOYSTICK_JS_UP_PIN)){
		returnValue |= JS_UP;
	}
	if(!GPIO_PinRead(JOYSTICK_JS_RIGHT_GPIO, JOYSTICK_JS_RIGHT_PIN)){
		returnValue |= JS_RIGHT;
	}
	if(!GPIO_PinRead(JOYSTICK_JS_DOWN_GPIO, JOYSTICK_JS_DOWN_PIN)){
		returnValue |= JS_DOWN;
	}
	if(!GPIO_PinRead(JOYSTICK_JS_LEFT_GPIO, JOYSTICK_JS_LEFT_PIN)){
		returnValue |= JS_LEFT;
	}
	if(!GPIO_PinRead(JOYSTICK_JS_PUSH_GPIO, JOYSTICK_JS_PUSH_PIN)){
		returnValue |= JS_PUSH;
	}

	return returnValue;
}

void MaskJoystickValues(uint32_t input){
	uint32_t maskedValue = 0;
	if (input & (1 << JOYSTICK_JS_UP_PIN)){
		maskedValue |= JS_UP;
	}
	if(input & (1 << JOYSTICK_JS_RIGHT_PIN)){
		maskedValue |= JS_RIGHT;
	}
	if(input & (1 << JOYSTICK_JS_DOWN_PIN)){
		maskedValue |= JS_DOWN;
	}
	if(input & (1 << JOYSTICK_JS_LEFT_PIN)){
		maskedValue |= JS_LEFT;
	}
	if(input & (1 << JOYSTICK_JS_PUSH_PIN)){
		maskedValue |= JS_PUSH;
	}
	states = maskedValue;
}

uint32_t GetJoystickValues(){
	return states;
}
uint32_t ResetJoystickValues(){
	states = 0;
}

