/*
 * GPIO_Toggler.h
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#ifndef CAR_LEDS_H_
#define CAR_LEDS_H_
#include "structs.h"

void TurnOnFrontLEDs(led_counter_t*);
void TurnOnRearLEDs(led_counter_t*);
void GoToNextLEDColorLeft(led_counter_t*);
void GoToNextLEDColorRight(led_counter_t*);
void TurnOffAllLEDs();

#endif /* CAR_LEDS_H_ */
