#pragma once
#include "satellite.h"
#include "fragment.h"
#include "deadBody.h"



class GPSRight : public Satellite
{
public:
    GPSRight(Position position, Velocity velocity, Direction direction) :
        Satellite(position, velocity, direction)
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
    GPSRight() : Satellite() 
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

    void draw() { drawGPSRight(position, angularVelocity); }

    void destroy(vector<Satellite*> satellites)
    {
        int numFrag = 3;

        for (int i = 0; i < numFrag; i++)
        {
            Fragment* frag = new Fragment(position, velocity, direction);
            satellites.push_back(frag);
        }
    }
};
class GPSCenter : public Satellite
{
public:
    GPSCenter(Position position, Velocity velocity, Direction direction) :
        Satellite(position, velocity, direction) 
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
    GPSCenter() : Satellite()
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

    void draw() { drawGPSCenter(position, angularVelocity); }

    void destroy(vector<Satellite*> satellites)
    {
        int numFrag = 3;

        for (int i = 0; i < numFrag; i++)
        {
            Fragment* frag = new Fragment(position, velocity, direction);
            satellites.push_back(frag);
        }
    }
};

class GPSLeft : public Satellite
{
public:
    GPSLeft(Position position, Velocity velocity, Direction direction) :
        Satellite(position, velocity, direction)
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
    GPSLeft() : Satellite() 
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

    void draw() { drawGPSLeft(position, angularVelocity); }

    void destroy(vector<Satellite*> satellites)
    {
        int numFrag = 3;

        for (int i = 0; i < numFrag; i++)
        {
            Fragment* frag = new Fragment(position, velocity, direction);
            satellites.push_back(frag);
			cout << "fragment created\n";
        }
    }
};

class GPS : public Satellite
{
public:
	GPS(Position position, Velocity velocity, Direction direction) :
		Satellite(position, velocity, direction) {}
	GPS() : Satellite() {}
	
	void draw() { drawGPS(position, angularVelocity); }

	void destroy(vector<Satellite*> &satellites, vector<Satellite*>& satellitesToAdd)
	{
		

		
		GPSRight* gpsRight = new GPSRight(position, velocity, direction);
        GPSCenter* gpsCenter = new GPSCenter(position, velocity, direction);
		GPSLeft *gpsLeft = new GPSLeft(position, velocity, direction);;
		satellitesToAdd.push_back(gpsRight);
		satellitesToAdd.push_back(gpsCenter);
		satellitesToAdd.push_back(gpsLeft);
		

		int numFrag = 2;
		
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
	}
};