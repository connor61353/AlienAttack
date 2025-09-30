//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: Army.cpp
// Description: Alien Attack game
//=====================================================
#include "Army.h"

//=====================================================
//description: 
// army constructor
//parameters:
// none
//return type:
// none
//=====================================================
Army::Army() {
	float offset = 0.0f; //how far over to the right the next automaton will spawn

	//for each automaton being created
	for (int i = 0; i < AUTOMATON_COUNT; i++) {
		//adds new automaton to list, spaced <offset> to the right
		army.push_back(new Automaton(offset));
		//moves offset by 1 sprite
		offset += (SPRITE_SIZE_X * SPRITE_MULTIPLIER);
	}
}

//=====================================================
//description: 
// checks if an automaton in the army has been hit, and deletes it and the missile that it it
//parameters:
// @missiles - list of player missiles currently on screen
//return type:
// void
//=====================================================
void Army::AutomatonHit(list<Missile*>& missiles) {
	for (auto automaton : army) { //reads through automaton list
		for (auto mis : missiles) { //reads through missile list
			if (mis->getMissile()->getY() <= automaton->getAutomaton()->getY() + (SPRITE_SIZE_Y * SPRITE_MULTIPLIER) && mis->getMissile()->getY() + MISSILE_SIZE_Y >= automaton->getAutomaton()->getY()) { //if the tip of a missile has reached the automaton's y value
				for (float i = 0.0f; i < MISSILE_SIZE_X; i++) { //checks every value across the width of the missile
					if (mis->getMissile()->getX() + i >= automaton->getAutomaton()->getX() && mis->getMissile()->getX() + i <= automaton->getAutomaton()->getX() + (SPRITE_SIZE_X * SPRITE_MULTIPLIER)) { //checks if a pixel of the missile overlapped with the automaton sprite
						//removes hitting missile
						delete mis; 
						//removes mis space from missile list
						missiles.remove(mis);
						//removes hit automaton
						army.remove(automaton);
						//delete automaton
						delete automaton;
						//exits to avoid access violation from loop
						return; 
					}
				}
			}
		}
	}
}

//=====================================================
//description: 
// chance for an automaton to shoot a missile
//parameters:
// @missiles - list of player missiles
//return type:
// void
//=====================================================
void Army::AutomatonAttack(list<Missile*>& missiles, Diver* diver) {
	int random; //random value

	for (auto automaton : army) { //reads through army
		random = rand() % CHANCE; //creates random number through CHANCE
		if (random == 1) { //if the random number hits 1, shoots missile
			//prints missile
			missiles.push_back(new Missile(automaton->getAutomaton(), diver)); 
		}
	}
}

//=====================================================
//description: 
// calls movement function for all automatons in army
//parameters:
// none
//return type:
// void
//=====================================================
void Army::move() {
	//for each automaton
	for (auto automaton : army) {
		//calls movement
		automaton->move();
	}
}