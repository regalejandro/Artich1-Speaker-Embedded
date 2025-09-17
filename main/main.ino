
#include "src/extras/tunes.h"

#define TEST_PIN 2

void setup() {
  // put your setup code here, to run once:
  pinMode(TEST_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  play_PvZ_theme(TEST_PIN);
}


