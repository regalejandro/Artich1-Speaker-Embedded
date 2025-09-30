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

Button cButton(34);
Button uButton(30);
Button dButton(32);


void ButtonsInit() {
	cButton.begin();
	uButton.begin();
	dButton.begin();
}

void ConfigNav() {
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
	    
	    if (uButton.pressed()) {
	    	nav.handleEvent(ConfigEvent::UP);
	    }
	    else if (dButton.pressed()) {
	    	nav.handleEvent(ConfigEvent::DOWN);
	    }
	    
	    else if (cButton.pressed()) {
	    	exit = true;
	    }

	    delay(REFRESH_DELAY);
	}
}







