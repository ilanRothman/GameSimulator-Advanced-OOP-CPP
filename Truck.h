
#ifndef GAMESIMULATOR_TRUCK_H
#define GAMESIMULATOR_TRUCK_H

#include <vector>
#include "Vehicle.h"

using routesVec = vector <pair<string, pair<double, int> > >;

class Truck: public Vehicle{
private:
    int _crates;
    routesVec _routes; // vactor < destination name: (time,crates) >
    int _nextIndex;
public:
    Truck(string &name, const Point& location, string vType): Vehicle(name,location,vType), _nextIndex(0) {Vehicle::setState("Moving");};

    int getCrates() const { return _crates; }

    void setRouts(const routesVec &routes);

    void setCrates(int crates) {
        _crates = crates;
    }
    void getStatus();

    bool checkCops();

    void robbed();

};

#endif //GAMESIMULATOR_TRUCK_H
