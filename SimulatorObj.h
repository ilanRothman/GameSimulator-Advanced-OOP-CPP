

#ifndef GAMESIMULATOR_SIMULATOROBJ_H
#define GAMESIMULATOR_SIMULATOROBJ_H

#include "Geometry.h"

class SimulatorObj{
    private:
        string name;
        Point location;
    public:
        SimulatorObj(string& name, Point& location): name(name),location(location){}

        virtual const string &getName() const;

};



#endif //GAMESIMULATOR_SIMULATOROBJ_H
