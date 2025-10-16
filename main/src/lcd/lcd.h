/*********************************************************
 * File: lcd.h
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

/* Includes */
#include <Arduino.h>
#include <stdint.h>
#include <Button.h>
#include <LiquidCrystal.h>

// Project files
#include "../controls/controls.h"

/* Define Macros */
// LCD Pins
#define RS 12
#define E 13
#define DB0 22
#define DB1 24
#define DB2 26
#define DB3 28
#define DB4 30
#define DB5 32
#define DB6 34
#define DB7 36

// LCD Refresh Rate
#define REFRESH_RATE 60	// Hz
#define REFRESH_DELAY 1000 / REFRESH_RATE


/* Globals */
extern LiquidCrystal lcd;

/* Enums */
// FSM States
enum class ConfigState {
	LO,
	MID,
	HI
};

/* Classes */
// Handle Configuration Menu Navigation
class ConfigNavFSM {
public:
	ConfigNavFSM() : currentState(ConfigState::MID) {}

	void handleEvent(ConfigEvent event) {
		switch (currentState) {
			case ConfigState::LO:
				if (event == ConfigEvent::UP) {
					currentState = ConfigState::MID;
				}
				break;
		
			case ConfigState::MID:
				if (event == ConfigEvent::UP) {
					currentState = ConfigState::HI;
				}
				else if (event == ConfigEvent::DOWN) {
					currentState = ConfigState::LO;
				}
				break;
		
			case ConfigState::HI:
				if (event == ConfigEvent::DOWN) {
					currentState = ConfigState::MID;
				}
				break;
		
		}
	}

    ConfigState getCurrentState() const {
        return currentState;
    }

private:
	ConfigState currentState;
};

/* Prototypes */
void ConfigNav();


#endif	// LCD_H


