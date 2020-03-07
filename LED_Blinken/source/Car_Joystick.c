/*
 * GPIO_Toggler.c
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#include "MK22F51212.h"
#include "fsl_gpio.h"
#include "GPIO_Toggler.h"
#include "pin_mux.h"

#define JS_UP		0x00000001
#define JS_RIGHT	0x00000010
#define JS_DOWN		0x00000100
#define JS_LEFT 	0x00001000
#define JS_PUSH		0x00010000

unsigned char GetJoyStickInputs(){
	unsigned char returnValue = 0;
	if(GPIO_PinRead(BOARD_INITPINS_JS_UP_GPIO, BOARD_INITPINS_JS_DOWN_PIN) == 0){
		returnValue |= JS_UP;
	}
	if(GPIO_PinRead(BOARD_INITPINS_JS_RIGHT_GPIO, BOARD_INITPINS_JS_RIGHT_PIN) == 0){
		returnValue |= JS_RIGHT;
	}
	if(GPIO_PinRead(BOARD_INITPINS_JS_DOWN_GPIO, BOARD_INITPINS_JS_DOWN_PIN) == 0){
		returnValue |= JS_DOWN;
	}
	if(GPIO_PinRead(BOARD_INITPINS_JS_LEFT_GPIO, BOARD_INITPINS_JS_LEFT_PIN) == 0){
		returnValue |= JS_LEFT;
	}
	if(GPIO_PinRead(BOARD_INITPINS_JS_PUSH_GPIO, BOARD_INITPINS_JS_PUSH_PIN) == 0){
		returnValue |= JS_PUSH;
	}

	return returnValue;
}

