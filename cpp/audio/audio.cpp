#include "audio.h"

const byte PROGMEM tune_pin_to_timer_PGM[] = { 3, 1 };
volatile byte *_tunes_timer1_pin_port;
volatile byte _tunes_timer1_pin_mask;
volatile int32_t timer1_toggle_count;
volatile byte *_tunes_timer3_pin_port;
volatile byte _tunes_timer3_pin_mask;
byte _tune_pins[AVAILABLE_TIMERS];
byte _tune_num_chans = 0;
volatile boolean tune_playing; // is the score still playing?
volatile unsigned wait_timer_frequency2;       /* its current frequency */
volatile boolean wait_timer_playing = false;   /* is it currently playing a note? */
volatile boolean tonePlaying = false;
volatile unsigned long wait_toggle_count;      /* countdown score waits */

// pointers to your musical score and your position in said score
volatile const byte *score_start = 0;
volatile const byte *score_cursor = 0;

/* AUDIO */

bool ArduboyAudio::audio_enabled = false;

void ArduboyAudio::on()
{
  audio_enabled = true;
}

bool ArduboyAudio::enabled()
{
  return audio_enabled;
}

void ArduboyAudio::off()
{
  audio_enabled = false;
}

void ArduboyAudio::saveOnOff()
{
}

void ArduboyAudio::begin()
{
  tune_playing = false;
}

/* TUNES */

void ArduboyTunes::initChannel(byte pin)
{
}

void ArduboyTunes::playNote(byte chan, byte note)
{
}

void ArduboyTunes::stopNote(byte chan)
{
}

void ArduboyTunes::playScore(const byte *score)
{
  score_start = score;
  score_cursor = score_start;
  step();  /* execute initial commands */
  tune_playing = true;  /* release the interrupt routine */
}

void ArduboyTunes::stopScore (void)
{
  tune_playing = false;
}

bool ArduboyTunes::playing()
{
  return tune_playing;
}

void ArduboyTunes::step()
{
}

void ArduboyTunes::closeChannels(void)
{
}

void ArduboyTunes::soundOutput()
{
}

void ArduboyTunes::tone(unsigned int frequency, unsigned long duration)
{
}