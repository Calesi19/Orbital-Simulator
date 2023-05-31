#pragma once
#include "velocity.h"
#include "constants.h"
#include <iostream>

using namespace std;


class Acceleration
{
private:
	double ddx;
	double ddy;

public:
	Acceleration() : ddx(0.0), ddy(0.0) {};

	void assign(Velocity vel, double time);

	Velocity getVelocity(double time)
	{
		Velocity vel(ddx * time, ddy * time);
		return vel;
	};

	double getDDX() { return ddx; };
	double getDDY() { return ddy; };

	void setGravityAtHeight(double height, Direction& dir);
	void setAcceleration(double force, Direction& dir);
};