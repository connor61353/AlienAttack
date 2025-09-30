//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: Automaton.cpp
// Description: Alien Attack game
//=====================================================
#include "Automaton.h"

//set static variables
float const Automaton::AutomatonX = 10.0f;
float const Automaton::AutomatonY = 10.0f;

//=====================================================
//description: 
// automaton constructor
//parameters:
// @Xoffset - x distance from the first automaton spawn (increments from 0 in army)
//			  used to space automatons out
//return type:
// none
//=====================================================
Automaton::Automaton(float Xoffset) {
	//creates new automaton pixie
	automaton = new Pixie("Automaton.png", AutomatonX + Xoffset, AutomatonY, AUTOMATON_PIXIE); 
	//sets scale
	automaton->setScale(SPRITE_MULTIPLIER, SPRITE_MULTIPLIER); 
	//sets default direction to true (right)
	direction = true;
}

//=====================================================
//description: 
// moves automaton
// left and right
// down at edge of screen
// changes direction at edge of screen
//parameters:
// none
//return type:
// void
//=====================================================
void Automaton::move() {
	if (direction == false) //if direction is left
	{
		if (automaton->getX() > AUTOMATON_DISTANCE_X) { //prevents moving offscreen to the left
			//moves automaton to the left
			automaton->move(-AUTOMATON_DISTANCE_X, 0);
		}
		else { //if atomaton is at the screen edge, changes direction and moves it down
			//changes direction
			direction = !direction;
			//moves down
			automaton->move(0, (SPRITE_SIZE_Y * SPRITE_MULTIPLIER) + AUTOMATON_DISTANCE_Y);
		}
	}
	else if (direction == true) //if direction is right
	{
		if (automaton->getX() < WINDOW_WIDTH - AUTOMATON_DISTANCE_X - (SPRITE_SIZE_X * SPRITE_MULTIPLIER)) { //prevents moving offscreen to the right
			//moves automaton to the right
			automaton->move(AUTOMATON_DISTANCE_X, 0);
		}
		else { //if atomaton is at the screen edge, changes direction and moves it down
			//changes direction
			direction = !direction;
			//moves down
			automaton->move(0, (SPRITE_SIZE_Y * SPRITE_MULTIPLIER) + AUTOMATON_DISTANCE_Y);
		}
	}
}