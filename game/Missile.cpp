//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: Missile.cpp
// Description: Alien Attack game
//=====================================================
#include "Missile.h"

//sets static int missileCount to default of 0
int Missile::missileCount = 0;

//=====================================================
//description: 
// missile constructor based on enemy or friendly missile sprite
//parameters:
// @pixie - pixie for missile, can be enemy or friendly
//return type:
// none
//=====================================================
Missile::Missile(Pixie* pixie, Diver* diver) {

	//slight adjustments to make guns on sprites shoot the missiles
	int playerMissileAdjustmentX = 5; //added to new player missile object X vals
	int enemyMissileAdjustmentX = 16; //added to new enemy missile object X vals
	int enemyMissileAdjustmentY = 11; //added to new enemy missile object Y vals

	if (pixie->getType() == DIVER_PIXIE) { //if player missile
		//sets missileMoveX to 0
		missileMoveX = 0.0f;
		//new player missile
		this->missile = new Pixie("missile.bmp", (pixie->getX() + (SPRITE_SIZE_X * SPRITE_MULTIPLIER) / 2) + playerMissileAdjustmentX, pixie->getY(), MISSILE_PIXIE);
		//player missile
		side = true;
		//adds 1 to missile count
		missileCount++; 
	}
	else if (pixie->getType() == AUTOMATON_PIXIE) { //if enemy missile
		float missileToDiverX = (diver->getDiver()->getX() + ((SPRITE_SIZE_X * SPRITE_MULTIPLIER) / 2)) - (pixie->getX() + ((SPRITE_SIZE_X * SPRITE_MULTIPLIER) / 2) - enemyMissileAdjustmentX); //distance from missile to diver Y
		float missileToDiverY = diver->getDiver()->getY() - (pixie->getY() + (SPRITE_SIZE_Y * SPRITE_MULTIPLIER) - enemyMissileAdjustmentY, MISSILE_PIXIE + (MISSILE_SIZE_Y + ENEMY_MISSILE_MULTIPLIER)); //distance from missile to diver Y
		missileMoveX = missileToDiverX / missileToDiverY; //how much the missile needs to move left or right to shoot at diver

		//new enemy missile
		this->missile = new Pixie("EnemyMissile.bmp", pixie->getX() + ((SPRITE_SIZE_X * SPRITE_MULTIPLIER) / 2) - enemyMissileAdjustmentX, pixie->getY() + (SPRITE_SIZE_Y * SPRITE_MULTIPLIER) - enemyMissileAdjustmentY, MISSILE_PIXIE);
		//scales up enemy missiles
		missile->setScale(ENEMY_MISSILE_MULTIPLIER, ENEMY_MISSILE_MULTIPLIER);
		//enemy missile
		side = false; 
	}
	else {
	}
}

//=====================================================
//description: 
// missile desconstructor - removes missile from missile count
//parameters:
// none
//return type:
// none
//=====================================================
Missile::~Missile() { 
	if (side) { //if player missile, removes 1 from missileCount
		missileCount--;
	}
}

//=====================================================
//description: 
// returns missile count
//parameters:
// none
//return type:
// int
//=====================================================
int Missile::getCount() { return missileCount; }

//=====================================================
//description: 
// moves missile up or down based on side (friendly or enemy)
//parameters:
// @pixie - pixie for missile, can be enemy or friendly
//return type:
// none
//=====================================================
void Missile::move() {
	if (side) { //player missile
		//moves up
		missile->move(0, -MISSILE_DISTANCE); 
	}
	else { //enemy missile
		//moves down
		missile->move(missileMoveX * MISSILE_DISTANCE, MISSILE_DISTANCE); 
	}
}