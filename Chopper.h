
#ifndef GAMESIMULATOR_CHOPPER_H
#define GAMESIMULATOR_CHOPPER_H

#include "SimulatorObj.h"
#include "Vehicle.h"

class Chopper: public Vehicle{
public:
    Chopper(string &name, const Point& location, string vType): Vehicle(name,location, vType){Vehicle::setState("Stopped");};
    string getStatus() override;

};

#endif //GAMESIMULATOR_CHOPPER_H
