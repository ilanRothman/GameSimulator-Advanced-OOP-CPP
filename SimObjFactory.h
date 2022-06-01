

#ifndef GAMESIMULATOR_SIMOBJFACTORY_H
#define GAMESIMULATOR_SIMOBJFACTORY_H

#include <iostream>
#include "Chopper.h"
#include "Trooper.h"
#include "Truck.h"
#include "SimulatorObj.h"
#include <memory>
using namespace std;

class SimObjFactory{
    private:
        enum Objects{WAREHOUSE, CHOPPER, TROOPER, TRUCK};
    public:
        shared_ptr<SimulatorObj> create(Objects type, string &name, Point &locations, string &vType);


};

#endif //GAMESIMULATOR_SIMOBJFACTORY_H
