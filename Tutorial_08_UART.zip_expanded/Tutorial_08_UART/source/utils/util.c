/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

#include <utils/util.h>
#include "MK22F51212.h"

#include "fsl_common.h"
#include "fsl_pit.h"

/**
 * @details delay at least given timeout in ns by using the
 * SDK_DelayAtLeastUs and Core clock frequency
 */
void utils_delay(const uint32_t timeout_in_ns) {
    SDK_DelayAtLeastUs(timeout_in_ns, CLOCK_GetCoreSysClkFreq());
}

/**
 * @brief configures pit with default configs, needs to be called before
 * 		  utils_pit_interrupt_config.
 */
void utils_setup_default_pit() {
	pit_config_t pitConfig;

	PIT_GetDefaultConfig(&pitConfig);

	/* Init pit module */
	PIT_Init(PIT, &pitConfig);
}

/**
 * @details Setup pit interrupt clock as a timer period by configuring the PIT on provided
 * 			channel and enabling the necessary interrupts for the specific channel and starting
 * 			the timer
 * PIT API: https://mcuxpresso.nxp.com/api_doc/dev/202/group__pit.html
 */
status_t utils_pit_interrupt_config(IRQn_Type interrupt, pit_chnl_t channel, uint32_t count) {
	/* Set timer period for channel 0 */
	PIT_SetTimerPeriod(PIT, channel, count);

	/* Enable timer interrupts for channel 0 */
	PIT_EnableInterrupts(PIT, channel, kPIT_TimerInterruptEnable);

	/* Enable at the NVIC */
	status_t status = EnableIRQ(interrupt);
	if(kStatus_Success != status) {
		return status;
	}

    /* Start channel 0 */
    PIT_StartTimer(PIT, channel);
    return status;
}
