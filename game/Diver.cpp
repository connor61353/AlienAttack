//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: Diver.cpp
// Description: Alien Attack game
//=====================================================
#include "Diver.h"


//sets static variables values
int Diver::lives = 6;
float const Diver::DiverX = (WINDOW_WIDTH / 2.0f) - 25;
float const Diver::DiverY = (WINDOW_HEIGHT * 0.9f);

//=====================================================
//description: 
// diver constructor
//parameters:
// none
//return type:
// none
//=====================================================
Diver::Diver() {
	diver = new Pixie("Helldiver.png", DiverX, DiverY, DIVER_PIXIE);
	diver->setScale(SPRITE_MULTIPLIER, SPRITE_MULTIPLIER);
}

//=====================================================
//description: 
// moves Diver left or right
//parameters:
// none
//return type:
// void
//=====================================================
void Diver::move() {
		if (Keyboard::isKeyPressed(Keyboard::Left)) //if left key is pressed
		{
			if (diver->getX() > DIVER_DISTANCE + DIVER_BOUNDS) { //prevents moving offscreen to the left
				//moves diver left
				diver->move(-DIVER_DISTANCE, 0);
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) //if right key is pressed
		{
			if (diver->getX() < WINDOW_WIDTH - (SPRITE_SIZE_X * SPRITE_MULTIPLIER) - DIVER_DISTANCE - DIVER_BOUNDS) { //prevents moving offscreen to the right
				//moves diver right
				diver->move(DIVER_DISTANCE, 0);
			}
		}
}