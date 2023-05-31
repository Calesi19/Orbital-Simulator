#pragma once
#include "satellite.h"


class Fragment;
class DragonLeft : public Satellite {};
class DragonRight : public Satellite {};
class DragonCenter : public Satellite {};


class Dragon : public Satellite
{
public:
	Dragon(Position position, Velocity velocity, Direction direction) :
		Satellite(position, velocity, direction) {}
	Dragon() : Satellite() {}

	void draw() { drawCrewDragon(position, angularVelocity); }

	void destroy(vector<Satellite*> satellites)
	{
		DragonLeft dragLeft;
		DragonRight dragRight;
		DragonCenter dragCent;

		satellites.push_back(&dragLeft);
		satellites.push_back(&dragRight);
		satellites.push_back(&dragCent);
		int numFrag = 2;

		for (int i = 0; i < numFrag; i++)
		{
			Fragment frag;
			satellites.push_back(&frag);
		}

	}
};