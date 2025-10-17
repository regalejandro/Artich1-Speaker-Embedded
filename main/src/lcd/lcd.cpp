/*********************************************************
 * File: lcd.cpp
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


void LCDInit() {
	lcd.begin(16, 2, 40);
}

// Controls to navigate setting configuartion menu
void ConfigNav() {
	ConfigNavFSM nav;
	bool exit = false;

	while (!exit) {
		if (nav.getCurrentState() == ConfigState::LO) {
		    DisplayLevel(ConfigState::LO);
	    } 
	    else if (nav.getCurrentState() == ConfigState::MID) {
	        DisplayLevel(ConfigState::MID);
	    }
		else if (nav.getCurrentState() == ConfigState::HI) {
	        DisplayLevel(ConfigState::HI);
	    }
	    
	    if (uButton.pressed()) {
	    	nav.handleEvent(ButtonPress::UP);
	    }
	    else if (dButton.pressed()) {
	    	nav.handleEvent(ButtonPress::DOWN);
	    }
	    else if (lButton.pressed()) {
	    	nav.changeValue(ButtonPress::LEFT);
	    }
	    else if (rButton.pressed()) {
	    	nav.changeValue(ButtonPress::RIGHT);
	    }
	    
	    else if (cButton.pressed()) {
	    	exit = true;
	    }

	    delay(REFRESH_DELAY);
	}

	return;
}

// Displays currnet frequency option and level
void DisplayLevel(ConfigState state) {
	
	
	uint8_t sel_level = 0;

	lcd.clear();
	if (state == ConfigState::LO) {
		lcd.print("BASS");
		sel_level = lo_level;
	}
	if (state == ConfigState::MID) {
		lcd.print("MID");
		sel_level = mid_level;
	}
	if (state == ConfigState::HI) {
		lcd.print("TREBLE");
		sel_level = hi_level;
	}

	lcd.setCursor(0, 1);
	lcd.print("----------------");
	lcd.setCursor(sel_level - 1, 1);
	lcd.write("#");

	return;
}







