/*
 * GPIO_Toggler.c
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#include "MK22F51212.h"
#include "fsl_gpio.h"


void GPIO_PinToggle(GPIO_Type *base, uint32_t pin)
{
	uint32_t state = GPIO_PinRead(base, pin) == 0;
	GPIO_PinWrite(base, pin, state);
}


void GPIO_PinOn(GPIO_Type *base, uint32_t pin)
{
	GPIO_PinWrite(base, pin, 0);
}

void GPIO_PinOnWithCounter(GPIO_Type *base, uint32_t pin, uint16_t *counter)
{
	if(GPIO_PinRead(base, pin) == 1)
	{
		GPIO_PinWrite(base, pin, 0);
		*counter += 1;
	}
}


void GPIO_PinOff(GPIO_Type *base, uint32_t pin)
{
	GPIO_PinWrite(base, pin, 1);
}
