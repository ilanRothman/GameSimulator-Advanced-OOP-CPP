

#ifndef GAMESIMULATOR_SIMULATOROBJ_H
#define GAMESIMULATOR_SIMULATOROBJ_H

#include <utility>
#include <vector>
#include "Geometry.h"
#include "cmath"
#include <climits>
#include <memory>

class Model;

class SimulatorObj{

    private:
        string _name;
        Point _location;
        string _type;

 public:
        SimulatorObj(string& name,const Point& location,string &type): _name(name), _location(location), _type(type){};
        string getType(){return _type;};

        Point* getLoc();
        virtual const string &getName() const;
        void printLoc(){_location.print();};

};



#endif //GAMESIMULATOR_SIMULATOROBJ_H
