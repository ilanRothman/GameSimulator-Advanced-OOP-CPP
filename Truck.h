
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

    // initializes the trucks details.
    void init();

    //updates the location and movement of the truck.
    void update() override;

    // Updates the inventory of the truck after it reaches the warehouse
    void updateInventory();

    // updated the inventories after arriving at a warehouse.
    void arrived();

    void updateIndex();

    // calculates the time left for travel after arriving at a warehouse.
    double calcTimeLeft(int time);

    //returns the next destination warehouse.
    warehousePtr getNextDest();

    //true if needs to leave a warehouse at the current time.
    bool needToMove();

    // return true if object need to stay, false otherwise.
    bool stay();

    void startMove();

    // checks whether the next warehouse location is in the same hour.
    bool inRange(int arriveTime);

    // true if finished all the visits.
    bool done();

    warehousePtr getCurrentWarehouse();
};

#endif //GAMESIMULATOR_TRUCK_H
