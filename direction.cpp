#pragma once
#include "direction.h"

/**************************************
*CONVERT TO DEGREES
* converts an angle in radians to
* degrees
*
* INPUT
*	radian- the angle to be converted
* Output
*	the angle in degrees
  ***************************************/
double Direction::convertToDegrees(double radian)
{
    return (180 / M_PI) * radian;
};

/**************************************
* CONVERT TO RADIANS
* converts an angle in degrees to
* radians
*
* INPUT
*	degree- the angle to be converted
* Output
*	the angle in radians
***************************************/
double Direction::convertToRadians(double degree)
{
    return (M_PI / 180) * degree;
}

/**************************************
* NORMALIZE RADIANS
* standardizes angle passed in as radians
***************************************/
double Direction::normalizeRadians(double radians)
{
    int multiple = abs(radians / (2 * M_PI));
    if (radians >= 2 * M_PI)
    {
        return radians - (multiple * 2 * M_PI);
    }

    else if (radians < 0)
    {
        return radians + (multiple * 2 * M_PI) + (2 * M_PI);
    }

    else return radians;
}

/**************************************
* NORMALIZE DEGREES
* standardizes angle passed in as degrees
***************************************/
double Direction::normalizeDegrees(double degrees)
{
    int multiple = abs(degrees / 360);
    if (degrees >= 360)
    {
        return degrees - (multiple * 360);
    }

    else if (degrees < 0)
    {
        return degrees + (multiple * 360) + 360;
    }

    else return degrees;
}

void Direction::setUp() { radians = 0; };
void Direction::setDown() { radians = M_PI; };
void Direction::setLeft() { radians = 3 * M_PI / 2; };
void Direction::setRight() { radians = M_PI / 2; };