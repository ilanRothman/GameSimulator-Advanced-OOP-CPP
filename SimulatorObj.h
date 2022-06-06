

#ifndef GAMESIMULATOR_SIMULATOROBJ_H
#define GAMESIMULATOR_SIMULATOROBJ_H

#include <utility>
#include <vector>

#include "Geometry.h"

class SimulatorObj{
    private:
        string _name;
        Point _location;
        string _type;

 public:
        SimulatorObj(string& name,const Point& location,string &type): _name(name), _location(location), _type(type){}

        virtual const string &getName() const;
        virtual void setRouts(const vector<pair<string, pair<double, int>>> &routs){;};
        virtual  int getInventory() const {return 0;}
        string getType(){return _type;}
        Point* getLoc(){return &_location;};
        string printLoc(){_location.print();return "";}
        virtual string getStatus() {return "";}
        virtual void setCourse(float course){;};
        virtual void setSpeed(int course){;};

};



#endif //GAMESIMULATOR_SIMULATOROBJ_H
