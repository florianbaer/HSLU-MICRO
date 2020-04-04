/*
 * GPIO_Toggler.h
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#ifndef GPIO_TOGGLER_H_
#define GPIO_TOGGLER_H_

void GPIO_PinToggle(GPIO_Type *base, uint32_t pin);
void GPIO_PinOnWithCounter(GPIO_Type *base, uint32_t pin, uint16_t *counter);
void GPIO_PinOn(GPIO_Type *base, uint32_t pin);
void GPIO_PinOff(GPIO_Type *base, uint32_t pin);

#endif /* GPIO_TOGGLER_H_ */
