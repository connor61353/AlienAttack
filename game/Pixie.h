#pragma once
//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: Pixie.h
// Description: Alien Attack game
//=====================================================
#ifndef PIXIE_H
#define PIXIE_H
#include "gameHeader.h"

//=====================================================
//description: 
// class for all on-screen objects that need to be drawn
//=====================================================
class Pixie {
public:
	Pixie();
	Pixie(string textureName, float xloc, float yloc, int type);
//=====================================================
//description: 
// draws pixie
//parameters:
// @window
//return type:
// void
//=====================================================
	void draw(RenderWindow& window) { window.draw(spri); };
//=====================================================
//description: 
// moves pixie
//parameters:
// @x - new x location
// @y - new y location
//return type:
// void
//=====================================================
	void move(float x, float y){ spri.move(x, y); }
//=====================================================
//description: 
// sets scale of pixie
//parameters:
// @xScale - scale of x
// @yScale - scale of y
//return type:
// void
//=====================================================
	void setScale(float xScale, float yScale) { spri.setScale(xScale, yScale); }
//=====================================================
//description: 
// sets new position of pixie
//parameters:
// @x - new x value
// @y - new y value
//return type:
// void
//=====================================================
	void setPosition(float x, float y) { spri.setPosition(x, y); }
//=====================================================
//description: 
// returns pixie x
//parameters:
// none
//return type:
// float
//=====================================================
	float getX() { return spri.getPosition().x; }
//=====================================================
//description: 
// returns pixie y
//parameters:
// none
//return type:
// float
//=====================================================
	float getY() { return spri.getPosition().y; }
//=====================================================
//description: 
// returns pixie sprite
//parameters:
// none
//return type:
// Sprite
//=====================================================
	Sprite getSprite() { return spri; }
//=====================================================
//description: 
// returns pixie texture
//parameters:
// 
//return type:
// Texture
//=====================================================
	Texture getTexture() { return tex; }
//=====================================================
//description: 
// returns pixie id
//parameters:
// none
//return type:
// int
//=====================================================
	int getID() { return myID; }
//=====================================================
//description: 
// returns pixie type
//parameters:
// none
//return type:
// int
//=====================================================
	int getType() { return pixieType; }
//=====================================================
//description: 
// returns next pixie
//parameters:
// none
//return type:
// Pixie*
//=====================================================
	Pixie* getNext() { return nextPixie; }
//=====================================================
//description: 
// returns previous pixie
//parameters:
// none
//return type:
// Pixie*
//=====================================================
	Pixie* getPrevious() { return previousPixie; }
//=====================================================
//description: 
// returns current pixie
//parameters:
// none
//return type:
// Pixie*
//=====================================================
	Pixie* getSelfPointer() { return this; }
//=====================================================
//description: 
// sets new pixie type
//parameters:
// @type - new type
//return type:
// void
//=====================================================
	void setType(int type) { pixieType = type; }
//=====================================================
//description: 
// sets new x value
//parameters:
// @x - new x
//return type:
// void
//=====================================================
	void setX(float x) { spri.setPosition(x, spri.getPosition().y); }
//=====================================================
//description: 
// sets new y value
//parameters:
// @y - new y
//return type:
// void
//=====================================================
	void setY(float y) { spri.setPosition(spri.getPosition().x, y); }
//=====================================================
//description: 
// sets new pixie texture
//parameters:
// @filename - name of the new texture file
//return type:
// void
//=====================================================
	void setTextureSourceFile(string filename) { tex.loadFromFile(filename); }

private:
	Texture tex; //texture of pixie
	Sprite spri; //sprite of pixie
	Pixie* nextPixie; //next pixie
	Pixie* previousPixie; //previous pixie
	static int nextPixieID; //next pixie
	int myID; //id of current pixie
	int pixieType; //type of pixie
};


#endif