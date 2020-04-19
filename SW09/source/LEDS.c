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
#include "structs.h"
#include "LEDS.h"

void LEDTurnOn(uint32_t led, led_counter_t* _counter){
	switch(led){
	case CONST_LED_F_L_RED_LED:
		GPIO_PinOnWithCounter(BOARD_LED_RED_F_L_GPIO, BOARD_LED_RED_F_L_PIN, &(_counter->FLR));
		break;
	case CONST_LED_F_L_GREEN_LED:
		GPIO_PinOnWithCounter(BOARD_LED_GREEN_F_L_GPIO, BOARD_LED_GREEN_F_L_PIN, &(_counter->FLG));
		break;
	case CONST_LED_F_L_BLUE_LED:
		GPIO_PinOnWithCounter(BOARD_LED_BLUE_F_L_GPIO, BOARD_LED_BLUE_F_L_PIN, &(_counter->FLB));
		break;
	case CONST_LED_F_R_RED_LED:
		GPIO_PinOnWithCounter(BOARD_LED_RED_F_R_GPIO, BOARD_LED_RED_F_R_PIN, &(_counter->FRR));
		break;
	case CONST_LED_F_R_GREEN_LED:
		GPIO_PinOnWithCounter(BOARD_LED_GREEN_F_R_GPIO, BOARD_LED_GREEN_F_R_PIN, &(_counter->FRG));
		break;
	case CONST_LED_F_R_BLUE_LED:
		GPIO_PinOnWithCounter(BOARD_LED_BLUE_F_R_GPIO, BOARD_LED_BLUE_F_R_PIN, &(_counter->FRB));
		break;
	case CONST_LED_R_L_RED_LED:
		GPIO_PinOnWithCounter(BOARD_LED_RED_R_L_GPIO, BOARD_LED_RED_R_L_PIN, &(_counter->RLR));
		break;
	case CONST_LED_R_R_RED_LED:
		GPIO_PinOnWithCounter(BOARD_LED_RED_R_R_GPIO, BOARD_LED_RED_R_R_PIN, &(_counter->RRR));
		break;
	default:
		break;
	}
}

void LEDTurnOff(uint32_t led){
	switch(led){
		case CONST_LED_F_L_RED_LED:
			GPIO_PinOff(BOARD_LED_RED_F_L_GPIO, BOARD_LED_RED_F_L_PIN);
			break;
		case CONST_LED_F_L_GREEN_LED:
			GPIO_PinOff(BOARD_LED_GREEN_F_L_GPIO, BOARD_LED_GREEN_F_L_PIN);
			break;
		case CONST_LED_F_L_BLUE_LED:
			GPIO_PinOff(BOARD_LED_BLUE_F_L_GPIO, BOARD_LED_BLUE_F_L_PIN);
			break;
		case CONST_LED_F_R_RED_LED:
			GPIO_PinOff(BOARD_LED_RED_F_R_GPIO, BOARD_LED_RED_F_R_PIN);
			break;
		case CONST_LED_F_R_GREEN_LED:
			GPIO_PinOff(BOARD_LED_GREEN_F_R_GPIO, BOARD_LED_GREEN_F_R_PIN);
			break;
		case CONST_LED_F_R_BLUE_LED:
			GPIO_PinOff(BOARD_LED_BLUE_F_R_GPIO, BOARD_LED_BLUE_F_R_PIN);
			break;
		case CONST_LED_R_L_RED_LED:
			GPIO_PinOff(BOARD_LED_RED_R_L_GPIO, BOARD_LED_RED_R_L_PIN);
			break;
		case CONST_LED_R_R_RED_LED:
			GPIO_PinOff(BOARD_LED_RED_R_R_GPIO, BOARD_LED_RED_R_R_PIN);
			break;
		default:
			break;
	}
}

void LEDToggle(uint32_t led){
	switch(led){
		case CONST_LED_F_L_RED_LED:
			GPIO_PinToggle(BOARD_LED_RED_F_L_GPIO, BOARD_LED_RED_F_L_PIN);
			break;
		case CONST_LED_F_L_GREEN_LED:
			GPIO_PinToggle(BOARD_LED_GREEN_F_L_GPIO, BOARD_LED_GREEN_F_L_PIN);
			break;
		case CONST_LED_F_L_BLUE_LED:
			GPIO_PinToggle(BOARD_LED_BLUE_F_L_GPIO, BOARD_LED_BLUE_F_L_PIN);
			break;
		case CONST_LED_F_R_RED_LED:
			GPIO_PinToggle(BOARD_LED_RED_F_R_GPIO, BOARD_LED_RED_F_R_PIN);
			break;
		case CONST_LED_F_R_GREEN_LED:
			GPIO_PinToggle(BOARD_LED_GREEN_F_R_GPIO, BOARD_LED_GREEN_F_R_PIN);
			break;
		case CONST_LED_F_R_BLUE_LED:
			GPIO_PinToggle(BOARD_LED_BLUE_F_R_GPIO, BOARD_LED_BLUE_F_R_PIN);
			break;
		case CONST_LED_R_L_RED_LED:
			GPIO_PinToggle(BOARD_LED_RED_R_L_BREAK_GPIO, BOARD_LED_RED_R_L_BREAK_PIN);
			break;
		case CONST_LED_R_R_RED_LED:
			GPIO_PinToggle(BOARD_LED_RED_R_R_BREAK_GPIO, BOARD_LED_RED_R_R_BREAK_PIN);
			break;
		default:
			break;
		}
}

