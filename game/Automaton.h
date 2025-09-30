#pragma once
#ifndef AUTOMATON_H
#define AUTOMATON_H
//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: Automaton.h
// Description: Alien Attack game
//=====================================================
#include "gameHeader.h"

//=====================================================
//description: 
// class for automaton objects (enemy)
//=====================================================
class Automaton {
public:
	Automaton(float Xoffset);
	void move();
	//=====================================================
	//description: 
	// returns automaton pixie
	//parameters:
	// none
	//return type:
	// Pixie*
	//=====================================================
	Pixie* getAutomaton() {
		return automaton;
	}

private:
	Pixie* automaton; //automaton sprite
	bool direction; //direction automaton will move, true = right, false = left
	static const float AutomatonX; //preset player spawn location X
	static const float AutomatonY; //preset player spawn location Y
};
#endif // !AUTOMATON_H