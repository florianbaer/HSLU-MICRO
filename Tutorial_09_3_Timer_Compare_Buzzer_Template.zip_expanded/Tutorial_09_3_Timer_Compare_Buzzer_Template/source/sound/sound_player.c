/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         Nokia Ringtone player
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          04.04s.2020
 *
 *--------------------------------------------------------------------
 */

#include <ftm0.h>
#include <sound_player.h>
#include <string.h>
#include "platform.h"
#include "sound.h"
#include "term.h"

#define MAX_MELODY_SIZE       800   // max number of notes

typedef struct
{
  uint8_t note;     // note frequency (0 = a Okt.4 ... 47 = g# Okt.7, 48 = pause)
  uint8_t time;     // note duration (in units of 1/64 notes)
} tNote;


const uint16_t noteFrequency[49]=  // # frequency [Hz] of some notes
{
    // c       c#         d         d#        e         f        f#       g      g#         a      a#        b/h
    (261.6),  (277.2),  (293.7),  (311.1),  (329.6),  (349.2),  (370),  (392),  (415.3),  (440),  (466.2),  (493.9),  // 4. oktave
    (523.3),  (554.4),  (587.3),  (622.3),  (659.3),  (698.5),  (740),  (784),  (830.6),  (880),  (932.3),  (987.8),  // 5. oktave
    (1046.5), (1108.7), (1174.7), (1244.5), (1318.5), (1396.9), (1480), (1568), (1661.2), (1760), (1864.7), (1975.5), // 6. oktave
    (2093),   (2217.4), (2349.3), (2489),   (2637),   (2793.8), (2960), (3136), (3322.4), (3520), (3729.4), (3951),   // 7. oktave
    0 //pause
};

const char wro[] = {0x57, 0x68, 0x69, 0x74, 0x65, 0x52, 0x61, 0x62, 0x62, 0x69, 0x74, 0x4F, 0x62, 0x6A, 0x65, 0x63, 0x74};
const char jp[] = "JP:d=32,o=6,b=28:p,b5,a#5,8b5,16p,b5,a#5,8b5,16p,b5,a#5,16b.5,c#, 16c#.,e,8e,16p,d#,b5,16c#.,a#5,16f#5,d#,b5,8c#,16p,f#,b5,16e.,d#,16d#.,c#,8c#.";

static char soundTitle[10];               // name of the melody (string max 10 characters)
static tNote melody[MAX_MELODY_SIZE];     // array for the melody
static uint16_t melodyPos;                // current tone position in the melody
static uint16_t melodySize;               // number of tones in the melody
static bool isPlaying;
static uint8_t msPer64Note;
static tCommandLineHandler clh;


void soundFinishedCallback()
{
    static bool playNote = FALSE;
    if (isPlaying)
    {
        if (playNote)
        {
            melodyPos++;
            if (melodyPos < melodySize)
            {
                sound_beep(noteFrequency[melody[melodyPos].note], melody[melodyPos].time * msPer64Note);
            }
            else
            {
                isPlaying = FALSE;
            }
        }
        else
        {
            sound_beep(0, 20);
        }
        playNote = !playNote;
    }
}


void sound_start(void)
{
    if (melodyPos == melodySize) melodyPos = 0;
    isPlaying = TRUE;
    soundSetCallbackHandler(soundFinishedCallback);
    sound_beep(noteFrequency[melody[melodyPos].note], melody[melodyPos].time * msPer64Note);
}


/**
 * Stops the current melody
 */
void sound_stop(void)
{
  if (!isPlaying)
  {
    melodyPos = 0;
  }
  isPlaying = FALSE;
}


/**
 * Returns true, if the player is playing a meldoy
 *
 * @returns
 *    true, if playing, false else
 */
bool sound_is_playing(void)
{
    return isPlaying;
}


/**
 * Toggles between play and pause.
 */
void sound_toogle_play_pause(void)
{
    if (sound_is_playing()) sound_stop();
    else sound_start();
}


/*
 * Parses the ring tone string and stores frequency and duration
 * for every tone in an array of type tNote.
 *
 * @param[in] p
 *   the RTTTL string
 */
