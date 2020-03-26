/*
 * sturcts.h
 *
 *  Created on: 15.03.2020
 *      Author: hslu
 */

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct _adress {
	char forename[120];
	char lastname[120];
    char adresse[120];
    int8_t zipcode;
    char adress[120];

} adress;

typedef struct _zeit {
	int sekunden;
	int minuten;
	int stunden;
} zeit;

typedef struct _zeit_bit {
	uint8_t sekunden: 6;
	uint8_t minuten :7;
	uint8_t stunden :6;
} zeit_bit;

typedef enum _boolean {
	FALSE = 0,
	TRUE = 1
} boolean;

typedef struct _led_counter {
	uint16_t FRR = 0;
	uint16_t FRG = 0;
	uint16_t FRB = 0;
	uint16_t FLR = 0;
	uint16_t FLG = 0;
	uint16_t FLB = 0;
	uint16_t RRR = 0;
	uint16_t RLR = 0;
} led_counter;

#endif /* STRUCTS_H_ */
