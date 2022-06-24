

#ifndef GAMESIMULATOR_SIMULATOROBJ_H
#define GAMESIMULATOR_SIMULATOROBJ_H

#include <utility>
#include <vector>
#include "Geometry.h"
#include "cmath"
#include <climits>
#include <memory>


class Model;

/**
 * The base object of the Vehicles and Warehouse objects in this program.
 * was no need to implement the big 5.
 * **/

class SimulatorObj{

    private:
        string _name;
        Point _location;
        string _type;
public:
    void setLocation(const Point &location);

public:
        SimulatorObj(string& name,const Point& location,string &type): _name(name), _location(location), _type(type){};

        // returns the type of the simulator object.
        string getType(){return _type;};

        Point* getLoc(); // returns the location of the object.

        virtual const string &getName() const; // returns the name of the object.

        void printLoc(){_location.print();}; // prints the location of the object.

};



#endif //GAMESIMULATOR_SIMULATOROBJ_H
