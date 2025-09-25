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
  // put your setup code here, to run once:
  pinMode(TUNE_PIN, OUTPUT);

  lcd.begin(16,1);
  lcd.print("Hello, World!");

}

void loop() {
  // put your main code here, to run repeatedly: 
  play_PvZ_theme(TUNE_PIN);
}


