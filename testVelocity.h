/***********************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Carlos, Hunter, and Jake
 * Summary:
 *    All the unit tests for satellite
 ************************************************************************/




#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "velocity.h"
#include <cassert>
using namespace std;

/*******************************************
* TEST VELOCITY
* a test class that tests the velocity class
*******************************************/
class TestVelocity
{
public:
	/*******************************************
	* RUN
	* runs all the tests
	*******************************************/
	void run()
	{
		// test getDx
		testGetDx_negativeVal();
		testGetDx_0Val();
		testGetDx_positiveVal();

		// test getDy
		testGetDy_negativeVal();
		testGetDy_0Val();
		testGetDy_positiveVal();

		// test setDx
		testSetDx_negativeVal();
		testSetDx_0Val();
		testSetDx_positiveVal();

		// test setDy
		testSetDy_negativeVal();
		testSetDy_0Val();
		testSetDy_positiveVal();

		// test assign
		testAssign_BothPos();
		testAssign_BothNeg();
		testAssign_PosDX_NegDY();
		testAssign_NegDX_PosDY();
		testAssign_Both0();

		// test getSpeed
		testGetSpeed_0DX_0DY();
		testGetSpeed_0DX_NegDY();
		testGetSpeed_0DX_PosDY();
		testGetSpeed_PosDX_0DY();
		testGetSpeed_PosDX_NegDY();
		testGetSpeed_PosDX_PosDY();
		testGetSpeed_NegDX_0DY();
		testGetSpeed_NegDX_NegDY();
		testGetSpeed_NegDX_PosDY();
		
		// test getDirection
		testGetDirection_0DX_0DY();
		testGetDirection_0DX_NegDY();
		testGetDirection_0DX_PosDY();
		testGetDirection_NegDX_0DY();
		testGetDirection_NegDX_NegDY();
		testGetDirection_NegDX_PosDY();
		testGetDirection_PosDX_0DY();
		testGetDirection_PosDX_NegDY();
		testGetDirection_PosDX_PosDY();
		
		// test addDx
		testAddDx_0Val();
		testAddDx_NegVal();
		testAddDx_PositiveVal();

		// test addDy
		testAddDy_0Val();
		testAddDy_NegVal();
		testAddDy_PositiveVal();

		// test addVel
		testAddVel_0Val();
		testAddVel_NegVal();
		testAddVel_PosVal();

		// test setSpeedDirection
		testSetSpeedDirection_0Rad();
		testSetSpeedDirection_PiFourthsRad();
		testSetSpeedDirection_PiHalvesRad();
		testSetSpeedDirection_ThreePiFourthsRad();
		testSetSpeedDirection_PiRad();
		testSetSpeedDirection_FivePiFourthsRad();
		testSetSpeedDirection_ThreePiHalvesRad();
		testSetSpeedDirection_SevenPiFourthsRad();
		testSetSpeedDirection_0Speed();
		testSetSpeedDirection_PosSpeed();
		testSetSpeedDirection_NegSpeed();

	};

	/*******************************************
	* SETUP
	* a function that simplifies the setup for tests
	*******************************************/
	Velocity setup()
	{
		Velocity vel;
		vel.dx = 0.0;
		vel.dy = 0.0;
		return vel;
	};

	/*******************************************
	* TEAR-DOWN
	* a function that simplifies the tear-down for tests
	*******************************************/
	void teardown(Velocity& vel)
	{
		vel.~Velocity();
	};

	/*******************************************
	* TEST GET DX NEGATIVE VAL
	* test getDx when dx is negative
	*******************************************/
	void testGetDx_negativeVal()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = -10.0;

		// exercise
		double dx = testVel.getDx();

