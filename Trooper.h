
#ifndef GAMESIMULATOR_TROOPER_H
#define GAMESIMULATOR_TROOPER_H

#include "Vehicle.h"

class Trooper: public Vehicle{
    public:
        Trooper(string &name,const Point& location, string Type): Vehicle(name,location, Type){Vehicle::setState("Stopped");};
        ~Trooper() {};
        string getStatus();
};

#endif //GAMESIMULATOR_TROOPER_H
