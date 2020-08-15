//
//  Player.cpp
//

#include <cassert>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

#include "Buffer.h"
#include "Player.h"
#include "Rectangle.h"

using namespace std;

static const int ROW_COUNT = 4;
static const int COLUMN_COUNT = 9;

static const int MAX_SHIELD_STRENGTH = 50;

static char image[ROW_COUNT][COLUMN_COUNT];

Player::Player() :Rectangle(0,0,ROW_COUNT,COLUMN_COUNT)
{
	shield_strength = MAX_SHIELD_STRENGTH;
	ore_collected = 0;

	assert(invariant());
}

unsigned int Player::getOreCollected() const
{
	assert(invariant());

	return ore_collected;
}

bool Player::isDead() const
{
	assert(invariant());

	if (shield_strength <= 0)
		return true;
	else
		return false;
}

double Player::getShieldStrengthFraction() const
{
	assert(invariant());

	if (shield_strength <= 0)
		return 0.0;
	else
		return (double)(shield_strength) / (double)(MAX_SHIELD_STRENGTH);
}

void Player::draw(Buffer& buff) const
{
	assert(invariant());

	for (int r = 0; r < ROW_COUNT; r++)
	{
		for (int c = 0; c < COLUMN_COUNT; c++)
		{
			int draw_row = getMinRow() + r;
			int draw_column = getMinColumn() + c;
			buff.setCell(draw_row, draw_column, image[r][c]);
		}
	}
}

void Player::increaseOreCollected(unsigned int amount)
{
	assert(invariant());

	ore_collected += amount;

	assert(invariant());
}

void Player::reduceShieldStrength(int amount)
{
	assert(invariant());

	shield_strength -= amount;

	assert(invariant());
}

void Player::update()
{
	assert(invariant());

	if (shield_strength < MAX_SHIELD_STRENGTH)
		shield_strength++;

	assert(invariant());
}

bool Player::invariant() const
{
	if (shield_strength > MAX_SHIELD_STRENGTH)
	{
		return false;
	}
	else
	{
		return true;
	}
};

void playerLoadImage()
{
	static const string FILENAME = "player.txt";

	for (int r = 0; r < ROW_COUNT; r++)
	{
		for (int c = 0; c < COLUMN_COUNT; c++)
		{
			image[r][c] = '?';
		}
	}

	// open file
	ifstream fin(FILENAME.c_str());
	if (!fin)
	{
		cout << "Error: Cannot open file \"" << FILENAME << "\"" << endl;
		return;   // give up, use default image
	}

	// load image
	for (int r = 0; r < ROW_COUNT; r++)
	{
		string line;
		getline(fin, line);

		// check that enough characters were read
		if (line.size() < COLUMN_COUNT)
		{
			cout << "Error: Not enough characters on line " << r << " of file \"" << FILENAME << "\"" << endl;
			return;   // give up, some of default image may be visible
		}

		// copy line into image
		for (int c = 0; c < COLUMN_COUNT; c++)
		{
			image[r][c] = line[c];
		}
	}
}