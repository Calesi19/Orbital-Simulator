#pragma once
#include "satellite.h"
#include "uiInteract.h"
#include "deadBody.h"


class Fragment;

class Sputnik : public Satellite
{
public:
	Sputnik(Position position, Velocity velocity, Direction direction) :
		Satellite(position, velocity, direction) 
	{
		radius = 4.0; // pixels
	}
	Sputnik() : Satellite() 
	{
		radius = 4.0; // pixels
	}

	void draw() { drawSputnik(position, angularVelocity); }

	void destroy(vector<Satellite*> &satellites, vector<Satellite*>& satellitesToAdd)
	{		

		int numFrag = 4;

		for (int i = 0; i < numFrag; i++)
		{
			Fragment* frag = new Fragment(position, velocity, direction);
			satellitesToAdd.push_back(frag);
		}

		int thisIndex = -1;
		//bool found = false;

		int vectSize = satellites.size();
		for (int i = 0; i < vectSize; i++)
		{
			if (
				satellites[i]->getPosition().getPixelsX() == position.getPixelsX()
				&& satellites[i]->getPosition().getPixelsY() == position.getPixelsY()
				&& satellites[i]->getRadius() == radius
				)
			{
				thisIndex = i;
				//found = true;
			}
		}

		//if (found)
		//{
		delete satellites[thisIndex];
		satellites[thisIndex] = NULL;

		//cout << satellites.at(thisIndex);
		Position pos(0, 0);
		Velocity vel(0, 0);
		Direction dir(0);
		satellites[thisIndex] = new DeadBody(pos, vel, dir);
		//auto it = satellites.begin() + thisIndex;
		//satellites.erase(it);
	//}
		// return new frags instead 

	}
};