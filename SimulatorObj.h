

#ifndef GAMESIMULATOR_SIMULATOROBJ_H
#define GAMESIMULATOR_SIMULATOROBJ_H

#include <utility>

#include "Geometry.h"

class SimulatorObj{
    private:
        string _name;
        Point _location;
        string _type;

 public:
        SimulatorObj(string& name,const Point& location,string &type): _name(name), _location(location), _type(type){}

        virtual const string &getName() const;
        string getType(){return _type;}

};



#endif //GAMESIMULATOR_SIMULATOROBJ_H
