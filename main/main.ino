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

  ButtonsInit();
  lcd.begin(16,1);
  //lcd.print("Hello, World!");
  lcd.print("Pair Device");
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
  lcd.setCursor(15, 1);
  lcd.write("*");
  delay(5000);
  digitalWrite(8, HIGH);


}

void loop() {
  // put your main code here, to run repeatedly: 
  lcd.clear();
  lcd.print("Playing Tunes");
  if (cButton.pressed()) {
    ConfigNav();
  }
  delay(REFRESH_DELAY);
  
  //play_PvZ_theme(TUNE_PIN);
}


