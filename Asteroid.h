//
//  Asteroid.h
//
//  A module to represent an asteroid in the game.
//

#pragma once

#include "Buffer.h"
#include "Rectangle.h"


//
//  Asteroid
//
//  A class to represent an asteroid in the game.
//
//  Class Invarint:
//    <1> row_count    >= 1
//    <2> column_count >= 1
//    <3> ore_value == ORE_VALUE_DEAD ||
//        (ore_value >= ORE_VALUE_MIN &&
//                                   ore_value <  ORE_VALUE_MAX)
//
class Asteroid :public Rectangle
{
public:
	//
	//  Default Constructor
	//
	//  Purpose: To create a new Asteroid with default values.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: A new Asteroid is created at position
	//               (row = 0, column = 0) with a random legal ore
	//               value.
	//
	Asteroid();

	//
	//  getOreValue
	//
	//  Purpose: To determine the ore value of this Asteroid.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: The ore value.
	//  Side Effect: N/A
	//
	unsigned int getOreValue() const;

	//
	//  isDead
	//
	//  Purpose: To determine whether this Asteroid is dead.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: Whether this Asteroid is dead.
	//  Side Effect: N/A
	//
	bool isDead() const;

	//
	//  draw
	//
	//  Purpose: To display this Asteroid.
	//  Parameter(s):
	//    <1> buffer: The Buffer to draw this Asteroid to
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: This Asteroid is drawn to Buffer buffer.
	//               The ore value is displayed.
	//
	void draw(Buffer& buff) const;

	//
	//  randomizeOreValue
	//
	//  Purpose: To change this Asteroid to have a new random ore
	//           value.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: This Asteroid is set to have a random legal ore
	//               value.  This Asteroid is marked as not dead.
	//
	void randomizeOreValue();

	//
	//  markDead
	//
	//  Purpose: To mark this Asteroid as dead.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: This Asteroid is marked as dead.
	//
	void markDead();

private:
	//
	//  getRandomOreValue
	//
	//  Purpose: To calculate a legal ore value for an Asteroid.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: A random ore value that an asteroid could have.
	//  Side Effect: N/A
	//
	unsigned int getRandomOreValue() const;

	//
	//  invariant
	//
	//  Purpose: To determine if the class invariant is true.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: Whether the class invariant is true.
	//  Side Effect: N/A
	//
	bool invariant() const;

private:
	unsigned int ore_value;
};

//
//  asteroidLoadImage
//
//  Purpose: To load the image used to display Asteroids.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The asteroid image is loaded.  If anything goes
//               wrong, an error message is printed.
//
void asteroidLoadImage();