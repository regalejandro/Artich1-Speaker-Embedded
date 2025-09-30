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
#include <Button.h>
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

#define REFRESH_RATE 60	// Hz
#define REFRESH_DELAY 1000 / REFRESH_RATE

extern LiquidCrystal lcd;
extern Button cButton;
extern Button uButton;
extern Button dButton;

// FSM States
enum class ConfigState {
	LO,
	MID,
	HI
};

// Transition triggers
enum class ConfigEvent {
	UP,
	DOWN
};

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

void ButtonsInit();
void ConfigNav();


#endif	// LCD_H