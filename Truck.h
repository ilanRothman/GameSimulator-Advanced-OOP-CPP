
#ifndef GAMESIMULATOR_TRUCK_H
#define GAMESIMULATOR_TRUCK_H

#include <vector>
#include "Vehicle.h"

class Truck: public Vehicle{
private:
    int _crates;
    vector < pair < string, pair<double, int> > > routs; // vactor < destination name: (time,crates) >
    int _nextIndex;
public:
    Truck(string &name, const Point& location, string vType): Vehicle(name,location,vType), _nextIndex(0) {Vehicle::setState("Moving");};

    int getCrates() const { return _crates; }

    void setRouts(const vector<pair<string, pair<double, int>>> &routs);

    void setCrates(int crates) {
        _crates = crates;
    }
    void getStatus();

private:
    public:
};

#endif //GAMESIMULATOR_TRUCK_H
