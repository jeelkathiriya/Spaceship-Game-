//
//  Game.h
//
//  A module to serve an intermediate layer between Main and
//  the Buffer, PLayer and the Asteroid
//

#pragma once

#include "Buffer.h"
#include "Player.h"
#include "Asteroid.h"

const unsigned int ASTEROID_COUNT = 10;
class Game 
{
public:
	Player player;
	Asteroid asteroid[ASTEROID_COUNT];
	int scroll_distance;

	//
	//  Default Constructor
	//
	//  Purpose: To allot player and asteroid position
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: Set Player a1 row 10 and column 1 and
	//                Set Asteroids at random rows and column 
	//
	Game();

	//
	//  isOver
	//
	//  Purpose: To determine whether the Game is Over.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: Whether the game is over.
	//  Side Effect: N/A
	//
	bool isOver()const;

	//
	//  drawAll
	//
	//  Purpose: To display initial or starting stage of the game.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: This Player and Asteroids is drawn to Buffer buffer.
	//               The Player status line is printed in the bottom.
	//
	void drawAll()const;

	//
	//  moveStraight
	//
	//  Purpose: To move the Player forward by specified offset.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: Increment the column coordinate for the Player 
	//
	void moveStraight();

	//
	//  moveUp
	//
	//  Purpose: To move the Player upword by specified offset.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: if The Player is not in the uppermost row 
	//                   then decrement the player row coordinate  Or 
	//                else increment the column coordinate.
	//
	void moveUp();

	//
	//  moveDown
	//
	//  Purpose: To move the Player Downward by specified offset.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: if The Player is not occupying the bottommost row  
	//                    then increment the row coordinate, Or 
	//                else increment the column coordinate.
	void moveDown();
	
private:

	//
	//  isCollision
	//
	//  Purpose: To determine whether the Player and Asteroid is dead.
	//  Parameter(s): 
	//    <1> Player: Takes const reference to a Player
	//    <2> Asteroid: Takes const reference to a Asteroid
	//  Precondition(s): N/A
	//  Returns: Whether the Player and Asteroid is dead.
	//            If neither is dead then check for further collision.
	//  Side Effect: N/A
	//
	bool isCollision(Player& player, Asteroid& asteroid)const;

	//
	//  printStatusBar
	//
	//  Purpose: Calculates the contents of Player Status Bar
	//  Parameter(s): 
	//    <1> length: Length of the bar
	//    <2> fraction_full: Fractional part of the bar that need to be displayed. 
	//  Precondition(s): The length should be >= than 2.
	//  Returns: N/A
	//  Side Effect: Calculates the shiled strength 
	//                Calculates the Power
	//
	void printStatusBar(unsigned int length, double fraction_full)const;

	//
	//  printPlayerStatusRow
	//
	//  Purpose: Prints Player status in status bar
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: Displaying the Shield strength as a fraction
	//               Displaying the full bar for Power
	//               Displaying the amount of ore collected with leading zero
	//
	void printPlayerStatusRow()const;

	//
	//  updateMoves
	//
	//  Purpose: Always perform the calculations after the player moves 
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: Increment the scroll distance.
	//               For asteroid handle collision with player.
	//               Checks for asteroid oving off the screen left.
	//               Restart asteroid off the screen right.
	//
	void updateMoves();
};

//
//  LoadAllImage
//
//  Purpose: To load the image used to display Player and Asteroids.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The player and asteroid image is loaded.  If anything goes
//               wrong, an error message is printed.
//
void gameLoadAllImages();