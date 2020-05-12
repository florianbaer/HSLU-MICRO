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

#include <ftm0.h>
#include <string.h>
#include "platform.h"
#include "sound.h"
#include "term.h"
#include "util.h"

#if !SOLUTION

static uint16_t tmrFrequencyTicks;                    // number of timer ticks to generate the desired frequency
static uint32_t tmrPlayTimeTicks;                     // number of timer ticks to play the frequency (duration)
static soundFinishedHandler soundFinishedCallback;    // optional callback function if one tone has been finished
static tCommandLineHandler clh;                       // terminal command line handler

/**
 * Registers an optional callback handler to be invoked if a tone finished playing.
 * An existing handler will be overridden. To remove the handler call this function
 * with the parameter "NULL".
 *
 * @param[in] handler
 *   the callback handler to register
 */
void soundSetCallbackHandler(soundFinishedHandler handler)
{
    soundFinishedCallback = handler;
}

/**
 * This handler is called if the channel 0 flag of the FTM0 is set.
 *
 * The purpose of this function is to generate a frequency during a desired time to
 * play a tone.
 * To generate the frequency, this function calculates the next compare time to toggle
 * a port pin, connected to the buzzer. If the frequency is 0, than the function
 * can be used to generate a pause (delay). After playing the tone or after the pause
 * this handler invokes an optional callback handler. This can be used to play the
 * next tone.
 */
void FTM0CH0_IRQHandler(void)
{
  OnEnterSoundISR();

  // count down the tmrPlayTimeTicks until it is smaller or equal to tmrFrequencyTicks
  if (tmrPlayTimeTicks >= tmrFrequencyTicks)
  {
    tmrPlayTimeTicks -= tmrFrequencyTicks;
  }
  else
  {
    // tmrPlayTimeTicky is lower as tmrFrequencyTicks (tmrPlayTimeTicky < tmrFrequencyTicks)
    // todo #9.3-09 => disable the whole timer channel 0 of FTM0
	  FTM0->CONTROLS[0].CnSC = 0;
    // todo #9.3-10 invoke the soundFinishedCallback function if the functionpointer isn't null!
	  if(soundFinishedCallback) soundFinishedCallback();
  }

  // todo #9.3-11 clear the channel 0 flag
  FTM0->CONTROLS[0].CnSC &= ~FTM_CnSC_CHF(1);

  // todo #9.3-12 set next compare time (value is stored in tmrFrequencyTicks)
  // => add tmrFrequencyTicks to the channel 0 value and store the result in the channel 0 value register
  FTM0->CONTROLS[0].CnV += tmrFrequencyTicks;

  OnExitSoundISR();
}

/**
 * This function configures a timer channel to generate a frequency during a certain time.
 *
 * @note
 *   If the frequency is 0, then the function generate a pause with the desired time.
 *   The macro FTM0_CLOCK contains the frequency of the FTM0. Defined in ftm0.h
 *
 * @param[in] frequency
 *   the desired frequency in Hz
 * @param[in] timeMS
 *   the playing time in milliseconds
 */
void sound_beep(uint16_t frequency, uint16_t timeMS)
{
  // calculate the number of ticks to play the tone during the desired time (timeMS)
  tmrPlayTimeTicks = FTM0_CLOCK / 1000 * timeMS;

  if (frequency > 0) // frequency >0 => generate sound
  {
    // todo #9.3-05 calculate the number of ticks needed to generate the desired frequency.
    // Note that you have to toggle the pin twice per period!
    // tmrFrequencyTicks = FTM0_CLOCK / (2 * frequency);
    tmrFrequencyTicks = ((10 * FTM0_CLOCK) / (2 * frequency) + 5) / 10;

    // todo #9.3-06 configure the channel status and control register as follows:
    // mode: output compare with "toggle on compare". Enable the channel interrupt
    FTM0->CONTROLS[0].CnSC = FTM_CnSC_MSx(1) | FTM_CnSC_ELSx(1) | FTM_CnSC_CHIE(1);
  }
  else // frequency == 0 => generate pause
  {
    // calculate the number of ticks needed to generate a pause of 1ms
    tmrFrequencyTicks = FTM0_CLOCK / 1000;

    // todo #9.3-07 configure the channel status and control register as follows:
    // mode: output compare with "clear on compare". Enable the channel interrupt
    FTM0->CONTROLS[0].CnSC = FTM_CnSC_MSx(1) | FTM_CnSC_ELSx(2) | FTM_CnSC_CHIE(1);
  }

  // todo #9.3-08 add to the current timer counter register the value of tmrFrequencyTicks calculated above and
  // store the result into the channel value register.
  FTM0->CONTROLS[0].CnV = FTM0->CNT + tmrFrequencyTicks;
}


/**
 * Command line parser for this file.
 * This code is complete and works.
 */
tError soundParseCommand(const char *cmd)
{
  tError result = EC_INVALID_ARG;
  if (strcmp(cmd, "help") == 0)
  {
    term_write_line("snd (sound) commands:");
    term_write_line("  help");
    term_write_line("  beep [freq Hz] [time ms]");
    result = EC_SUCCESS;
  }
  else if (strncmp(cmd, "beep", sizeof("beep")-1) == 0)
  {
    cmd += sizeof("beep");

    uint16_t freq;
    result = utilScanDecimal16u(&cmd, &freq);
    if (result != EC_SUCCESS) return result;

    uint16_t time;
    result = utilScanDecimal16u(&cmd, &time);
    if (result != EC_SUCCESS) return result;

    soundFinishedCallback = NULL;
    sound_beep(freq, time);
  }
  return result;
}


/**
 * Initialize the sound driver of the buzzer on PTC1 (FTM0_CH0)
 * (KRM216ff)
 */
void sound_init(void)
{
  // todo #9.3-04 configure port muxing of PTC1 to FTM3_CH0!
	PORTC->PCR[1] = PORT_PCR_MUX(4);
  // register terminal command line handler
  term_register_command_line_handler(&clh, "snd", "(sound)", soundParseCommand);
}
#endif
