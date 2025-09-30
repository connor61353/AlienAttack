#pragma once
#ifndef GAMEHEADER_H
#define GAMEHEADER_H

//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: gameHeader.h
// Description: Alien Attack game
// 
// Must be run in x86 
//=====================================================
#include <iostream>
#include <iomanip>
#include <string> 
#include <SFML/Graphics.hpp>
#include <list>
#include <chrono>
#include "windows.h"

//namespaces
using namespace sf;
using namespace std;

// Constants
const float DIVER_DISTANCE = 5.0f; // distance diver moves in one check
const float MISSILE_DISTANCE = 10.0f; //distance a missile can move in one check
const float AUTOMATON_DISTANCE_X = 5.0f; //x distance an automaton moves in one check
const float AUTOMATON_DISTANCE_Y = 10.0f; //y distance an automaton moves when at an edge
const int WINDOW_WIDTH = (473*1.3); // window is 800 pixels wide 473 x 667
const int WINDOW_HEIGHT = (667*1.3);// window is 600 pixels vertically "high"
const float WINDOW_MULTIPLIER = 1.3f; //multiplier for window
const int DIVER_BOUNDS = 15; //Diver can get this close to the window edge
const int SPRITE_MULTIPLIER = 3; //number that the enemy and player sprites are multiplied by
const int SPRITE_SIZE_X = 20; //size of the sprite image X (both automaton and diver)
const int SPRITE_SIZE_Y = 20; //size of the sprite image Y (both automaton and diver)
const int MISSILE_SIZE_X = 5; //size of missile sprite
const int MISSILE_SIZE_Y = 12; //size of missile sprite
const int ENEMY_MISSILE_MULTIPLIER = 2; //multiplier for enemy missiles
const int UNDEFINED_PIXIE = 1; //type number of undefined pixie
const int DIVER_PIXIE = 2; //type number of player pixie
const int AUTOMATON_PIXIE = 3; //type number of enemy pixie
const int MISSILE_PIXIE = 4; //type number of player missile pixie
const int BACKGROUND_PIXIE = 5; //type number of background pixie
const int DIVER_MISSLE_LIMIT = 5; //number of player missiles allowed on screen at any given point
const int CHANCE = 90; //chance that an automaton will fire a missile during a AutomatonAttack check
const int AUTOMATON_COUNT = 10; //number of automatons in a wave
const int PAUSE_NUMBER = 1000000000; //number of loop iterations the "pause" on player respawn

//classes
#include "Pixie.h"
class Pixie;
#include "Automaton.h"
class Automaton;
#include "Diver.h"
class Diver;
#include "Missile.h"
class Missile;
#include "Army.h"
class Army;

// Game Functions
void MissileOutOfBounds(list<Missile*>& missiles);
bool DiverHit(Diver* diver, list<Missile*>& missiles, list<Automaton*> army);
void respawn(Diver*& diver);
#endif // !GAMEHEADER_H