//
//  Player.h
//
//  A module to represent the player ship in the game.
//

#pragma once

#include "Buffer.h"
#include "Rectangle.h"

//  Class Invarint:
//    <1> shield_strength <= MAX_SHIELD_STRENGTH
//
class Player :public Rectangle
{
public:
	Player();
	unsigned int getOreCollected() const;
	bool isDead() const;
	double getShieldStrengthFraction() const;
	void draw(Buffer& buff) const;
	void increaseOreCollected(unsigned int amount);
	void reduceShieldStrength(int amount);
	void update();

private:
	bool invariant() const;

private:
	int shield_strength;
	unsigned int ore_collected;
};

void playerLoadImage();