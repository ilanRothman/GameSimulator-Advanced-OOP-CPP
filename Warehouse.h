
#ifndef GAMESIMULATOR_WAREHOUSE_H
#define GAMESIMULATOR_WAREHOUSE_H

#include "SimulatorObj.h"

class Warehouse: public SimulatorObj{
    public:
        Warehouse(string &name, Point& location): SimulatorObj(name,location){;};

};
#endif //GAMESIMULATOR_WAREHOUSE_H
