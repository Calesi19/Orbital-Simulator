#include "acceleration.h"

void Acceleration::setGravityAtHeight(double height, Direction& dir)
{
    double gravAtHeight = GRAV_AT_SURFACE
        * ((RAD_EARTH / (RAD_EARTH + height))
            * (RAD_EARTH / (RAD_EARTH + height)));

    ddx = gravAtHeight * dir.getPartX();
    ddy = gravAtHeight * dir.getPartY();
}

void Acceleration::assign(Velocity vel, double time)
{
	if (time != 0)
	{
		ddx = vel.getDx() / time;
		ddy = vel.getDy() / time;
	}
	else
		cout << "Time cannot be zero";
}

void Acceleration::setAcceleration(double force, Direction& dir)
{
	ddx = force * dir.getPartX();
	ddy = force * dir.getPartY();
}