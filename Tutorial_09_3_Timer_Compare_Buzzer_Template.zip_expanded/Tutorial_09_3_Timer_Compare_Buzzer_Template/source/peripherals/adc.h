/*
 * Copyright (c) 2020, Lucerne University of Applied Sciences and Arts.
 * @author Lucien Zuercher <lucien.zuercher@stud.hslu.ch>
 */

#ifndef _ADC_H_
#define _ADC_H_


#include "peripherals.h"

// define constants for the ADC
// Those can be also found in the board/peripherals.c file
// The ADC1_channelsConfig array contains those values,
// the order is defined by through the Periperals > ADC1 > ADC Channel Configuration
#define ADC_CH_TEMPERATURE      ADC1_channelsConfig[0].channelNumber // TempSensor = 26
#define ADC_CH_BAT_VOLTAGE      ADC1_channelsConfig[1].channelNumber // U_BAT 	 = 0
#define ADC_CH_CURRENT	      	ADC1_channelsConfig[2].channelNumber // I_TOT 	 = 19

/**
 * @brief
 *  Return the raw current of the MCU car.
 *
 * @return
 *   raw current
 */
uint64_t adc_get_current(void);

/**
 * @brief
 * 	Return the voltage
 *
 * @param[in]
 *   the channel number to read the voltage from
 * @return
 *   the measured voltage in uV (0..REFERENCE_VOLTAGE)
 */
uint64_t adc_get_voltage(const uint8_t channel);

/**
 * @details
 * 	Returns the power consumption of the MC-Car.
 *
 * @return
 *   the power consumption in mA
 */
uint64_t adc_get_mA(void);


/**
 * @brief
 *  Returns the energy consumption of the MC-Car
 *
 * @return
 *   the power consumption in mV
 */
uint64_t adc_get_mV(void);

/**
 * @brief
 * 	Performs one A/D conversion for the specified channel with 16 bit resolution.
 * 	The function blocks until the conversion has been finished.
 *
 * @param[in]
 *   the channel number to convert
 * @return
 *   a 16bit value
 */
uint16_t adc_get_16bit(const uint8_t channel);

/**
 * @brief
 * 	Reads and returns the temperature of the microcontroller
 *
 * @returns
 *   the temperature in 0.1�C => 237 = 23.7�C
 */
uint64_t adc_get_temperature(void);

/**
 * @brief
 * 	prints the through adc read sensor data.
 */
void adc_print_data(void);

#endif /* _ADC_H_ */
