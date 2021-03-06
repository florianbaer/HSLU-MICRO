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

void LEDTurnOn(uint32_t led, led_counter* _counter){
	switch(led){
	case CONST_LED_F_L_RED_LED:
		GPIO_PinOn(LED_LED_RED_FL_GPIO, LED_LED_RED_FL_PIN);
		break;
	case CONST_LED_F_L_GREEN_LED:
		GPIO_PinOn(LED_LED_GREEN_FL_GPIO, LED_LED_GREEN_FL_PIN);
		break;
	case CONST_LED_F_L_BLUE_LED:
		GPIO_PinOn(LED_LED_BLUE_FL_GPIO, LED_LED_BLUE_FL_PIN);
		break;
	case CONST_LED_F_R_RED_LED:
		GPIO_PinOn(LED_LED_RED_FR_GPIO, LED_LED_RED_FR_PIN);
		break;
	case CONST_LED_F_R_GREEN_LED:
		GPIO_PinOn(LED_LED_GREEN_FR_GPIO, LED_LED_GREEN_FR_PIN);
		break;
	case CONST_LED_F_R_BLUE_LED:
		GPIO_PinOn(LED_LED_BLUE_FR_GPIO, LED_LED_BLUE_FR_PIN);
		break;
	case CONST_LED_R_L_RED_LED:
		GPIO_PinOn(LED_LED_RED_RL_GPIO, LED_LED_RED_RL_PIN);
		break;
	case CONST_LED_R_R_RED_LED:
		GPIO_PinOn(LED_LED_RED_RR_GPIO, LED_LED_RED_RR_PIN);
		break;
	default:
		break;
	}
}

void LEDTurnOff(uint32_t led){
	switch(led){
		case CONST_LED_F_L_RED_LED:
			GPIO_PinOff(LED_LED_RED_FL_GPIO, LED_LED_RED_FL_PIN);
			break;
		case CONST_LED_F_L_GREEN_LED:
			GPIO_PinOff(LED_LED_GREEN_FL_GPIO, LED_LED_GREEN_FL_PIN);
			break;
		case CONST_LED_F_L_BLUE_LED:
			GPIO_PinOff(LED_LED_BLUE_FL_GPIO, LED_LED_BLUE_FL_PIN);
			break;
		case CONST_LED_F_R_RED_LED:
			GPIO_PinOff(LED_LED_RED_FR_GPIO, LED_LED_RED_FR_PIN);
			break;
		case CONST_LED_F_R_GREEN_LED:
			GPIO_PinOff(LED_LED_GREEN_FR_GPIO, LED_LED_GREEN_FR_PIN);
			break;
		case CONST_LED_F_R_BLUE_LED:
			GPIO_PinOff(LED_LED_BLUE_FR_GPIO, LED_LED_BLUE_FR_PIN);
			break;
		case CONST_LED_R_L_RED_LED:
			GPIO_PinOff(LED_LED_RED_RL_GPIO, LED_LED_RED_RL_PIN);
			break;
		case CONST_LED_R_R_RED_LED:
			GPIO_PinOff(LED_LED_RED_RR_GPIO, LED_LED_RED_RR_PIN);
			break;
		default:
			break;
	}
}

void LEDToggle(uint32_t led){
	switch(led){
		case CONST_LED_F_L_RED_LED:
			GPIO_PinToggle(LED_LED_RED_FL_GPIO, LED_LED_RED_FL_PIN);
			break;
		case CONST_LED_F_L_GREEN_LED:
			GPIO_PinToggle(LED_LED_GREEN_FL_GPIO, LED_LED_GREEN_FL_PIN);
			break;
		case CONST_LED_F_L_BLUE_LED:
			GPIO_PinToggle(LED_LED_BLUE_FL_GPIO, LED_LED_BLUE_FL_PIN);
			break;
		case CONST_LED_F_R_RED_LED:
			GPIO_PinToggle(LED_LED_RED_FR_GPIO, LED_LED_RED_FR_PIN);
			break;
		case CONST_LED_F_R_GREEN_LED:
			GPIO_PinToggle(LED_LED_GREEN_FR_GPIO, LED_LED_GREEN_FR_PIN);
			break;
		case CONST_LED_F_R_BLUE_LED:
			GPIO_PinToggle(LED_LED_BLUE_FR_GPIO, LED_LED_BLUE_FR_PIN);
			break;
		case CONST_LED_R_L_RED_LED:
			GPIO_PinToggle(LED_LED_RED_RL_GPIO, LED_LED_RED_RL_PIN);
			break;
		case CONST_LED_R_R_RED_LED:
			GPIO_PinToggle(LED_LED_RED_RR_GPIO, LED_LED_RED_RR_PIN);
			break;
		default:
			break;
		}
}

