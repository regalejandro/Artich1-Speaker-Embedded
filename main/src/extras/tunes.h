



#ifndef TUNES_H
#define TUNES_H

#include <Arduino.h>
#include <stdint.h>

#define BPM 60

void play_note(uint32_t freq, uint8_t time, uint8_t pin);
void quiet(uint8_t time, uint8_t pin);

void play_PvZ_theme(uint8_t pin);

#endif	// TUNES_H