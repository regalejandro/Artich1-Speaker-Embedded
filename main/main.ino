
#include "src/lcd/lcd.h"
#include "src/extras/tunes.h"

#define TUNE_PIN 3

LiquidCrystal lcd(RS, E, DB0, DB1, DB2, DB3, DB4, DB5, DB6, DB7);

void setup() {
  // put your setup code here, to run once:
  pinMode(TUNE_PIN, OUTPUT);

  lcd.begin(16,1);
  lcd.print("Hello, World!");

}

void loop() {
  // put your main code here, to run repeatedly: 
  play_PvZ_theme(TUNE_PIN);
}


