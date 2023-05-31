#pragma once


#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include <iostream>

#include <math.h>

#define _USE_MATH_DEFINES
# define M_PI           3.14159265358979323846

using namespace std;



class Physics
{
public:
	/********************************************************
	timeDilation or td = time dilation, which is the ratio of
		simulator time to real - world time

	hoursDay = number of hours in a day,
		24 in the case of earth

	minutesHour = number of minutes
		in an hour, which is
		60 in our case
	*******************************************************/
	double computeTimeDilation(double hoursDay, double minutesHour) 
	{
		return hoursDay * minutesHour;
	}

	/*************************************************
	tpf = time per frame, which is
		real-world time in seconds
		for each frame in the simulator

	td = time dilation

	frameRate = number of frames in the simulator
		per second, 30 in our case

	***************************************************/
	double computeTimePerFrame(double td, double frameRate) 
	{
		return td / frameRate;
	}

	/**************************************************
		rf = rotation of the earth in radians
			for one frame

		frameRate = number of frames per second.
			30 frames per second in our case

		td = how much faster time
			passes in the simulator
			than in the real world

		secondsDay = number of seconds
			for the earth to make one rotation
		**************************************************/
	double computeRotationSpeed(double frameRate, double td, double secondsDay)
	{
		return -((2 * M_PI) / frameRate) * (td / secondsDay);
	}

	/**************************************************
			x = horizontal position at time t(m)

			x0 = initial horizontal position(m)

			dx = horizontal component of velocity(m / s)

			t= time(s)
	**************************************************/
	double computeHorizontalPositionWithConstantVelocity(double xO, double dx, double t)
	{
			return xO + dx * t;
	}
	/**************************************************
		y = vertical position at time t(m)

		y0 = initial vertical position(m)

		dy = vertical component of velocity(m / s)

		t= time(s)
	**************************************************/
	double computeVerticalPositionWithConstantVelocity(double yO, double dy, double t) 
	{
		return yO + dy * t;
	}

	/***************************************************
	* COMPUTE GRAVITATIONAL ACCELERATION
	*         (  r )
	*  gh = g(------)^2
	*        (r + h)
	*
	* gh: magnitude of acceleration due to gravity
	*   at altitude h.
	* g: gravity at sea level (9.80665 m/s^2)
	* r: radius of the earth (6,378,000 m)
	* h: height above the earth in meters
	*
	* Aurgs: g, r, h
	* returns gh
	***************************************************/
	double computGravitationalAcceleration(double g, double r, double h)
	{
		return g * ((r / (r + h)) * (r / (r + h)));
	}

	/***************************************************
	* COMPUTE ALTITUDE
	*
	*  h = sqrt(x^2 + y^2) - r
	*
	*
	* x: horizontal position where the center
	*   of earth is at 0
	* y: vertical position where the center
	*   of earth is at 0
	* r: radius of the earth (6,378,000 m)
	* h: height above the earth in meters
	*
	* Aurgs: x, y, r
	* returns h
	***************************************************/
	double computeAltitude(double x, double y, double r)
	{
		return sqrt((x * x) + (y * y)) - r;
	}

	/***************************************************
	* COMPUTE DIRECTION OF GRAVITY
	*
	*  d = atan((xe - xs) / (ye - ys))
	*
	*
	* d: direction of pull of gravity in radians
	* xe: horizontal center of earth 0
	* xs horizontal position of satelite in meters
	* ye: vertical center of earth 0
	* ys: vertical position of satelite in meters
	*
	* NOTE xe and ye = 0
	* therefore, x and y will represent the position of the
	* satelite
	*
	* Aurgs: x, y
	* returns d
	***************************************************/
	double computeDirectionOfGravity(double x, double y)
	{
		return (atan2(x, y));
	}

	/***************************************************
	* COMPUTE HORIZONTAL COMPONENT
	*
	*  ddx = a * sin(angle)
	*
	*
	* ddx: horizontal acceleration
	* a: total acceleration
	* angle: 0 degrees is up
	*
	* Aurgs: a, angle
	* returns ddx
	***************************************************/
	double computeHorizontalCompnent(double a, double angle)
	{
			return a * sin(angle);
	}

	/***************************************************
	* COMPUTE VERTICAL COMPONENT
	*
	*  ddx = a * cos(angle)
	*
	*
	* ddx: vertical acceleration
	* a: total acceleration
	* angle: 0 degrees is up
	*
	* Aurgs: a, angle
	* returns ddy
	****************************************************/
	double computeVerticalCompnent(double a, double angle)
	{
			return a * cos(angle);
	}


	/***************************************************
	* MOTION WITH CONSTANT VELOCITY
	* s = s0 + v*t
	* 
	* s: distance in meters
	* s0: initial distance
	* v: veloicity m/s
	* t: time sec
	*
	* Aurgs: initial distance, velocity, time
	* returns new distance
	****************************************************/
	double computeMotionWithConstantVelocity(double iniDistance, double velocity, 
		double time)
	{
		return iniDistance + (velocity * time);
	}

	/***************************************************
	* Distance Fomula
	* s = s0 + v*t + 0.5*a*t^2
	*
	* s: distance in meters
	* s0: initial distance
	* v: veloicity m/s
	* t: time sec
	* a: acceleration m/s^2
	*
	* Aurgs: initial distance, velocity, time, acceleration
	* returns new distance
	****************************************************/
	double computeComponentDistance(double iniPosition, double componentVelocity, 
		double componentAcceleration, double time)
	{
		return iniPosition + (componentVelocity * time) + 
			(.5 * componentAcceleration * time * time);
	}

	/***************************************************
	* VELOCITY WITH CONSTANT ACCELERATION
	* v = v0 + a*t
	*
	* v: veloicity m/s
	* t: time sec
	* a: acceleration m/s^2
	* v0: initial velocity
	*
	* Aurgs: initial velocity, time, acceleration
	* returns new velocity
	****************************************************/
	double computeComponentVelocityWithConstantAcceleration(double initVelocity, 
		double acceleration, double time)
	{
		return initVelocity + (acceleration * time);
	}
};











