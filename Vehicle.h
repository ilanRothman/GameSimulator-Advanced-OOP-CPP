
#ifndef GAMESIMULATOR_VEHICLE_H
#define GAMESIMULATOR_VEHICLE_H

#include "SimulatorObj.h"

class Vehicle: public SimulatorObj{

private:
    string _type;
public:
    Vehicle(string &name, Point &location, string& type): SimulatorObj(name, location), _type(type){};

    virtual ~Vehicle() = default;

    string getType()const {return _type;};

};

#endif //GAMESIMULATOR_VEHICLE_H
