
#include "Trooper.h"

void Trooper::init(vector<warehousePtr> &wHouseLst, shared_ptr<Warehouse> first) {
    this->firstVisit = first;
    setMapRouts(wHouseLst);
    nextDest = getNextDest();
    setNext(nextDest);
    Vehicle::setSpeed(90);
}

void Trooper::getStatus() {
    if(getState() == "Course")
        cout << " Heading to " << getHeadingTo() << ", speed " << getSpeed() << "km/h" << endl;
    else if(getState() == "Position")
        cout << " Heading to (" << getHeadingTo() << ") , speed " << getSpeed() << "km/h" << endl;
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
    bool found = false;

    getClosest(found,currClosest);
    if(!found){ // start new loop again.
        makeAllFalse();
        setNext(firstVisit);
        return firstVisit;
    }
    setNext(currClosest);
    return currClosest;
}

void Trooper::setNext(Vehicle::warehousePtr warehouse) {
    setHeadingTo(warehouse->getName());
    setCourse(Point::getAngle(getLoc(),warehouse->getLoc()));
    setState("course");
}

void Trooper::makeAllFalse() {
    for(auto& warehouse : _visitedMap){
        warehouse.second = false;
   }
}

void Trooper::getClosest(bool &found, warehousePtr &currClosest) {
    double minDist = LONG_MAX;
    double currDist = 0;
    for(auto &wareHouse: _visitedMap){ // loop over warehouses
        if(!wareHouse.second){ // find one who hasn't been visited yet.
            found = true;
            currDist = Point::getDistance(*getLoc(),*wareHouse.first->getLoc()); // get distance from that warehouse.
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
}

Trooper::Trooper(string &name, const Point &location, string Type) : Vehicle(name, location, Type) {

}

void Trooper::update() {

    if (getState() == "Position")
        if (move(headingToPoint())) {
            nextDest = getNextDest();
            setNext(nextDest);
            return;
        }

    if(getState() == "Course")
        if (move(*nextDest->getLoc())){
            nextDest = getNextDest();
            _visitedMap.at(nextDest) = true;
            setNext(nextDest);
        }

}





