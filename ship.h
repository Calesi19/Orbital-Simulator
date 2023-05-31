#pragma once
#include "satellite.h"
#include "acceleration.h"
#include "constants.h"
#include "uiInteract.h"
#include "projectile.h"

class Ship : public Satellite
{
public:
	Ship(Position position, Velocity velocity, Direction direction) :
		Satellite(position, velocity, direction) 
	{
		thrust = false;
        direction.setDown();
        angularVelocity = direction.getRadians();
	}
	Ship() : Satellite() 
    { 
        thrust = false;
        direction.setDown();
        angularVelocity = direction.getRadians();
    }

	void draw() { drawShip(position, angularVelocity, thrust) ; }

	void destroy(vector<Satellite*>& satellites)
	{}
	void input(const Interface *UI, vector<Satellite*>& satellitesToAdd)
    {
        if (UI->isDown() || UI->isUp())
            thrust = true;
        else thrust = false;

        if (UI->isLeft())
            angularVelocity -= 0.1;
        if (UI->isRight())
            angularVelocity += 0.1;
        if (UI->isSpace())
            fire(satellitesToAdd);

    };

    void fire(vector<Satellite*>& satellites)
    {
        Projectile* bullet = new Projectile(this->position, this->velocity, this->direction);
        satellites.push_back(bullet);

    }

    void move(double time)
    {

        // direction of acceleration
        direction.setRadians(angularVelocity);

        // Acceleration
        Acceleration accel;
        accel.setAcceleration(0.0, direction);

        if (thrust)
            accel.setAcceleration(THRUST, direction); 

        // Velocity
        Velocity addedVel(accel.getDDX() * time, accel.getDDY() * time);
        velocity.addVel(addedVel);

        // Position
        position.addMetersX(velocity.getDx() * time);
        position.addMetersY(velocity.getDy() * time);
    }

private:
	bool thrust;
};