/*********************************************************
 * File: main.ino
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Main file for Artich1 Bluetooth Speaker
 *        
 * Date Created: September 15, 2025
 * 
*********************************************************/

#include "src/lcd/lcd.h"
#include "src/extras/tunes.h"

#define TUNE_PIN 3

void setup() {
  pinMode(TUNE_PIN, OUTPUT);

  // Initialize Hardware
  LCDInit();
  ButtonsInit();

  lcd.print("Pairing Device");
  delay(1000);
  lcd.setCursor(15, 1);
  lcd.write("*");
  delay(5000);
}

void loop() {
  lcd.clear();
  lcd.print("Playing Tunes");
  if (cButton.pressed()) {
    ConfigNav();
  }
  delay(REFRESH_DELAY);
  
  //play_PvZ_theme(TUNE_PIN);
}


