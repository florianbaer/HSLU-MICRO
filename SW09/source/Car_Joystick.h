/*
 * GPIO_Toggler.h
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#ifndef CAR_JOYSTICK_H_
#define CAR_JOYSTICK_H_

#define JS_UP		0b00000001
#define JS_RIGHT	0b00000010
#define JS_DOWN		0b00000100
#define JS_LEFT 	0b00001000
#define JS_PUSH		0b00010000

void ResetJoystickValues();
uint32_t GetJoystickValues();
uint32_t GetJoyStickInputs();
void MaskJoystickValues();

#endif /* CAR_JOYSTICK_H_ */
