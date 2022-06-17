
#ifndef GAMESIMULATOR_TRUCK_H
#define GAMESIMULATOR_TRUCK_H

#include <vector>
#include "Vehicle.h"

using routesVec = vector <pair<string, pair<double, int> > >;
using timeVec = vector< pair<string,string> >;

class Truck: public Vehicle{
private:
    int _crates;
    routesVec _routes; // vector < destination name: (time,crates) >
    timeVec  _times; // vector < arriveTime, LeaveTime >
    int _index;

public:
    Truck(string &name, const Point& location, string vType): Vehicle(name,location,vType), _index(0) {Vehicle::setState("Moving");};

    int getCrates() const { return _crates; }

    void setRoutes(const routesVec &routes);

    void setTimes(const timeVec & times);

    void setCrates(int crates) { _crates = crates;}

    void getStatus();

    bool checkCops();

    void robbed();

    void calcSpeed();

    void calcCourse();

    void init();

    void update();

    bool move();

    void updateInventory();

    void arrived();

    void updateIndex();

    double calcTimeLeft(int time);

    shared_ptr<Warehouse> getNextDest();

    bool needToMove();

    bool stay();

    void startMove();

    bool inRange(int arriveTime);

    bool done();

    warehousePtr getCurrentWarehouse();
};

#endif //GAMESIMULATOR_TRUCK_H
