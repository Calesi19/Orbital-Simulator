#pragma once
#include "satellite.h"


class Fragment;
class StarlinkBody : public Satellite {};
class StarlinkArray : public Satellite {};


class Starlink : public Satellite
{
public:
	Starlink(Position position, Velocity velocity, Direction direction) :
		Satellite(position, velocity, direction) {}
	Starlink() : Satellite() {}

	void draw() { drawStarlink(position, angularVelocity); }

	void destroy(vector<Satellite*> satellites)
	{
		StarlinkBody starlinkBod;
		StarlinkArray starlinkArr;

		satellites.push_back(&starlinkArr);
		satellites.push_back(&starlinkBod);

		int numFrag = 2;

		for (int i = 0; i < numFrag; i++)
		{
			Fragment frag;
			satellites.push_back(&frag);
		}

	}
};