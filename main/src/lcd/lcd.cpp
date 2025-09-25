/*********************************************************
 * File: tunes.cpp
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Contains menu logic to be displayed on LCD
 *        
 * Date Created: September 22, 2025
 * 
*********************************************************/

#include "lcd.h"

LiquidCrystal lcd(RS, E, DB0, DB1, DB2, DB3, DB4, DB5, DB6, DB7);

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
	ConfigNavFSM() : currentState(ConfigState::LO) {}

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

int ConfigNav() {
	ConfigNavFSM nav;
	bool exit = false;

	while (!exit) {
		if (nav.getCurrentState() == ConfigState::LO) {
	        lcd.clear();
			lcd.print("BASS");
	    } 
	    else if (nav.getCurrentState() == ConfigState::MID) {
	        lcd.clear();
			lcd.print("MID");
	    }
		else if (nav.getCurrentState() == ConfigState::HI) {
	        lcd.clear();
			lcd.print("TREBLE");
	    }
	}
}







