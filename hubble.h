#pragma once
#include "satellite.h"



class HubbleLeft : public Satellite {};
class HubbleRight : public Satellite {};
class HubbleTelescope : public Satellite {};
class HubbleComputer : public Satellite {};

class Hubble : public Satellite
{
public:
	Hubble(Position position, Velocity velocity, Direction direction) :
		Satellite(position, velocity, direction) {}
	Hubble() : Satellite() {}

	void draw() { drawHubble(position, angularVelocity); }

	void destroy(vector<Satellite*> satellites)
	{
		HubbleLeft hubLeft;
		HubbleRight hubRight;
		HubbleComputer hubCom;
		HubbleTelescope hubTel;

		satellites.push_back(&hubLeft);
		satellites.push_back(&hubRight);
		satellites.push_back(&hubTel);
		satellites.push_back(&hubCom);

	}
};
