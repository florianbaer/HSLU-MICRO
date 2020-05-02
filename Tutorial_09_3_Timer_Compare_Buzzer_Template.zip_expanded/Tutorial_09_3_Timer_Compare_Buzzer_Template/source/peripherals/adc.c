/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

#include "adc.h"

#include <stdio.h>

#include "MK22F51212.h"
#include "fsl_adc16.h"

#define REFERENCE_VOLTAGE   3300000  // 3,3V

#define ADC_CH_GROUP		0

/**
 * @details
 * 	Performs one A/D conversion with on the ADC1 of the processor. Will
 * 	By setting the channel, the conversion will begin. The ADC_SC1_COCO_MASK
 * 	flag is set, as soon as the conversion is done. The function will block
 * 	until this flag is set.
 */
uint16_t adc_get_16bit(const uint8_t channel) {
	ADC1->SC1[0] = channel;
	while (!(ADC1->SC1[0] & ADC_SC1_COCO_MASK)) {}  // wait until conversion has been finished
	return ADC1->R[0];
}

/**
 * @details
 * 	Performs a A/D conversation and returns the measured voltage of this channel.
 * 	The maximum voltage is the REFERENCE_VOLTAGE defined above.
 */
uint64_t adc_get_voltage(const uint8_t channel) {
	uint32_t value = adc_get_16bit(channel);
	uint64_t uV = ((uint64_t)REFERENCE_VOLTAGE * (uint64_t)value) / 65535;
	return uV;
}

/**
 * @details
 *  Return the raw current of the MCU car by reading the ADC_CH_CURRENT
 *
 * @return
 *   raw current
 */
uint64_t adc_get_current(void) {
	return adc_get_16bit(ADC_CH_CURRENT);
}

/**
 * @details
 * 	Returns the power consumption of the MC-Car
 *
 * 	          Ushunt [mV]        Ushunt
 * 	I [mA] = -------------- = ------------ x Yshunt
 * 	          Rshunt [Ohm]     100 * 1000
 */
uint64_t adc_get_mA(void) {
	uint64_t uShunt = adc_get_voltage(ADC_CH_CURRENT);
	uint64_t iShunt = uShunt * 68 / (1000 * 100) - 15;
	return iShunt;
}

/**
 * @details
 *  Returns the energy consumption of the MC-Car by reading the voltage and
 *  converting it.
 */
uint64_t adc_get_mV(void) {
	uint64_t voltage = adc_get_voltage(ADC_CH_BAT_VOLTAGE);
	uint64_t iShunt = voltage * 37 / 1000;
	return iShunt;
}

/**
 * Reads and returns the temperature of the microcontroller
 *
 * @returns
 *   the temperature in 0.1�C => 237 = 23.7�C
 */
uint64_t adc_get_temperature(void) {
	uint64_t vTemp = adc_get_voltage(ADC_CH_TEMPERATURE);
	return 250 - ((vTemp - 716000) / 162);
}

/**
 * @details
 * 	Print Voltage, mV, mA, Raw Current, Temperature
 */
void adc_print_data(void) {
	uint32_t value;
	value = adc_get_temperature();
	printf("\nTemperatur: %d\n", value);
	value = adc_get_voltage(ADC_CH_BAT_VOLTAGE);
	printf("Voltage: %d\n", value);
	value = adc_get_mV();
	printf("mV: %d\n", value);
	value = adc_get_mA();
	printf("mA: %d\n", value);
	value = adc_get_current();
	printf("Raw Current: %d\n", value);
}
