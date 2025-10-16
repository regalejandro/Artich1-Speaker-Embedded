/*********************************************************
 * File: controls.cpp
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Contains functions related to buttons
 * 				and physical user inputs
 *        
 * Date Created: October 15, 2025
 * 
*********************************************************/

#include "controls.h"

// Instantiate buttons
Button cButton(CBUTTON);
Button uButton(UBUTTON);
Button dButton(DBUTTON);

// Initialize buttons
void ButtonsInit() {
	cButton.begin();
	uButton.begin();
	dButton.begin();
}