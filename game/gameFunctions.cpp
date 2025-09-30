//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: gameFunctions.cpp
// Description: Alien Attack game
//=====================================================
#include "gameHeader.h"

//=====================================================
//description: 
// deletes missiles that have gone out of the window border
//parameters:
// @missiles - missile list
//return type:
// void
//=====================================================
void MissileOutOfBounds(list<Missile*>& missiles) {
	for (auto mis : missiles) { //reads through missiles
		if (mis->getMissile()->getY() < 0 || mis->getMissile()->getY() > WINDOW_HEIGHT) { //if missile is out of bounds
			//deletes missile
			delete mis;
			//deletes missile from list
			missiles.remove(mis);
			//breaks out of loop when a missile is found to be out of bounds
			break; 
		}
	}
}

//=====================================================
//description: 
// checks if diver has been hit by a missile or automaton
//parameters:
// @diver - current diver
// @missiles - missile list
// @army - automaton list
//return type:
// bool
//=====================================================
bool DiverHit(Diver* diver, list<Missile*>& missiles, list<Automaton*> army) {
	//checks missiles
	for (auto mis : missiles) { //reads through missile list
		if (mis->getMissile()->getY() + (MISSILE_SIZE_Y*ENEMY_MISSILE_MULTIPLIER) >= diver->getDiver()->getY()) { //if the tip of a missile has reached the diver's y value
			for (float i = 0.0f; i < MISSILE_SIZE_X * ENEMY_MISSILE_MULTIPLIER; i++) { //checks every value across the width of the missile
				if (mis->getMissile()->getX() + i >= diver->getDiver()->getX() && mis->getMissile()->getX() + i <= diver->getDiver()->getX() + (SPRITE_SIZE_X*SPRITE_MULTIPLIER)) { //checks if a pixel of the missile overlapped with the diver sprite
					//removes mis space from missile list
					missiles.remove(mis); 
					//deletes hitting missile
					delete mis;
					return true;
				}
			}
		}
	}
	//checks automatons
	for (auto automaton : army) { //reads through army list
		if (automaton->getAutomaton()->getY() + (SPRITE_SIZE_Y * SPRITE_MULTIPLIER) >= diver->getDiver()->getY()) { //if automaton has reached y level of diver
			if (automaton->getAutomaton()->getX() + (SPRITE_SIZE_X * SPRITE_MULTIPLIER) >= diver->getDiver()->getX() && automaton->getAutomaton()->getX() <= diver->getDiver()->getX() + (SPRITE_SIZE_Y * SPRITE_MULTIPLIER)) { //if automaton is overlapping with diver X
				//sets lives to 0 to end game if hit by automaton
				diver->setLives(0); 
				return true;
			}
		}
	}
	//if diver has not been hit
	return false;
}

//=====================================================
//description: 
// respawns diver (deletes and creates new diver)
//parameters:
// @diver - pointer to current diver
//return type:
// void
//=====================================================
void respawn(Diver*& diver) {
	//deletes current diver
	delete diver;
	//deploys new diver
	diver = new Diver();
	//useless loop pseudo pause -- really didn't want to deal with the sfml pause
	for (int i = 0; i <= PAUSE_NUMBER; i++) {
		//nothing
	}
	if (Diver::getLives() > 0) { //if player has lives left, gives updated lives on console
		cout << "Respawned" << endl;
		cout << "Lives: " << Diver::getLives() << endl << endl;
	}
}