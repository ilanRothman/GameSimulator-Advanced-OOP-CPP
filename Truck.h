
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
    timeVec  _times;
    int _nextIndex;


public:
    Truck(string &name, const Point& location, string vType): Vehicle(name,location,vType), _nextIndex(0) {Vehicle::setState("Parked");};

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

    bool updateIndex();

    void checkIfLeave();

    void drive(double over);

    double calcTimeLeft(double currTime, double leaveTime);

    shared_ptr<Warehouse> getNextDest();
};

#endif //GAMESIMULATOR_TRUCK_H
