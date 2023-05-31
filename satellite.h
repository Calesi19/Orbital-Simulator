#pragma once
#include "velocity.h"
#include "position.h"
#include "constants.h"
#include "uiDraw.h"
#include <vector>
#include "uiInteract.h"

// forward declare testSatellite
class TestSatellite;


class Satellite
{
	friend class TestSatellite;

protected:

	Velocity velocity;
	Position position;
	Direction direction;
	double angularVelocity;
	bool dead = false;
	double radius;

public:

	Satellite(): angularVelocity(0.0), dead(false), radius(0.0) {};
	Satellite(Position position, Velocity velocity, Direction direction) 
		: position(position), velocity(velocity), direction(direction),
		angularVelocity(0.0), dead(false), radius(5) {}; // change radius for each individual
	Satellite(Satellite& satellite) 
	{
		velocity = satellite.velocity;
		position = satellite.position;
		direction = satellite.direction;
		angularVelocity = satellite.angularVelocity;
		radius = satellite.radius;
		dead = false;
	};

	double getRadius() { return radius; };
	bool isDead() { return dead; };
	Position getPosition() { return position; };

	void kill() 
	{ 
		dead = true; 
		//cout << "satellite down\n";
	};

	virtual void draw() {};
	virtual void destroy(vector<Satellite*> &satellites, vector<Satellite*>& satellitesToAdd) {};
	virtual void move(double time);
	virtual void input(const Interface* UI, vector<Satellite*>& satellitesToAdd) {}


};