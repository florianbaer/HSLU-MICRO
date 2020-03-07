/*
 * Delay.c
 *
 *  Created on: 07.03.2020
 *      Author: hslu
 */

#include "stdint.h"
#include "fsl_common.h"
#include "fsl_clock.h"

void Delay(float timeout){
	SDK_DelayAtLeastUs((uint32_t)(timeout*1000000U), CLOCK_GetCoreSysClkFreq());
}
