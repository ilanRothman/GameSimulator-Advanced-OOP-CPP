
#ifndef GAMESIMULATOR_CHOPPER_H
#define GAMESIMULATOR_CHOPPER_H

#include "SimulatorObj.h"
#include "Vehicle.h"

class Chopper: public Vehicle{
public:
    Chopper(string &name, Point& location, string &vType): Vehicle(name,location, vType){;};
};

#endif //GAMESIMULATOR_CHOPPER_H
