#pragma once
#include "satellite.h"

class Fragment : public Satellite
{
public:
    Fragment(Position position, Velocity velocity, Direction direction) :
        Satellite(position, velocity, direction) 
    {
		this->position = position;
		this->velocity = velocity;
		this->direction = direction;
		this->dead = false;
		this->radius = 0;
		//this->velocity.setDx(0.0);
		//this->velocity.setDy(0.0);

		// create kick
		double addedSpeed = random(5000.0, 9000.0);
		double addedDirectionDegrees = random(-90.0, 90.0);

		// update direction and velocity
		this->direction.setDegrees(this->direction.getDegrees() + addedDirectionDegrees);
		this->velocity.setSpeedDirection(this->velocity.getSpeed() + addedSpeed, this->direction);
		

		// update position 4 pixels in fromt of direction
		this->position.addPixelsX(this->direction.getPartX() * 4);
		this->position.addPixelsY(this->direction.getPartY() * 4);
		//this->position.setPixelsX(-450);
		//this->position.setPixelsY(450);
		cout << "made it into fragment constructor\n";
    }
    Fragment() : Satellite() 
	{
		// create kick
		double addedSpeed = random(5000.0, 9000.0);
		double addedDirectionDegrees = random(-90.0, 90.0);

		// update direction and velocity
		direction.setDegrees(direction.getDegrees() + addedDirectionDegrees);
		velocity.setSpeedDirection(velocity.getSpeed() + addedSpeed, direction);

		// update position 4 pixels in fromt of direction
		position.addPixelsX(direction.getPartX() * 4);
		position.addPixelsY(direction.getPartY() * 4);
	}
	void destroy(vector<Satellite*>& satellites, vector<Satellite*>& satellitesToAdd)
	{
		cout << "Fragment Destroyed\n";
	}

    void draw() 
	{
		cout << "drawing fragment\n";
		drawFragment(position, angularVelocity); 
	}
	/*
	void move(double time)
	{
		angularVelocity += 0.05;
	}
	*/


};