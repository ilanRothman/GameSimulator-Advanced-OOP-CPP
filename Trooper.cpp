
#include "Trooper.h"

void Trooper::init(vector<warehousePtr> &wHouseLst, shared_ptr<Warehouse> first) {
    this->firstVisit = first;
    setMapRouts(wHouseLst);
    nextDest = getNextDest();
}

void Trooper::getStatus() {
    if(getState() == "course")
        cout << " Heading to " << getHeadingTo() << ", speed " << getSpeed() << "km/h" << endl;
    else
        cout<<  " " + getState() << endl;
}

void Trooper::setMapRouts(vector<warehousePtr> &warehouses) {
    for(auto& warehouse : warehouses){
        _visitedMap.insert(make_pair(warehouse, false));
    }
    _visitedMap.at(firstVisit) = true;
}

shared_ptr<Warehouse> Trooper::getNextDest() {
    warehousePtr currClosest;
    double minDist = LONG_MAX;
    double currDist = 0;
    for(auto &wareHouse: _visitedMap){ // loop over warehouses
        if(!wareHouse.second){ // find one who hasn't been visited yet.
            currDist = getDistance((wareHouse.first)); // get distance from that warehouse.
            if(currDist == minDist)
                if(currClosest->getName()[0] > wareHouse.first->getName()[0]){ // pick the one with lower letter.
                    currClosest = wareHouse.first;
                }
            if(currDist < minDist) {
                minDist = currDist;
                currClosest = wareHouse.first;
            }
        }
    }
    setHeadingTo(currClosest->getName());
    setCourse(Point::getAngle(getLoc(),currClosest->getLoc()));
    return currClosest;
}

double Trooper::getDistance(const warehousePtr& dest) {
    return sqrt( pow((dest->getLoc()->x) - (getLoc()->x) , 2) + pow((dest->getLoc()->y) - (getLoc()->y) , 2));
}