		// verify
		assert(dx == -10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DX 0 VAL
	* test getDx when dx is 0
	*******************************************/
	void testGetDx_0Val()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		double dx = testVel.getDx();

		// verify
		assert(dx == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DX POSITIVE VAL
	* test getDx when dx is positive
	*******************************************/
	void testGetDx_positiveVal()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = 10.0;

		// exercise
		double dx = testVel.getDx();

		// verify
		assert(dx == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DY NEGATIVE VAL
	* test getDy when dy is negative
	*******************************************/
	void testGetDy_negativeVal()
	{
		// setup
		Velocity testVel = setup();
		testVel.dy = -10.0;

		// exercise
		double dy = testVel.getDy();

		// verify
		assert(dy == -10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DY 0 VAL
	* test getDy when dy is 0
	*******************************************/
	void testGetDy_0Val()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		double dy = testVel.getDy();

		// verify
		assert(dy == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DY POSITIVE VAL
	* test getDy when dy is positive
	*******************************************/
	void testGetDy_positiveVal()
	{
		// setup
		Velocity testVel = setup();
		testVel.dy = 10.0;

		// exercise
		double dy = testVel.getDy();

		// verify
		assert(dy == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET DX NEGATIVE VAL
	* test setDx when dx is negative
	*******************************************/
	void testSetDx_negativeVal()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.setDx(-10.0);

		// verify
		assert(testVel.dx == -10.0);

		// teardown
		teardown(testVel);
	};


	/*******************************************
	* TEST SET DX 0 VAL
	* test setDx when dx is 0
	*******************************************/
	void testSetDx_0Val()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.setDx(0.0);

		// verify
		assert(testVel.dx == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET DX POSITIVE VAL
	* test setDx when dx is positive
	*******************************************/
	void testSetDx_positiveVal()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.setDx(10.0);

		// verify
		assert(testVel.dx == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET DY NEGATIVE VAL
	* test setDy when dy is negative
	*******************************************/
	void testSetDy_negativeVal()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.setDy(-10.0);

		// verify
		assert(testVel.dy == -10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET DY 0 VAL
	* test setDy when dy is 0
	*******************************************/
	void testSetDy_0Val()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.setDy(0.0);

		// verify
		assert(testVel.dy == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET DY POSITIVE VAL
	* test setDy when dy is positive
	*******************************************/
	void testSetDy_positiveVal()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.setDy(10.0);

		// verify
		assert(testVel.dy == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ASSIGN BOTH POS
	* test assign when both dx and dy are positive
	*******************************************/
	void testAssign_BothPos()
	{
		// setup
		Velocity testVel = setup();
		Velocity newVel;
		newVel.dx = 10.0;
		newVel.dy = 10.0;

		// exercise
		testVel.assign(newVel);

		// verify
		assert(testVel.dy == 10.0);
		assert(testVel.dx == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ASSIGN BOTH NEG
	* test assign when both dx and dy are negative
	*******************************************/
	void testAssign_BothNeg()
	{
		// setup
		Velocity testVel = setup();
		Velocity newVel;
		newVel.dx = -10.0;
		newVel.dy = -10, 0;

		// exercise
		testVel.assign(newVel);

		// verify
		assert(testVel.dy == -10.0);
		assert(testVel.dx == -10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ASSIGN POS DX NEG DY
	* test assign when dx is positive
	* and dy is negative
	*******************************************/
	void testAssign_PosDX_NegDY()
	{
		// setup
		Velocity testVel = setup();
		Velocity newVel;
		newVel.dx = 10.0;
		newVel.dy = -10, 0;

		// exercise
		testVel.assign(newVel);

		// verify
		assert(testVel.dy == -10.0);
		assert(testVel.dx == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ASSIGN NEG DX POS DY
	* test assign when dx is negative
	* and dy is positive
	*******************************************/
	void testAssign_NegDX_PosDY()
	{
		// setup
		Velocity testVel = setup();
		Velocity newVel;
		newVel.dx = -10.0;
		newVel.dy = 10, 0;

		// exercise
		testVel.assign(newVel);

		// verify
		assert(testVel.dy == 10.0);
		assert(testVel.dx == -10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ASSIGN BOTH 0
	* test assign when dx and dy are both 0
	*******************************************/
	void testAssign_Both0()
	{
		// setup
		Velocity testVel = setup();
		Velocity newVel;
		newVel.dx = 0.0;
		newVel.dy = 0, 0;

		// exercise
		testVel.assign(newVel);

		// verify
		assert(testVel.dy == 0.0);
		assert(testVel.dx == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET SPEED NEG DX NEG DY
	* test getSpeed when dx and dy are negative
	*******************************************/
	void testGetSpeed_NegDX_NegDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = -10;
		testVel.dy = -10;

		// exercise
		double speed = testVel.getSpeed();

		// verify *rounding checks
		assert(speed > 14.142135623730949 
			&& speed <= 14.142135623730951);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET SPEED 0 DX NEG DY
	* test getSpeed when dx is 0 
	* and dy is negative
	*******************************************/
	void testGetSpeed_0DX_NegDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dy = -10;

		// exercise
		double speed = testVel.getSpeed();

		// verify *rounding checks
		assert(speed == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET SPEED POS DX NEG DY
	* test getSpeed when dx is positive and 
	* dy is negative
	*******************************************/
	void testGetSpeed_PosDX_NegDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = 10;
		testVel.dy = -10;

		// exercise
		double speed = testVel.getSpeed();

		// verify *rounding checks
		assert(speed > 14.142135623730949
			&& speed < 14.142135623730952);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET SPEED 0 DX 0 DY
	* test getSpeed when dx is 0 dy is 0
	*******************************************/
	void testGetSpeed_0DX_0DY()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		double speed = testVel.getSpeed();

		// verify *rounding checks
		assert(speed == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET SPEED NEG DX 0 DY
	* test getSpeed when dx is negative
	* and dy is 0
	*******************************************/
	void testGetSpeed_NegDX_0DY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = -10;

		// exercise
		double speed = testVel.getSpeed();

		// verify *rounding checks
		assert(speed == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET SPEED POS DX 0 DY
	* test getSpeed when dx is positive
	* and dy is 0
	*******************************************/
	void testGetSpeed_PosDX_0DY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = 10;

		// exercise
		double speed = testVel.getSpeed();

		// verify *rounding checks
		assert(speed == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET SPEED NEG DX POS DY
	* test getSpeed when dx is negative
	* and dy is positive
	*******************************************/
	void testGetSpeed_NegDX_PosDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = -10;
		testVel.dy = 10;

		// exercise
		double speed = testVel.getSpeed();

		// verify *rounding checks
		assert(speed > 14.142135623730949
			&& speed <= 14.142135623730951);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET SPEED 0 DX POS DY
	* test getSpeed when dx is 0
	* and dy is positive
	*******************************************/
	void testGetSpeed_0DX_PosDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dy = 10;

		// exercise
		double speed = testVel.getSpeed();

		// verify *rounding checks
		assert(speed == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET SPEED POS DX POS DY
	* test getSpeed when dx is positive
	* and dy is positive
	*******************************************/
	void testGetSpeed_PosDX_PosDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = 10;
		testVel.dy = 10;

		// exercise
		double speed = testVel.getSpeed();

		// verify *rounding checks
		assert(speed > 14.142135623730949
			&& speed < 14.142135623730952);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DIRECTION NEG DX NEG DY
	* test getDirection when dx and dy are negative
	*******************************************/
	void testGetDirection_NegDX_NegDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = -10;
		testVel.dy = -10;

		// exercise
		Direction dir = testVel.getDirection();

		// verify *rounding checks
		assert(dir.getRadians() >= (5.0 / 4.0) * 3.1415926535897931
			&& dir.getRadians() <= (5.0 / 4.0) * 3.1415926535897933);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DIRECTION 0 DX NEG DY
	* test getDirection when dx is 0
	* and dy is negative
	*******************************************/
	void testGetDirection_0DX_NegDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dy = -10;

		// exercise
		Direction dir = testVel.getDirection();

		// verify *rounding checks
		assert(dir.getRadians() >= 3.1415926535897931
			&& dir.getRadians() <= 3.1415926535897933);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DIRECTION POS DX NEG DY
	* test getDirection when dx is positive and
	* dy is negative
	*******************************************/
	void testGetDirection_PosDX_NegDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = 10;
		testVel.dy = -10;

		// exercise
		Direction dir = testVel.getDirection();

		// verify *rounding checks
		assert(dir.getRadians() >= (3.0 / 4.0) * 3.1415926535897931
			&& dir.getRadians() <= (3.0 / 4.0) * 3.1415926535897933);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DIRECTION 0 DX 0 DY
	* test getDirection when dx is 0 dy is 0
	*******************************************/
	void testGetDirection_0DX_0DY()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		Direction dir = testVel.getDirection();

		// verify *rounding checks
		assert(dir.getRadians() == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DIRECTION NEG DX 0 DY
	* test getDirection when dx is negative
	* and dy is 0
	*******************************************/
	void testGetDirection_NegDX_0DY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = -10;

		// exercise
		Direction dir = testVel.getDirection();

		// verify *rounding checks
		assert(dir.getRadians() >= (3.0 / 2.0) * 3.1415926535897931
			&& dir.getRadians() <= (3.0 / 2.0) * 3.1415926535897933);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DIRECTION POS DX 0 DY
	* test getDirection when dx is positive
	* and dy is 0
	*******************************************/
	void testGetDirection_PosDX_0DY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = 10;

		// exercise
		Direction dir = testVel.getDirection();

		// verify *rounding checks
		assert(dir.getRadians() >= (1.0 / 2.0) * 3.1415926535897931
			&& dir.getRadians() <= (1.0 / 2.0) * 3.1415926535897933);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DIRECTION NEG DX POS DY
	* test getDirection when dx is negative
	* and dy is positive
	*******************************************/
	void testGetDirection_NegDX_PosDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = -10;
		testVel.dy = 10;

		// exercise
		Direction dir = testVel.getDirection();

		// verify *rounding checks
		assert(dir.getRadians() >= (7.0 / 4.0) * 3.1415926535897931
			&& dir.getRadians() <= (7.0 / 4.0) * 3.1415926535897933);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DIRECTION 0 DX POS DY
	* test getDirection when dx is 0
	* and dy is positive
	*******************************************/
	void testGetDirection_0DX_PosDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dy = 10;

		// exercise
		Direction dir = testVel.getDirection();

		// verify *rounding checks
		assert(dir.getRadians() == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST GET DIRECTION POS DX POS DY
	* test getDirection when dx is positive
	* and dy is positive
	*******************************************/
	void testGetDirection_PosDX_PosDY()
	{
		// setup
		Velocity testVel = setup();
		testVel.dx = 10;
		testVel.dy = 10;

		// exercise
		Direction dir = testVel.getDirection();

		// verify *rounding checks
		assert(dir.getRadians() >= (1.0 / 4.0) * 3.1415926535897931
			&& dir.getRadians() <= (1.0 / 4.0) * 3.1415926535897933);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ADD DX POS
	* test addDx when adding positive value
	*******************************************/
	void testAddDx_PositiveVal()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.addDx(10.0);

		// verify
		assert(testVel.dx == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ADD DY POS
	* test addDy when adding positive value
	*******************************************/
	void testAddDy_PositiveVal()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.addDy(10.0);

		// verify
		assert(testVel.dy == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ADD DX 0
	* test addDx when adding 0 value
	*******************************************/
	void testAddDx_0Val()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.addDx(0.0);

		// verify
		assert(testVel.dx == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ADD DY 0
	* test addDy when adding 0 value
	*******************************************/
	void testAddDy_0Val()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.addDy(0.0);

		// verify
		assert(testVel.dy == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ADD DX NEG
	* test addDx when adding negative value
	*******************************************/
	void testAddDx_NegVal()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.addDx(-10.0);

		// verify
		assert(testVel.dx == -10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ADD DY NEG
	* test addDy when adding negative value
	*******************************************/
	void testAddDy_NegVal()
	{
		// setup
		Velocity testVel = setup();

		// exercise
		testVel.addDy(-10.0);

		// verify
		assert(testVel.dy == -10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ADD VEL NEG
	* test addVel when adding negative values
	*******************************************/
	void testAddVel_NegVal()
	{
		// setup
		Velocity testVel = setup();
		Velocity newVel;
		newVel.dx = -10.0;
		newVel.dy = -10.0;

		// exercise
		testVel.addVel(newVel);

		// verify
		assert(testVel.dx == -10.0);
		assert(testVel.dy == -10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ADD VEL 0
	* test addVel when adding 0 values
	*******************************************/
	void testAddVel_0Val()
	{
		// setup
		Velocity testVel = setup();
		Velocity newVel;
		newVel.dx = 0.0;
		newVel.dy = 0.0;

		// exercise
		testVel.addVel(newVel);

		// verify
		assert(testVel.dx == 0.0);
		assert(testVel.dy == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST ADD VEL POS
	* test addVel when adding positive values
	*******************************************/
	void testAddVel_PosVal()
	{
		// setup
		Velocity testVel = setup();
		Velocity newVel;
		newVel.dx = 10.0;
		newVel.dy = 10.0;

		// exercise
		testVel.addVel(newVel);

		// verify
		assert(testVel.dx == 10.0);
		assert(testVel.dy == 10.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION NEG SPEED
	* test setSpeedDirection when speed is negative
	* this should go in the opposite direction
	*******************************************/
	void testSetSpeedDirection_NegSpeed()
	{
		// setup
		Velocity testVel = setup();
		double speed = -10.0;
		Direction dir;
		dir.setRadians(0.0);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify
		assert(testVel.dy == -10.0);
		assert(testVel.dx == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION 0 SPEED
	* test setSpeedDirection when speed is 0
	* this should set both velocities to 0
	*******************************************/
	void testSetSpeedDirection_0Speed()
	{
		// setup
		Velocity testVel = setup();
		double speed = 0.0;
		Direction dir;
		dir.setRadians(0.0);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify
		assert(testVel.dx == 0.0);
		assert(testVel.dy == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION POS SPEED
	* test setSpeedDirection when speed is positive
	* this should go in the same direction
	*******************************************/
	void testSetSpeedDirection_PosSpeed()
	{
		// setup
		Velocity testVel = setup();
		double speed = 10.0;
		Direction dir;
		dir.setRadians(0.0);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify
		assert(testVel.dy == 10.0);
		assert(testVel.dx == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION 0 RAD
	* test setSpeedDirection when direction is 0
	*******************************************/
	void testSetSpeedDirection_0Rad()
	{
		// setup
		Velocity testVel = setup();
		double speed = 10.0;
		Direction dir;
		dir.setRadians(0.0);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify
		assert(testVel.dy == 10.0);
		assert(testVel.dx == 0.0);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION PI FOURTHS RAD
	* test setSpeedDirection when direction is pi/4
	*******************************************/
	void testSetSpeedDirection_PiFourthsRad()
	{
		// setup
		Velocity testVel = setup();
		double speed = 10.0;
		Direction dir;
		dir.setRadians(M_PI / 4);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify *rounding checks
		assert(testVel.dx >= 7.0710678117
			&& testVel.dx <= 7.0710678119);
		assert(testVel.dy >= 7.0710678117 
			&& testVel.dy <= 7.0710678119);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION PI HALVES RAD
	* test setSpeedDirection when direction is pi/2
	*******************************************/
	void testSetSpeedDirection_PiHalvesRad()
	{
		// setup
		Velocity testVel = setup();
		double speed = 10.0;
		Direction dir;
		dir.setRadians(M_PI / 2);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify *rounding checks
		assert(testVel.dy >= -0.00000000001
			&& testVel.dy <= 0.000000000001);
		assert(testVel.dx >= 9.999999999999
			&& testVel.dx <= 10.00000000001);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION THREE PI FOURTHS RAD
	* test setSpeedDirection when direction is 3 * pi/4
	*******************************************/
	void testSetSpeedDirection_ThreePiFourthsRad()
	{
		// setup
		Velocity testVel = setup();
		double speed = 10.0;
		Direction dir;
		dir.setRadians( 3 * M_PI / 4);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify *rounding checks
		assert(testVel.dx >= 7.0710678117
			&& testVel.dx <= 7.0710678119);
		assert(testVel.dy <= -7.0710678117
			&& testVel.dy >= -7.0710678119);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION PI RAD
	* test setSpeedDirection when direction is pi
	*******************************************/
	void testSetSpeedDirection_PiRad()
	{
		// setup
		Velocity testVel = setup();
		double speed = 10.0;
		Direction dir;
		dir.setRadians(M_PI);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify *rounding checks
		assert(testVel.dx >= -0.00000000001
			&& testVel.dx <= 0.000000000001);
		assert(testVel.dy <= -9.999999999999
			&& testVel.dy >= -10.00000000001);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION FIVE PI FOURTHS RAD
	* test setSpeedDirection when direction is 5 * pi/4
	*******************************************/
	void testSetSpeedDirection_FivePiFourthsRad()
	{
		// setup
		Velocity testVel = setup();
		double speed = 10.0;
		Direction dir;
		dir.setRadians(5 * M_PI / 4);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify *rounding checks
		assert(testVel.dx <= -7.0710678117
			&& testVel.dx >= -7.0710678119);
		assert(testVel.dy <= -7.0710678117
			&& testVel.dy >= -7.0710678119);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION THREE PI HALVES RAD
	* test setSpeedDirection when direction is 3 * pi/2
	*******************************************/
	void testSetSpeedDirection_ThreePiHalvesRad()
	{
		// setup
		Velocity testVel = setup();
		double speed = 10.0;
		Direction dir;
		dir.setRadians(3 * M_PI / 2);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify *rounding checks
		assert(testVel.dy >= -0.00000000001
			&& testVel.dy <= 0.000000000001);
		assert(testVel.dx <= -9.999999999999
			&& testVel.dx >= -10.00000000001);

		// teardown
		teardown(testVel);
	};

	/*******************************************
	* TEST SET SPEED DIRECTION SEVEN PI FOURTHS RAD
	* test setSpeedDirection when direction is 7 * pi/4
	*******************************************/
	void testSetSpeedDirection_SevenPiFourthsRad()
	{
		// setup
		Velocity testVel = setup();
		double speed = 10.0;
		Direction dir;
		dir.setRadians(7* M_PI / 4);

		// exercise
		testVel.setSpeedDirection(speed, dir);

		// verify *rounding checks
		assert(testVel.dx <= -7.0710678117
			&& testVel.dx >= -7.0710678119);
		assert(testVel.dy >= 7.0710678117
			&& testVel.dy <= 7.0710678119);

		// teardown
		teardown(testVel);
	};
};