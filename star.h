#pragma once


#include "position.h"
#include <cstdlib>
#include "uiDraw.h"  // For using random number generator & draw function



class Star
{

public:

	// Determines brightness of the star.
	int phase;

	// X and Y coordinates of the star.
	Position position;


	// Default constructor.
	Star() {

		// Sets brightness of the star to a random value from 0 - 254
		this->phase = random(1, 253);

		// Sets a random position for the star.

		this->position.setPixelsX(random(-500, 500));
		this->position.setPixelsY(random(-500, 500));
	}

	/*******************************
	 * INCREMENT PHASE
	 * Increases the phase (brightness of the star) by 1. If it reaches maximum brightness, it resets the phase.
	 ********************************/
	void incrementPhase() {

		// Increment phase by 1 if under 254.
		if (this->phase < 254)
		{
			this->phase++;
		}

		// Resets the star's phase if it has rech maximum brightness.
		else
		{

			/*We don't want the star to suddenly go dim after being at max brightness.
			Star value will be switched to negative. When drawing the brightness,
			we only want to look at the absolute value. */
			this->phase = -254;
		}
	}

	/*******************************
	 * GET PHASE
	 * Returns the current phase (brightness of the star).
	 ********************************/
	int getPhase() {
		return abs(this->phase);
	}

	/*******************************
	 * DRAW
	 * Displays the star on screen in its specified position and with its corresponding brightness.
	 ********************************/
	void draw() {
		drawStar(this->getPosition(), this->getPhase());
	}


	/*******************************
	 * GET POSITION
	 * Returns the star's current position.
	 ********************************/
	Position getPosition() {
		return this->position;
	}

};