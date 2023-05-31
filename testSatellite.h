#pragma once

/***********************************************************************
 * Header File:
 *    Test Satellite : Test the Satellite class
 * Author:
 *    Carlos, Hunter, and Jake
 * Summary:
 *    All the unit tests for satellite
 ************************************************************************/


#pragma once

#include <iostream>
#include "position.h"
#include "satellite.h"
#include "velocity.h"
#include <cassert>

using namespace std;

/*******************************
 * TEST Satellite
 * A friend class for Satellite which contains the Satellite unit tests
 ********************************/

class TestSatellite
{

public:

	/*******************************************
	* RUN
	* runs all the tests
	*******************************************/

	void run()
	{

		test_noneDefaultConstructor();
		test_defaultConstructor();
		test_copyConstructor();
		test_getRadius();
		test_isDead_is_not_dead();
		test_isDead_is_dead();
		test_getPosition();
		test_kill();
		test_destroy();
		test_move();

	};

	/*******************************************
	* TEST NONE DEFAULT CONSTRUCTOR
	* a function that initiates the a Satellite with the non-default constructor.
	*******************************************/


	void test_noneDefaultConstructor() {

		//Setup

		Position position(2345, 2345);
		Velocity velocity(2345, 2345);
		Direction direction;

		//Exercise
		Satellite satellite(position, velocity, direction);

		//Verify
		assert(satellite.position.getMetersX() == 2345);
		assert(satellite.position.getMetersY() == 2345);
		assert(satellite.velocity.getDx() == 2345);
		assert(satellite.direction.getRadians() == 0.0);

		//Teardown
	};

	/*******************************************
	* TEST DEFAULT CONSTRUCTOR
	* a function that initiates the a Satellite with the default constructor.
	*******************************************/


	void test_defaultConstructor() {

		//No Setup

		//Exercise
		Satellite satellite;

		//Verify
		assert(satellite.position.getMetersX() == 0);
		assert(satellite.position.getMetersY() == 0);
		assert(satellite.velocity.getDx() == 0);
		assert(satellite.velocity.getDy() == 0);
		assert(satellite.direction.getRadians() == Direction().getRadians());
		assert(satellite.dead == false);


		//Teardown
		
	};

	/*******************************************
	* TEST COPY CONSTRUCTOR
	* a function that initiates the a Satellite when given another Satellite as a parameter.
	*******************************************/


	void test_copyConstructor() {

		//Setup
		Satellite satellite1(Position(2345, 2345), Velocity(2345, 2345), Direction());

		//Exercise
		Satellite satellite2(satellite1);

		//Verify
		assert(satellite2.position.getMetersX() == satellite1.position.getMetersX());
		assert(satellite2.position.getMetersY() == satellite1.position.getMetersY());
		assert(satellite2.velocity.getDx() == satellite1.velocity.getDx());
		assert(satellite2.velocity.getDy() == satellite1.velocity.getDy());
		assert(satellite2.direction.getRadians() == satellite1.direction.getRadians());

		//Teardown
		
	};

	/*******************************************
	* TEST GETTING THE SATELLITE'S RADIUS
	* a function that test if the getRadius method works for a Satellite object.
	*******************************************/


	void test_getRadius()
	{
		//Setup
		Satellite satellite;

		//Exercise
		double radius = satellite.getRadius();

		//Verify
		assert(radius == satellite.radius);

		//Teardown
		
	};

	/*******************************************
	* TEST ASKING A SATELLITE IF IT'S DEAD WHEN ITS ALIVE
	* a function that test asking a satellite if its dead
	*******************************************/

	void test_isDead_is_not_dead() 
	{	
		//Setup
		Satellite satellite;

		//Exercise
		bool isDead = satellite.isDead();

		//Verify
		assert(isDead == false);

		//Teardown
		
	};

	/*******************************************
	* TEST ASKING A SATELLITE IF IT'S DEAD WHEN ITS DEAD
	* a function that test asking a satellite if its dead
	*******************************************/

	void test_isDead_is_dead() {
		
		//Setup
		Satellite satellite;
		satellite.dead = true;

		//Exercise
		bool isDead = satellite.isDead();

		//Verify
		assert(isDead = true);

		//Teardown
		
	};

	/*******************************************
	* TEST ASKING A SATELLITE FOR ITS POSITION
	* a function that test asking a satellite for its position coordinates
	*******************************************/


	void test_getPosition() {

		//Setup
		Satellite satellite;

		//Exercise
		Position position = satellite.getPosition();

		//Verify
		assert(position.getMetersX() == satellite.position.getMetersX());
		assert(position.getMetersY() == satellite.position.getMetersY());

		//Teardown
		
	};

	/*******************************************
	* TEST KILLING A SATELLITE OBJECT
	* a function that test setting the satellite's dead attribute to false
	*******************************************/


	void test_kill() {

		//Setup
		Satellite satellite;
		satellite.dead = false;

		//Exercise
		satellite.kill();

		//Verify
		assert(satellite.dead == true);

		//Teardown
		

	};


	/*******************************************
	* TEST DESTROYING THE SATELLITE AND SPAWNING FRAGMENTS FROM THE SATELLITE'S POSITION
	* a function that test spawning fragments on a dead satellite's position
	*******************************************/

		void test_destroy() {

		//Setup
		Satellite satellite;

		Satellite fragment1;
		Satellite fragment2;
		Satellite fragment3;
		vector<Satellite*> fragments;
		fragments.push_back(&fragment1);
		fragments.push_back(&fragment2);
		fragments.push_back(&fragment3);

		vector<Satellite*> fragmentsToAdd;

		//Exercise
		satellite.destroy(fragments, fragmentsToAdd);

		//Verify

		assert(fragment1.position.getMetersX() == satellite.position.getMetersX());
		assert(fragment1.position.getMetersY() == satellite.position.getMetersY());
		assert(fragment2.position.getMetersX() == satellite.position.getMetersX());
		assert(fragment2.position.getMetersY() == satellite.position.getMetersY());
		assert(fragment3.position.getMetersX() == satellite.position.getMetersX());
		assert(fragment3.position.getMetersY() == satellite.position.getMetersY());
		

		//Teardown
		

	};


	/*******************************************
	* TEST UPDATING THE SATELLITE'S POSITION AND VELOCITY
	* a function that test updating the satellite's position.
	*******************************************/


	void test_move() {

		//Setup
		Satellite satellite(Position(6379000.0, 6379000.0 ), Velocity(2345, 2345), Direction());
		int timeFrame = 48;

		//Exercise
		/*
			* direction of gravity: pi / 4
			* height: 2,643,268.314377973
			* acceleration: -4.90181277922411666778
			*	ddx: -3.466105056296249853
			*	ddy: -3.466105056296249853
			* velocity:
			*	dx: 2,178.6269572977800
			*	dy: 2,178.6269572977800
			* position:
			*	x: 6,483,574.093950
			*	y: 6,483,574.093950
		*/
		satellite.move(timeFrame);

		//Verify
		assert(satellite.position.getMetersX() <= 6483574.093951
			&& satellite.position.getMetersX() >= 6483574.093949);

		assert(satellite.position.getMetersY() <= 6483574.093951
			&& satellite.position.getMetersY() >= 6483574.093949);

		//Teardown
		
	};

};