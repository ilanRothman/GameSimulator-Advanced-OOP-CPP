
#ifndef GAMESIMULATOR_WAREHOUSE_H
#define GAMESIMULATOR_WAREHOUSE_H

#include "SimulatorObj.h"

class Warehouse: public SimulatorObj{
    private:
    int _inventory;
    public:
        Warehouse(string& name,const Point& location, int inventory, string type):
        SimulatorObj(name,location,type), _inventory(inventory){};

};
#endif //GAMESIMULATOR_WAREHOUSE_H
