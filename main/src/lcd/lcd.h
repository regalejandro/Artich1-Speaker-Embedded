/*********************************************************
 * File: tunes.cpp
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Header file for lcd.cpp and pin 
 * 				definitions
 *        
 * Date Created: September 22, 2025
 * 
*********************************************************/

#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <stdint.h>

#include <LiquidCrystal.h>

#define RS 52
#define E 50
#define DB0 53
#define DB1 51
#define DB2 49
#define DB3 47
#define DB4 45
#define DB5 43
#define DB6 41
#define DB7 39

extern LiquidCrystal lcd;


#endif	// LCD_H