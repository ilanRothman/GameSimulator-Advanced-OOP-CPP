

#ifndef GAMESIMULATOR_SIMOBJFACTORY_H
#define GAMESIMULATOR_SIMOBJFACTORY_H

#include <iostream>
#include "Chopper.h"
#include "Trooper.h"
#include "Truck.h"
#include <memory>
#include <map>

/**
 * Factory method design pattern.
 * Used here for creating all the vehicle object in the program.
 * **/

using namespace std;
using vehiclePtr = shared_ptr<Vehicle> ;

class SimObjFactory{
    private:
    map<string,int> _types; // holds the different types of vehicles in the program.

    public:
    SimObjFactory();

    // the factory method.
    // calls the constructors of the correct Vehicle.
    shared_ptr<Vehicle> create(string &name,const Point &locations, string Type);


};

#endif //GAMESIMULATOR_SIMOBJFACTORY_H
