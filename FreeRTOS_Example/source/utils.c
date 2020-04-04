/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

#include "utils.h"
#include "fsl_common.h"

/**
 * @details delay at least given timeout in ns by using the
 * SDK_DelayAtLeastUs and Core clock frequency
 */
void utils_delay(const uint32_t timeout_in_ns) {
    SDK_DelayAtLeastUs(timeout_in_ns, CLOCK_GetCoreSysClkFreq());
}
