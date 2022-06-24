
#ifndef GAMESIMULATOR_TROOPER_H
#define GAMESIMULATOR_TROOPER_H

#include <memory>
#include "Vehicle.h"

#include "map"

/**
 * State Trooper vehicle object.
 * was no need to implement the big 5.
 * **/

class Trooper: public Vehicle{

private:

    map<warehousePtr,bool> _visitedMap; // holds all the warehouse and a boolean for each one. true if already visited in the current round.
    warehousePtr firstVisit; // the starting warehouse.
    warehousePtr nextDest; // next warehouse in the round.

public:

    Trooper(string &name,const Point& location, string Type);
    ~Trooper() {};

    void init(vector<warehousePtr> &wHouseLst, shared_ptr<Warehouse> first); // initialized the trooper.

    void makeAllFalse(); // after finishing a round makes all false again in visited loop.

    void getClosest(bool &found, warehousePtr &currCloses); // returns the closest warehouse to the trooper.

    void update(); // updates the location and movement.

    //getters and setters.

    void getStatus();

    void setMapRouts(vector<warehousePtr> &warehouses);

    warehousePtr getNextDest();

    void setNext(warehousePtr warehouse);




};

#endif //GAMESIMULATOR_TROOPER_H
