#pragma once
#ifndef DIVER_H
#define DIVER_H
//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: Diver.h
// Description: Alien Attack game
//=====================================================
#include "gameHeader.h"

//=====================================================
//description: 
// class for diver objects (player)
//=====================================================
class Diver {
public:
	Diver();
	//=====================================================
	//description: 
	// Diver deconstructor - removes a life if deleted
	//parameters:
	// none
	//return type:
	// none
	//=====================================================
	~Diver() { lives--; }
	void move();
	//=====================================================
	//description: 
	// returns diver pixie
	//parameters:
	// none
	//return type:
	// Pixie*
	//=====================================================
	Pixie* getDiver() { return diver; }
	//=====================================================
	//description: 
	// returns diver lives
	//parameters:
	// none
	//return type:
	// int
	//=====================================================
	static int getLives() { return lives; }
	//=====================================================
	//description: 
	// sets diver lives
	//parameters:
	// @lives - number of lives to set
	//return type:
	// void
	//=====================================================
	void setLives(int lives) {
		this->lives = lives;
	}



private:
	Pixie* diver; //diver sprite
	static int lives; //current number of player lives
	static const float DiverX; //preset player spawn location X
	static const float DiverY; //preset player spawn location Y

};
#endif // !DIVER_H