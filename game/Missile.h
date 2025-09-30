#pragma once
#ifndef MISSILE_H
#define MISSILE_H
//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: Missile.h
// Description: Alien Attack game
//=====================================================
#include "gameHeader.h"

//=====================================================
//description: 
// class for missile objects
//=====================================================
class Missile {
public:
	Missile(Pixie* pixie, Diver* diver);
	~Missile();
	static int getCount();
	//=====================================================
	//description: 
	// returns missile pixie
	//parameters:
	// none
	//return type:
	// Pixie*
	//=====================================================
	Pixie* getMissile() { return missile; }
	void move();
private:
	Pixie* missile; //missile pixie
	static int missileCount; //number of missiles on screen
	float missileMoveX; //distance a missile needs to move left or right to hit diver
	bool side; //side missile is for, true = player missile, false = enemy missile
};
#endif // !MISSILE_H
