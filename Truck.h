
#ifndef GAMESIMULATOR_TRUCK_H
#define GAMESIMULATOR_TRUCK_H

#include <vector>
#include "Vehicle.h"

class Truck: public Vehicle{
private:
    int _crates;
    vector < pair < string, pair<double, int> > > routs; // vactor < destination name: (time,crates) >
public:
    Truck(string &name, const Point& location, string vType): Vehicle(name,location,vType){;};

    int getCrates() const {
        return _crates;
    }

    void setRouts(const vector<pair<string, pair<double, int>>> &routs) {
        Truck::routs = routs;
    }

    void setCrates(int crates) {
        _crates = crates;
    }

private:
    public:
};

#endif //GAMESIMULATOR_TRUCK_H
