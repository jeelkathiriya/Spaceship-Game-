//
//  Game.cpp
//
//  Assignment 4 for CS 115
//
//  Name:  JEEL KATHIRIYA
//  Student Number:  200420063
//

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>

#include "Asteroid.h"
#include "Buffer.h"
#include "Game.h"

using namespace std;

Game::Game()
{
	player.setPosition(10, 1);

	for (unsigned int i = 0; i < ASTEROID_COUNT; i++)
	{
		int new_row = rand() % (BUFFER_ROW_COUNT - asteroid[i].getRowCount());
		int new_column = 20 + rand() % (BUFFER_COLUMN_COUNT * 2);
		asteroid[i].setPosition(new_row, new_column);
	}

	scroll_distance = 0;
}

bool Game::isCollision(Player & player1, Asteroid & asteroid1) const
{
	if (player1.isDead())
		return false;
	if (asteroid1.isDead())
		return false;


	if (asteroid1.isIntersection(player1) == true)
		return true;

	return false;
}

void Game::printStatusBar(unsigned int length, double fraction_full) const
{
	assert(length >= 2);

	cout << "|";

	unsigned int bar_length = length - 2;
	unsigned int first_empty = (unsigned int)(bar_length * fraction_full);
	for (unsigned int i = 0; i < bar_length; i++)
	{
		if (i < first_empty)
			cout << "*";
		else
			cout << "-";
	}

	cout << "|";
}

void Game::printPlayerStatusRow() const
{
	cout << " Shields ";
	printStatusBar(22, player.getShieldStrengthFraction());
	cout << "   Power ";
	printStatusBar(7, 1.0);
	cout << "   Ore: ";
	cout << setw(6) << setfill('0') << player.getOreCollected();
	cout << endl;
}

void Game::drawAll()const
{
	Buffer buffer;

	buffer.clear();

	buffer.setOffset(0, scroll_distance);

	player.draw(buffer);

	for (unsigned int i = 0; i < ASTEROID_COUNT; i++)
	{
		asteroid[i].draw(buffer);
	}

	buffer.print();

	printPlayerStatusRow();
}

void Game::updateMoves()
{
	scroll_distance++;

	player.update();

	for (unsigned int i = 0; i < ASTEROID_COUNT; i++)
	{
		if (isCollision(player, asteroid[i]))
		{
			player.increaseOreCollected(asteroid[i].getOreValue());
			player.reduceShieldStrength(asteroid[i].getOreValue());
			asteroid[i].markDead();
		}

		if (asteroid[i].getMaxColumn() < scroll_distance)
		{
			asteroid[i].markDead();
		}

		if (asteroid[i].isDead())
		{
			asteroid[i].randomizeOreValue();

			int new_row = rand() % (BUFFER_ROW_COUNT - asteroid[i].getRowCount());
			int new_column = BUFFER_COLUMN_COUNT + scroll_distance;
			asteroid[i].setPosition(new_row, new_column);
		}
	}
}

void Game::moveStraight()
{
	player.addPosition(0, 1);

	updateMoves();
}

void Game::moveUp()
{
	if (player.getMinRow() - 1 >= 0)
	{
		player.addPosition(-1, 1);
	}
	else
	{
		player.addPosition(0, 1);
	}

	updateMoves();
}

void Game::moveDown()
{
	if (player.getMaxRow() + 1 < BUFFER_ROW_COUNT)
	{
		player.addPosition(1, 1);
	}
	else
	{
		player.addPosition(0, 1);
	}

	updateMoves();
}



bool Game::isOver()const
{
	bool over = false;

		if (player.isDead())
		{
			over = true;
		}
		else
		{
			return over;
		}
}

void gameLoadAllImages()
{
	playerLoadImage();
	asteroidLoadImage();
}