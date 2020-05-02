/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         Nokia Ringtone player
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          04.04.2020
 *
 *--------------------------------------------------------------------
 */

#ifndef SOURCES_SOUNDPLAYER_H_
#define SOURCES_SOUNDPLAYER_H_

#include <stdbool.h>

bool sound_is_playing(void);
void sound_toogle_play_pause(void);
void sound_start(void);
void sound_stop(void);
void sound_load(const char *soundFile);
void sound_play(const char *soundFile);
void sound_player_init(void);

#endif /* SOURCES_SOUNDPLAYER_H_ */
