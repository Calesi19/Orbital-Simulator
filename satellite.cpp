#pragma once
#include "satellite.h"
#include "direction.h"
#include "acceleration.h"
#include <cmath>
using namespace std;

void Satellite::move(double time)
{
    // direction of gravity
    direction.setDxDy(position.getMetersX(), position.getMetersY());

    // height
    double height = computeAltitude(position);
   
    // Acceleration
    Acceleration accel;
    accel.setGravityAtHeight(height, direction);

    // Velocity
    Velocity addedVel(accel.getDDX() * time, accel.getDDY() * time);
    velocity.addVel(addedVel);

    // Position
    position.addMetersX(velocity.getDx() * time);
    position.addMetersY(velocity.getDy() * time);

    angularVelocity += 0.02;
}