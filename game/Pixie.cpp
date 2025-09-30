//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: Pixie.cpp
// Description: Alien Attack game
//=====================================================

#include "gameHeader.h"
//=====================================================
//description: 
// default constructor
//parameters:
// none
//return type:
// none
//=====================================================
Pixie::Pixie() {
	nextPixie = nullptr;
	previousPixie = nullptr;
	nextPixieID = -1;
	myID = -1;
	pixieType = UNDEFINED_PIXIE;
}

//=====================================================
//description: 
// constructor with indicated values
//parameters:
// @textureName - file name of texture
// @xloc - y location for pixie
// @yloc - x location for pixie
// @type - type of pixie
//return type:
// none
//=====================================================
Pixie::Pixie(string textureName, float xloc, float yloc, int type) {
	tex.loadFromFile(textureName);
	nextPixie = nullptr;
	previousPixie = nullptr;
	nextPixieID = -1;
	myID = -1;
	pixieType = type;
	spri.setTexture(tex);
	spri.setPosition(xloc, yloc);

}


//required line
int Pixie::nextPixieID = 0;