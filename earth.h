#pragma once
#include "satellite.h"

class Earth : public Satellite
{
public:
	Earth(Position position, Velocity velocity, Direction direction) :
		Satellite(position, velocity, direction) {}

	Earth() : Satellite() {}

	void draw() { drawEarth(position, angularVelocity); }

	void destroy() {}

	void move(double time) { angularVelocity += 0.01; }
};