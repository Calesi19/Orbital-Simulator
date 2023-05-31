#define _USE_MATH_DEFINES
#pragma once

#include <cmath>
using namespace std;


class Direction
{
private:
	double radians;
	double normalizeRadians(double radians);
	double normalizeDegrees(double degrees);
	double convertToDegrees(double radians);
	double convertToRadians(double degrees);

public:
	Direction() : radians(0.0) {};
	Direction(double radians)
	{
		this->radians = normalizeRadians(radians);
	}

	void setRadians(double radians)	
	{ 
		this->radians = normalizeRadians(radians); 
	};
	void setDegrees(double degrees)
	{
		this->radians = convertToRadians(normalizeDegrees(degrees));
	};

	double getRadians() { return radians; };
	double getDegrees() { return convertToDegrees(radians); };
	double getPartX() { return sin(radians); };
	double getPartY() { return cos(radians); };

	void rotate(double amount) { radians = normalizeRadians(radians + amount); };

	
	void setDxDy(double dx, double dy) 
	{ 
		radians = normalizeRadians(atan2(dx, dy)); 
	};

	void setUp();
	void setDown();
	void setLeft();
	void setRight();
};