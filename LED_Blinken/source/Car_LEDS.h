/*
 * GPIO_Toggler.h
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#ifndef CAR_LEDS_H_
#define CAR_LEDS_H_


void TurnOnFrontLEDs(led_counter*);
void TurnOnRearLEDs(led_counter*);
void GoToNextLEDColorLeft(led_counter*);
void GoToNextLEDColorRight(led_counter*);
void TurnOffAllLEDs();

#endif /* CAR_LEDS_H_ */
