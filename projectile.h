#pragma once
#include "satellite.h"
#include "acceleration.h"


class Projectile : public Satellite
{
public:
    Projectile(Position position, Velocity velocity, Direction direction) :
        Satellite(position, velocity, direction)
    {
        radius = 1;
        this->position = position;
        this->velocity = velocity;
        this->direction = direction;

        this->position.addPixelsX(this->direction.getPartX() * 19);
        this->position.addPixelsY(this->direction.getPartY() * 19);

        Velocity vel;
        this->velocity.setSpeedDirection(9000.0, this->direction);
    }
    Projectile() : Satellite()
    {}

    /*
    Projectile(Satellite* ship) {
        
        this->position.setPosition(ship->getPosition());
        this->setDirection(ship->getDirection());
        this->setVelocity(Velocity(3000, this->getDirection()));
        
    }
    */

    void draw() {
        drawProjectile(this->getPosition());
    }

    int expirationCounter = 48 * 2;

    void decreaseLife() {

        if (expirationCounter > 0)
        {
            this->expirationCounter--;
        }
        else
        {
            this->kill();
        }
    }
    void move(double time)
    {
        position.addMetersX(velocity.getDx() * time);
        position.addMetersY(velocity.getDy() * time);
        decreaseLife();
    }

    void destroy(vector<Satellite*>& satellites, vector<Satellite*>& satellitesToAdd)
    {
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