void sound_load(const char *p)
{
  uint8_t i, value, param, note;
  uint8_t duration, defDuration;
  uint8_t octave, defOctave;

  // Read Title
  for (i=0; i<sizeof(soundTitle); i++)
  {
    if (*p == ':') break;
    soundTitle[i] = *p;
    p++;
  }

  while (*p && *p != ':') p++;
  if (!*p) return;
  p++;


  // parse default values
  while (*p) {
    while (*p == ' ') p++;    // Skip Spaces
    if (!*p) return;          // abort at the end of the string
    if (*p == ':') break;

    param = *p++;
    if (*p != '=') return;

    p++;
    value = 0;
    while (*p >= '0' && *p <= '9') value = value * 10 + (*p++ - '0');

    switch (param) {
      case 'd': defDuration = 64 / value; break;
      case 'o': defOctave = ((uint8_t)value - 4) * 12; break;
      //case 'b': tick64 = (uint16)(((60 * 1000000l) / (value * 64)) - 1); break; // bpm

      //case 'b': msPer64Note = (uint8)((60*1000l) / (value * 16)); // bpm
      case 'b': msPer64Note = (uint8_t)(3750 / value); // bpm
    }

    while (*p == ' ') p++;
    if (*p == ',') p++;
  }
  p++;

  melodySize = 0;
  while (*p)
  {
    duration = defDuration;
    octave = defOctave;

    // Skip whitespace
    while (*p == ' ') p++;
    if (!*p) return;

    // Parse duration
    if (*p >= '0' && *p <= '9')
    {
     value = 0;
     while (*p >= '0' && *p <= '9') value = value * 10 + (*p++ - '0');
     duration = (uint8_t) (64 / value);
    }

    // Parse note
    switch (*p){
      case 0: return;
      case 'C': case 'c': note = 0; break;
      case 'D': case 'd': note = 2; break;
      case 'E': case 'e': note = 4; break;
      case 'F': case 'f': note = 5; break;
      case 'G': case 'g': note = 7; break;
      case 'A': case 'a': note = 9; break;
      case 'H': case 'h': note = 11; break;
      case 'B': case 'b': note = 11; break;
      case 'P': case 'p': note = 48; break;
    }
    p++;

    if (*p == '#'){
       note++;
       p++;
    }

    if (*p == 'b'){
       note--;
       p++;
    }

    // Parse special duration
    if (*p == '.'){
      duration += duration / 2;
      p++;
    }

    // Parse octave 4..7
    if (*p >= '0' && *p <= '9'){
      octave = ((*p++ - '0') - 4) * 12;
    }

    // Parse special duration (again...)
    if (*p == '.') {
      duration += duration / 2;
      p++;
    }

    // Skip delimiter
    while (*p == ' ') p++;
    if (*p == ',') p++;

    note += octave;
    if (note > 48) note = 48;

    melody[melodySize].note = note;
    melody[melodySize].time = duration;
    melodySize++;
    if (melodySize >= MAX_MELODY_SIZE) break;
  }

  melodyPos = 0;
}


/**
 * Parses the ring tone string and starts to play immediately.
 *
 * @param[in] p
 *   the RTTTL string
 */
void sound_play(const char *p)
{
  sound_load(p);
  sound_start();
}


/**
 * This function parses one command line, executes the command and returns the status
 *
 * @param[in] cmd
 *   the null terminated string to parse
 * @returns
 *   EC_SUCCESS if there was a valid command
 *   EC_INVALID_CMD if the command was unknown or invalid
 */
tError soundPlayerParseCommand(const char *cmd)
{
  tError result = EC_INVALID_ARG;
  if (strcmp(cmd, "help") == 0)
  {
    term_write_line("sp (SoundPlayer) commands:");
    term_write_line("  help");
    term_write_line("  load rttl-string");
    term_write_line("  play");
    term_write_line("  stop");
    result = EC_SUCCESS;
  }
  else if (strncmp(cmd, "load ", sizeof("load")) == 0)
  {
    cmd += sizeof("load ") - 1;
    sound_load(cmd);
    result = EC_SUCCESS;
  }
  else if (strncmp(cmd, "play", sizeof("play")-1) == 0)
  {
    sound_start();
    result = EC_SUCCESS;
  }
  else if (strncmp(cmd, "stop", sizeof("stop")-1) == 0)
  {
    sound_stop();
    result = EC_SUCCESS;
  }
  else if (strncmp(cmd, wro, sizeof(wro)-1) == 0)
  {
    sound_play(jp);
    result = EC_SUCCESS;
  }

  return result;
}


/**
 * Initializes the sound player
 */
void sound_player_init(void)
{
  // register terminal command line handler
  term_register_command_line_handler(&clh, "sp", "(sound player)", soundPlayerParseCommand);
}
