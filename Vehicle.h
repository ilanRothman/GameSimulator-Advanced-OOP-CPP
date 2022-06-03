
#ifndef GAMESIMULATOR_VEHICLE_H
#define GAMESIMULATOR_VEHICLE_H

#include "SimulatorObj.h"

class Vehicle: public SimulatorObj{


public:
    Vehicle(string &name, const Point& location,string type): SimulatorObj(name, location,type){};

    virtual ~Vehicle() = default;

};

#endif //GAMESIMULATOR_VEHICLE_H
