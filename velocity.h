#pragma once
#include <cmath>
#include "direction.h"
#include "constants.h"
using namespace std;

// forward declare testVelocity
class TestVelocity;


/*******************************************
* VELOCITY
* This class keeps track of a two-dimensional
* object's horizontal and vertical componenets
* of velocity.
*******************************************/
class Velocity
{
	friend class TestVelocity;

private:
	double dx;
	double dy;

public:
	Velocity(): dx(0.0), dy(0.0) {};
	Velocity(double dx, double dy) : dx(dx), dy(dy) {};
	void assign(Velocity velocity) 
	{ 
	dx = velocity.dx;
	dy = velocity.dy;
	};

	double getDx() { return dx; };
	double getDy() { return dy; };
	double getSpeed() { return std::sqrt((dx * dx) + (dy * dy)); };
	Direction getDirection()
	{
		Direction dir;
		dir.setDxDy(dx, dy);
		return dir;
	};
	

	void setDx(double dx) { this->dx = dx; };
	void setDy(double dy) { this->dy = dy; };
	void setSpeedDirection(double speed, Direction dir)
	{
		dx = dir.getPartX() * speed;
		dy = dir.getPartY() * speed;
	};

	void addDx(double dx) { this->dx += dx; };
	void addDy(double dy) { this->dy += dy; };
	void addVel(Velocity velocity)
	{
		addDx(velocity.getDx());
		addDy(velocity.getDy());
	};
};