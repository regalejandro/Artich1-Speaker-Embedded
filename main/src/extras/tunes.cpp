/*********************************************************
 * File: tunes.cpp
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Functions to produce simple square wave
 *              tunes.
 *        
 * Date Created: September 15, 2025
 * 
*********************************************************/

#include "tunes.h"

// Plays a note of a specified frequency for a specified amount of time in beats
void play_note(uint32_t freq, uint8_t time, uint8_t pin) {
  
  // Define the length of a cycle for the note in microseconds 
  uint32_t cycle = 1000000 / freq;

  // Alternate output at note frequency
  // freq * -> ensures the same runtime regardless of frequency
  // 60/BPM -> ensure 1 sec per beat
  // time/4 -> more iterations for higher value of time
  for (uint32_t i = 0; i < freq * 60/BPM * time/4; i++) {
    // Each iteration is one cycle
    digitalWrite(pin, HIGH);
    delayMicroseconds(cycle / 2);
    digitalWrite(pin, LOW);
    delayMicroseconds(cycle / 2);
  }
}

// Serves as a gap between notes for a specied amount of time in beats
void quiet(uint8_t time, uint8_t pin) {
  uint32_t delay_us = 1000000 * 60/BPM * time/4;
  uint32_t delay_ms = delay_us / 1000;
  digitalWrite(pin, LOW);
  delay(delay_ms);
}

// Plays Plants Vs. Zombies Theme
void play_PvZ_theme(uint8_t pin) {
    
  play_note(554, 1, pin);
  play_note(587, 1, pin);
  play_note(554, 1, pin);
  play_note(587, 1, pin);

  play_note(466, 1, pin);
  play_note(392, 1, pin);
  quiet(2, pin);

  play_note(466, 1, pin);
  play_note(392, 1, pin);
  quiet(2, pin);

  play_note(587, 1, pin);
  play_note(392, 1, pin);
  quiet(2, pin);

}