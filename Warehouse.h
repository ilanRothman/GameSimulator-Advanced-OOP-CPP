
#ifndef GAMESIMULATOR_WAREHOUSE_H
#define GAMESIMULATOR_WAREHOUSE_H

#include "SimulatorObj.h"

/**
 * WareHouse class
 * One of the simulator object.
 * No need for the implementation of the "Big Five".
 * **/

class Warehouse: public SimulatorObj{

    private:
    int _inventory;
    public:
        // Constructor
        Warehouse(string& name,const Point& location, int inventory, string type):
        SimulatorObj(name,location,type), _inventory(inventory){};

        /*
         * Getters and Setters
         */
        int getInventory() const{ return _inventory;};
        void setInventory(int inventory);

};
#endif //GAMESIMULATOR_WAREHOUSE_H
