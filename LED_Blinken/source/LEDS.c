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

#define CONST_LED_F_L_RED_LED 0
#define CONST_LED_F_L_GREEN_LED 1
#define CONST_LED_F_L_BLUE_LED 2
#define CONST_LED_F_R_RED_LED 3
#define CONST_LED_F_R_GREEN_LED 4
#define CONST_LED_F_R_BLUE_LED 5
#define CONST_LED_R_L_RED_LED 6
#define CONST_LED_R_R_RED_LED 7

void LEDTurnOn(uint32_t led){
	switch(led){
	case CONST_LED_F_L_RED_LED:
		GPIO_PinOn(BOARD_INITPINS_LED_RED_FL_GPIO, BOARD_INITPINS_LED_RED_FL_PIN);
		break;
	case CONST_LED_F_L_GREEN_LED:
		GPIO_PinOn(BOARD_INITPINS_LED_GREEN_FL_GPIO, BOARD_INITPINS_LED_GREEN_FL_PIN);
		break;
	case CONST_LED_F_L_BLUE_LED:
		GPIO_PinOn(BOARD_INITPINS_LED_BLUE_FL_GPIO, BOARD_INITPINS_LED_BLUE_FL_PIN);
		break;
	case CONST_LED_F_R_RED_LED:
		GPIO_PinOn(BOARD_INITPINS_LED_RED_FR_GPIO, BOARD_INITPINS_LED_RED_FR_PIN);
		break;
	case CONST_LED_F_R_GREEN_LED:
		GPIO_PinOn(BOARD_INITPINS_LED_GREEN_FR_GPIO, BOARD_INITPINS_LED_GREEN_FR_PIN);
		break;
	case CONST_LED_F_R_BLUE_LED:
		GPIO_PinOn(BOARD_INITPINS_LED_BLUE_FR_GPIO, BOARD_INITPINS_LED_BLUE_FR_PIN);
		break;
	case CONST_LED_R_L_RED_LED:
		GPIO_PinOn(BOARD_INITPINS_LED_RED_RL_GPIO, BOARD_INITPINS_LED_RED_RL_PIN);
		break;
	case CONST_LED_R_R_RED_LED:
		GPIO_PinOn(BOARD_INITPINS_LED_RED_RR_GPIO, BOARD_INITPINS_LED_RED_RR_PIN);
		break;
	default:
		break;
	}
}

void LEDTurnOff(uint32_t led){
	switch(led){
		case CONST_LED_F_L_RED_LED:
			GPIO_PinOff(BOARD_INITPINS_LED_RED_FL_GPIO, BOARD_INITPINS_LED_RED_FL_PIN);
			break;
		case CONST_LED_F_L_GREEN_LED:
			GPIO_PinOff(BOARD_INITPINS_LED_GREEN_FL_GPIO, BOARD_INITPINS_LED_GREEN_FL_PIN);
			break;
		case CONST_LED_F_L_BLUE_LED:
			GPIO_PinOff(BOARD_INITPINS_LED_BLUE_FL_GPIO, BOARD_INITPINS_LED_BLUE_FL_PIN);
			break;
		case CONST_LED_F_R_RED_LED:
			GPIO_PinOff(BOARD_INITPINS_LED_RED_FR_GPIO, BOARD_INITPINS_LED_RED_FR_PIN);
			break;
		case CONST_LED_F_R_GREEN_LED:
			GPIO_PinOff(BOARD_INITPINS_LED_GREEN_FR_GPIO, BOARD_INITPINS_LED_GREEN_FR_PIN);
			break;
		case CONST_LED_F_R_BLUE_LED:
			GPIO_PinOff(BOARD_INITPINS_LED_BLUE_FR_GPIO, BOARD_INITPINS_LED_BLUE_FR_PIN);
			break;
		case CONST_LED_R_L_RED_LED:
			GPIO_PinOff(BOARD_INITPINS_LED_RED_RL_GPIO, BOARD_INITPINS_LED_RED_RL_PIN);
			break;
		case CONST_LED_R_R_RED_LED:
			GPIO_PinOff(BOARD_INITPINS_LED_RED_RR_GPIO, BOARD_INITPINS_LED_RED_RR_PIN);
			break;
		default:
			break;
	}
}

void LEDToggle(uint32_t led){
	switch(led){
		case CONST_LED_F_L_RED_LED:
			GPIO_PinToggle(BOARD_INITPINS_LED_RED_FL_GPIO, BOARD_INITPINS_LED_RED_FL_PIN);
			break;
		case CONST_LED_F_L_GREEN_LED:
			GPIO_PinToggle(BOARD_INITPINS_LED_GREEN_FL_GPIO, BOARD_INITPINS_LED_GREEN_FL_PIN);
			break;
		case CONST_LED_F_L_BLUE_LED:
			GPIO_PinToggle(BOARD_INITPINS_LED_BLUE_FL_GPIO, BOARD_INITPINS_LED_BLUE_FL_PIN);
			break;
		case CONST_LED_F_R_RED_LED:
			GPIO_PinToggle(BOARD_INITPINS_LED_RED_FR_GPIO, BOARD_INITPINS_LED_RED_FR_PIN);
			break;
		case CONST_LED_F_R_GREEN_LED:
			GPIO_PinToggle(BOARD_INITPINS_LED_GREEN_FR_GPIO, BOARD_INITPINS_LED_GREEN_FR_PIN);
			break;
		case CONST_LED_F_R_BLUE_LED:
			GPIO_PinToggle(BOARD_INITPINS_LED_BLUE_FR_GPIO, BOARD_INITPINS_LED_BLUE_FR_PIN);
			break;
		case CONST_LED_R_L_RED_LED:
			GPIO_PinToggle(BOARD_INITPINS_LED_RED_RL_GPIO, BOARD_INITPINS_LED_RED_RL_PIN);
			break;
		case CONST_LED_R_R_RED_LED:
			GPIO_PinToggle(BOARD_INITPINS_LED_RED_RR_GPIO, BOARD_INITPINS_LED_RED_RR_PIN);
			break;
		default:
			break;
		}
}

