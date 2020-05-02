/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         Buzzer driver to generate different frequencies
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          04.04.2020
 *
 *--------------------------------------------------------------------
 */

#ifndef SOURCES_SOUND_H_
#define SOURCES_SOUND_H_


typedef void (*soundFinishedHandler)(void);

void soundSetCallbackHandler(soundFinishedHandler handler);
void sound_beep(uint16_t frequency, uint16_t timeMS);
void sound_init(void);


#endif /* SOURCES_SOUND_H_ */
