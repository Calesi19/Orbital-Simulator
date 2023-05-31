#pragma once
#include "satellite.h"

class DeadBody : public Satellite
{
public:
    DeadBody(Position position, Velocity velocity, Direction direction) :
        Satellite(position, velocity, direction) {}
    DeadBody() : Satellite() {}

    void draw() {}

    void destroy(vector<Satellite*> &satellites, vector<Satellite*> &satellitesToAdd){}
    void input(const Interface* UI){}
    void move(double time) {}

};