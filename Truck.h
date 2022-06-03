
#ifndef GAMESIMULATOR_TRUCK_H
#define GAMESIMULATOR_TRUCK_H
#include "Vehicle.h"

class Truck: public Vehicle{
    public:
        Truck(string &name, const Point& location, string vType): Vehicle(name,location,vType){;};
};

#endif //GAMESIMULATOR_TRUCK_H
