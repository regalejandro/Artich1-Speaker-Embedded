/*********************************************************
 * File: controls.h
 * 
 * Author:  Alejandro Regalado
 * 
 * Description: Header file for controls.cpp and pin
 * 				definitions
 *        
 * Date Created: October 15, 2025
 * 
*********************************************************/

#ifndef CONTROLS_H
#define CONTROLS_H

/* Includes */
#include <Arduino.h>
#include <stdint.h>
#include <Button.h>

/* Define Macros */
#define CBUTTON 27
#define UBUTTON 25
#define DBUTTON 23
#define LBUTTON 31
#define RBUTTON 29

/* Globals */
extern Button cButton;
extern Button uButton;
extern Button dButton;
extern Button lButton;
extern Button rButton;

/* Enums */
// Transition triggers
enum class ConfigEvent {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

/* Prototypes */
void ButtonsInit();


#endif	//CONTROLS_H


