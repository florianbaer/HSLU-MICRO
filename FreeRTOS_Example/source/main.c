/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */
 
/**
 * @brief   Application entry for Amazon FreeRTOS.
 */
#define EXAMPLE_DESCRIPTION   "FreeRTOS Example"
#define TASK_STACK_SIZE 	  300

#include <stdio.h>
#include "peripherals.h"
#include "clock_config.h"
#include "MK22F51212.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

#include "utils.h"
#include "joystick.h"
#include "led.h"

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

/**
 * Handle Joystick interrupt by handling
 * PortB Interrupts
 */
void PORTB_IRQHandler(void) {
	static BaseType_t pxHigherPriorityTaskWoken;
	// clear interrupt flags
	PORT_ClearPinsInterruptFlags(PORTB, 0xFFFF);

	// update internal joystick state
	joysick_update();

	// prevent switch bounce effect by adding a timeout
	TickType_t currentClock = xTaskGetTickCount();
	if(lastInterruptReceived + pdMS_TO_TICKS(INTERRUPT_PUSH_TIMEOUT_IN_MS)< currentClock) {
		lastInterruptReceived = currentClock;

		// increment semaphore
		pxHigherPriorityTaskWoken = pdFALSE;
		if(joystickTaskHandle != NULL) {
			vTaskNotifyGiveFromISR(joystickTaskHandle, &pxHigherPriorityTaskWoken);
			portYIELD_FROM_ISR(pxHigherPriorityTaskWoken);
		}
	}
}

/**
 * Task notified by joystick interrupt
 */
static void app_joystick_pressed_task(void *pv) {
	uint32_t ulNotifiedValue;
	for(;;) {
		ulNotifiedValue = ulTaskNotifyTake(pdFALSE, portMAX_DELAY);

		if(ulNotifiedValue > 0) {  // Not timed out
			if(joystick_is_pressed(JOYSTICK_PUSH)) {
				LED_TOGGLE(BOARD_CAR_LED_FRONT_RIGHT_GREEN);
			}
			joystick_clear();
			joystickCounter++;
		}
	} /* for */
}

/**
 * App print task, which prints out counter value
 */
static void app_print_counter_task(void *pv) {
	for(;;) {
		vTaskDelay(pdMS_TO_TICKS(5000));

		printf("counted Joystick clicks: %d\n", joystickCounter);
	} /* for */
}

/**
 * Timer callback, which will blink the led
 */
static void ledToggleTimerCallback(TimerHandle_t timer) {
	  LED_TOGGLE(BOARD_CAR_LED_FRONT_LEFT_RED);
}


/*
 * @brief   Application entry point.
 */
int main(void) {
  	/* Init board hardware. */
	BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

	// set priority of interrupt to be higher then configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY
	// this is defined by FreeRTOS (https://www.freertos.org/RTOS-Cortex-M3-M4.html)
	NVIC_SetPriority(PORTB_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);
    // enable interrupt for PortB, on which the Joystick GPIO is located
    EnableIRQ(PORTB_IRQn);

	utils_print_tutorial(EXAMPLE_DESCRIPTION);

	xTaskCreate(app_joystick_pressed_task,
		        "JoystickTask",
				TASK_STACK_SIZE,
				NULL,
				tskIDLE_PRIORITY + 2,			//< higher priority then print task
				&joystickTaskHandle);

	TaskHandle_t printTaskHandle;
	xTaskCreate(app_print_counter_task,
			"PrintCounterTask",
			TASK_STACK_SIZE,
			NULL,
			tskIDLE_PRIORITY,
			&printTaskHandle);

	TimerHandle_t timerHandle = xTimerCreate("Timer",
			                                 pdMS_TO_TICKS(500), // Period in ticks (500ms)
											 pdTRUE, // Repeating
											 ( void * ) 0, // Timer Id
											 ledToggleTimerCallback);
	xTimerStart(timerHandle, 0);

	// start scheduler, this will start the tasks and timers and will never return
	vTaskStartScheduler();

    return 0 ;
}
