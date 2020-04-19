/*
 * structs.c
 *
 *  Created on: 15.03.2020
 *      Author: hslu
 */

#include "structs.h"

InitalizeCounter(led_counter_t *counter){
 counter->FLR = 0;
 counter->FLG = 0;
 counter->FLB = 0;
 counter->FRR = 0;
 counter->FRG = 0;
 counter->FRB = 0;
 counter->RLR = 0;
 counter->RRR = 0;
}
