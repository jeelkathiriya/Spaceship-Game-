//
//  Main.cpp
//
//  Assignment 4 for CS 115
//
//  Name:  JEEL KATHIRIYA
//  Student Number:  200420063
//

#include <string>
#include <iostream>
#include <iomanip>

#include "Buffer.h"
#include "Player.h"
#include "Asteroid.h"
#include "Game.h"

using namespace std;

int main();

int main()
{
	Game active_game;
	Game saved_game;

	//game = saved_game;
	
	gameLoadAllImages();

	// set up game variables
	active_game.scroll_distance = 0;

	// main loop
	char input = ' ';
	while (input != 'q')
	{
		// display the game state
		active_game.drawAll();
		// read input

		cout << "Next? ";

		string line;
		getline(cin, line);

		// use either one of these lines
		//for(unsigned int i = 0; i < 1; i++)  // process only first input char
		for (unsigned int i = 0; i < line.size(); i++)  // process all input
		{
			input = line[i];

			// handle input
			switch (input)
			{
			case 'w':
				active_game.moveUp();
				break;
			case 's':
				active_game.moveStraight();
				break;
			case 'x':
				active_game.moveDown();
				break;
			case'r':
				saved_game = active_game;;
				cout << "Game Saved" << endl;
				break;
			}

			// perform updates

			if (active_game.isOver())
			{
				active_game = saved_game;

				cout << "Game Restrored" << endl;
			}
		}
	}

	return 0;
}
