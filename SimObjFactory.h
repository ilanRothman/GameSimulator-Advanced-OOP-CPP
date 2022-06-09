

#ifndef GAMESIMULATOR_SIMOBJFACTORY_H
#define GAMESIMULATOR_SIMOBJFACTORY_H

#include <iostream>
#include "Chopper.h"
#include "Trooper.h"
#include "Truck.h"
#include <memory>
#include <map>

using namespace std;
using vehiclePtr = shared_ptr<Vehicle> ;

class SimObjFactory{
    private:
    map<string,int> _types;

    public:
    SimObjFactory();
    shared_ptr<Vehicle> create(string &name,const Point &locations, string Type);


};

#endif //GAMESIMULATOR_SIMOBJFACTORY_H
