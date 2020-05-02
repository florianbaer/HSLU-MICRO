/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         simple driver for the blue user led on the tinyK22
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          19.03.2020
 *
 *--------------------------------------------------------------------
 */
#ifndef SOURCES_LED_H_
#define SOURCES_LED_H_

void ledSetOn(void);
void ledSetOff(void);
bool ledIsOn(void);
tError ledParseCommand(const char *cmd);
void ledInit(void);

#endif /* SOURCES_TINYLED_H_ */
