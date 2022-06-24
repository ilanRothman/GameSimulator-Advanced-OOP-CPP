
#ifndef GAMESIMULATOR_TRUCK_H
#define GAMESIMULATOR_TRUCK_H

#include <vector>
#include "Vehicle.h"

using routesVec = vector <pair<string, pair<double, int> > >;
using timeVec = vector< pair<string,string> >;

/**
 * Truck class
 * One of the simulator object.
 * No need for the implementation of the "Big Five".
 * **/

class Truck: public Vehicle{
private:
    int _crates;
    routesVec _routes; // vector < destination name: (time,crates) >
    timeVec  _times; // vector < arriveTime, LeaveTime >
    int _index;

public:
    // Constructor
    Truck(string &name, const Point& location, string vType): Vehicle(name,location,vType),_crates(0), _index(0) {Vehicle::setState("Moving");};


    // The function will look around for State Troopers
    // in the range of 10 KM.
    bool checkCops();

    // Sets the Truck into "Robbed" mode.
    // The inventory will be gone and the truck state will turn to "OffRoad".
    void robbed();

    // Calculate the speed of the Truck per hour.
    void calcSpeed();

    // Calculate the angle of the current Truck course.
    void calcCourse();

    // initializes the trucks details.
    void init();

    //updates the location and movement of the truck.
    void update() override;

    // Updates the inventory of the truck after it reaches the warehouse
    void updateInventory();

    // updated the inventories after arriving at a warehouse.
    void arrived();

    // updates the next location of the truck, if it finishes the truck state will turn into "OffRoad".
    void updateIndex();

    // calculates the time left for travel after arriving at a warehouse.
    double calcTimeLeft(int time);

    //returns the next destination warehouse.
    warehousePtr getNextDest();

    //true if needs to leave a warehouse at the current time.
    bool needToMove();

    // return true if object need to stay, false otherwise.
    bool stay();

    // starts to move after parking state.
    void startMove();

    // checks whether the next warehouse location is in the same hour.
    bool inRange(int arriveTime);

    // true if finished all the visits.
    bool done();


    /**
     * Setters and Getters
     */
    int getCrates() const { return _crates; }

    void setRoutes(const routesVec &routes);

    void setTimes(const timeVec & times);

    void setCrates(int crates) { _crates = crates;}

    void getStatus() override;

    warehousePtr getCurrentWarehouse();

};

#endif //GAMESIMULATOR_TRUCK_H
