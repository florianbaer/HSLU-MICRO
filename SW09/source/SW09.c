/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Florian Bär
 */

/**
 * @brief   Application entry for Amazon FreeRTOS.
 */
#define EXAMPLE_DESCRIPTION   "FreeRTOS Example"
#define TASK_STACK_SIZE 	  300
#define ADC_CH_POWER	  	   19
#define ADC_CH_TEMPERATURE	   26

#include <stdio.h>
#include "peripherals.h"
#include "clock_config.h"
#include "MK22F51212.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

#include "Car_Joystick.h"
#include "Car_LEDS.h"
#include "structs.h"

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

volatile static uint8_t joystickCounter = 0;
TaskHandle_t joystickTaskHandle = NULL;

// For PORTB ISR
// defines timeout of interrupt received, ignoring interrupt happening in given time frame
#define INTERRUPT_PUSH_TIMEOUT_IN_MS	130
// last interrupt received, used for bouncy prevention
static TickType_t lastInterruptReceived;

led_counter_t counter;

static void Toggle_Lights(uint32_t input) {
	if ((input & JS_UP) > 0) {
		TurnOnFrontLEDs(&counter);
	}

	if ((input & JS_DOWN) > 0) {
		TurnOnRearLEDs(&counter);
	}

	if ((input & JS_RIGHT) > 0) {
		GoToNextLEDColorRight(&counter);
	}

	if ((input & JS_LEFT) > 0) {
		GoToNextLEDColorLeft(&counter);
	}

	if ((input & JS_PUSH) > 0) {
		TurnOffAllLEDs(&counter);
	}
}

/**
 * Handle Joystick interrupt by handling
 * PortB Interrupts
 */
void PORTB_IRQHandler(void) {
	static BaseType_t pxHigherPriorityTaskWoken;

	// clear interrupt flags
	PORT_ClearPinsInterruptFlags(PORTB, 0xFFFF);

	MaskJoystickValues(GPIOB->PDIR);

	// prevent switch bounce effect by adding a timeout
	TickType_t currentClock = xTaskGetTickCount();
	if (lastInterruptReceived + pdMS_TO_TICKS(INTERRUPT_PUSH_TIMEOUT_IN_MS)
			< currentClock) {
		lastInterruptReceived = currentClock;

		// increment semaphore
		pxHigherPriorityTaskWoken = pdFALSE;
		if (joystickTaskHandle != NULL) {
			vTaskNotifyGiveFromISR(joystickTaskHandle,
					&pxHigherPriorityTaskWoken);
			portYIELD_FROM_ISR(pxHigherPriorityTaskWoken);
		}
	}
}

/**
 * Task notified by joystick interrupt
 */
static void app_joystick_pressed_task(void *pv) {
	uint32_t ulNotifiedValue;
	for (;;) {
		ulNotifiedValue = ulTaskNotifyTake(pdFALSE, portMAX_DELAY);

		//printf("Pressed: %d \n", values);
		if (ulNotifiedValue > 0) {  // Not timed out

			uint32_t values = GetJoystickValues();
			Toggle_Lights(values);

			ResetJoystickValues();
		}
	} /* for */
}

/**
 * App print task, which prints out counter value
 */
static void app_print_counter_task(void *pv) {
	for (;;) {
		//printf("works here");
		vTaskDelay(pdMS_TO_TICKS(5000));
		ADC1->SC1[0] = ADC_CH_POWER; // Temperature
		// wait until conversion has been finished
		while (!(ADC1->SC1[0] & ADC_SC1_COCO_MASK)) {
		}
		uint32_t adcvalue = ADC1->R[0];
		uint32_t voltage = adcvalue * 3300000 / 65535;
		uint32_t power = voltage * 68 / 100000 - 15;
		uint32_t tens = voltage * 37 / 10000;
		uint32_t temp = 250 - ((voltage - 716000) / 162);
		printf("-----------------------\n");
		printf("Measured Power was %d mA\n", power);
		printf("Measured Temp was %d mA\n", temp);
		printf("-----------------------\n");
		printf("FLR: %d\n", counter.FLR);
		printf("FLG: %d\n", counter.FLG);
		printf("FLB: %d\n", counter.FLB);
		printf("-----------------------\n");
		printf("FRR: %d\n", counter.FRR);
		printf("FRG: %d\n", counter.FRG);
		printf("FRB: %d\n", counter.FRB);
		printf("-----------------------\n");
		printf("RRR: %d\n", counter.RRR);
		printf("RLR: %d\n", counter.RLR);
		printf("-----------------------\n");
	} /* for */
}

/*
 * @brief   Application entry point.
 */
int main(void) {
	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();

	InitalizeCounter(&counter);

	TurnOffAllLEDs(counter);

	// set priority of interrupt to be higher then configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY
	// this is defined by FreeRTOS (https://www.freertos.org/RTOS-Cortex-M3-M4.html)

	NVIC_SetPriority(PORTB_IRQn,
			configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);
	// enable interrupt for PortB, on which the Joystick GPIO is located
	EnableIRQ(PORTB_IRQn);

	//utils_print_tutorial(EXAMPLE_DESCRIPTION);

	xTaskCreate(app_joystick_pressed_task, "JoystickTask",
	TASK_STACK_SIZE,
	NULL,
	tskIDLE_PRIORITY + 1, &joystickTaskHandle);

	TaskHandle_t printTaskHandle;
	xTaskCreate(app_print_counter_task, "PrintCounterTask",
	TASK_STACK_SIZE,
	NULL,
	tskIDLE_PRIORITY, &printTaskHandle);

	// start scheduler, this will start the tasks and timers and will never return
	vTaskStartScheduler();

	return 0;
}
