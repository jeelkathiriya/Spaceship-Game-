//
//  Asteroid.h
//

#include <cassert>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

#include "Buffer.h"
#include "Asteroid.h"
#include "Rectangle.h"

using namespace std;

static const int ROW_COUNT = 3;
static const int COLUMN_COUNT = 4;

static const unsigned int ORE_VALUE_DEAD = 0;
static const unsigned int ORE_VALUE_MIN = 10;
static const unsigned int ORE_VALUE_MAX = 100;
static const unsigned int ORE_VALUE_RANGE = ORE_VALUE_MAX - ORE_VALUE_MIN;

static char image[ROW_COUNT][COLUMN_COUNT];

Asteroid::Asteroid() :Rectangle(0, 0, ROW_COUNT, COLUMN_COUNT)
{
	ore_value = getRandomOreValue();

	assert(invariant());
}

unsigned int Asteroid::getOreValue() const
{
	assert(invariant());

	return ore_value;
}

bool Asteroid::isDead() const
{
	assert(invariant());

	if (ore_value == ORE_VALUE_DEAD)
		return true;
	else
		return false;
}

void Asteroid::draw(Buffer& buff) const
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

	int digit_row = getMinRow() + 1;
	int digit_column = getMinColumn() + 1;
	char digit_tens = '0' + ore_value / 10;
	char digit_ones = '0' + ore_value % 10;
	buff.setCell(digit_row, digit_column, digit_tens);
	buff.setCell(digit_row, digit_column + 1, digit_ones);
}

void Asteroid::randomizeOreValue()
{
	assert(invariant());

	ore_value = getRandomOreValue();

	assert(invariant());
}

void Asteroid::markDead()
{
	assert(invariant());

	ore_value = ORE_VALUE_DEAD;

	assert(invariant());
}

unsigned int Asteroid::getRandomOreValue() const
{
	return ORE_VALUE_MIN + rand() % ORE_VALUE_RANGE;
}

bool Asteroid::invariant() const
{
	if (!(ore_value == ORE_VALUE_DEAD ||
		(ore_value >= ORE_VALUE_MIN && ore_value < ORE_VALUE_MAX)))
	{
		return false;
	}
	return true;
};

void asteroidLoadImage()
{
	static const string FILENAME = "asteroid.txt";

	for (int r = 0; r < ROW_COUNT; r++)
	{
		for (int c = 0; c < COLUMN_COUNT; c++)
		{
			image[r][c] = '?';
		}
	}

	ifstream fin(FILENAME.c_str());
	if (!fin)
	{
		cout << "Error: Cannot open file \"" << FILENAME << "\"" << endl;
		return;
	}

	for (int r = 0; r < ROW_COUNT; r++)
	{
		string line;
		getline(fin, line);

		if (line.size() < COLUMN_COUNT)
		{
			cout << "Error: Not enough characters on line " << r << " of file \"" << FILENAME << "\"" << endl;
			return;
		}

		for (int c = 0; c < COLUMN_COUNT; c++)
		{
			image[r][c] = line[c];
		}
	}
}
