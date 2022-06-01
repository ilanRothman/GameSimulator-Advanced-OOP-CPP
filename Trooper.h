
#ifndef GAMESIMULATOR_TROOPER_H
#define GAMESIMULATOR_TROOPER_H

#include "Vehicle.h"

class Trooper: public Vehicle{
    public:
        Trooper(string &name, Point& location, string &vType): Vehicle(name,location, vType){;};
        ~Trooper() {};
};

#endif //GAMESIMULATOR_TROOPER_H
