/*
 * GPIO_Toggler.h
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#ifndef CAR_JOYSTICK_H_
#define CAR_JOYSTICK_H_

#define JS_UP		0x00000001
#define JS_RIGHT	0x00000010
#define JS_DOWN		0x00000100
#define JS_LEFT 	0x00001000
#define JS_PUSH		0x00010000

uint32_t GetJoyStickInputs();

#endif /* CAR_JOYSTICK_H_ */
