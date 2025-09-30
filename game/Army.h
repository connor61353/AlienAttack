#pragma once
#ifndef ARMY_H
#define ARMY_H
//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: Army.h
// Description: Alien Attack game
//=====================================================
#include "gameHeader.h"

//=====================================================
//description: 
// list class for automaton army
//=====================================================
class Army {
public:
	Army();
	void AutomatonHit(list<Missile*>& missiles);
	void AutomatonAttack(list<Missile*>& missiles, Diver* diver);
	void move();
	//=====================================================
	//description: 
	// returns army pixie
	//parameters:
	// none
	//return type:
	// list<Automaton*>
	//=====================================================
	list<Automaton*> getArmy() { return army; }
private:
	list<Automaton*> army; //list of all automatons
};
#endif // !ARMY_H