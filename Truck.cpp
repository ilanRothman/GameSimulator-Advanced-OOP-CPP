

#include "Truck.h"
#include "Model.h"

void Truck::setTimes(const timeVec &times) {
  _times = times;
}

shared_ptr<Warehouse> Truck::getNextDest() {
  return Model::get().findWareHouse(_routes.at(_index).first);
}

void Truck::getStatus() {
    if(getState() == "Moving")
        cout << " Heading to " <<  _routes.at(_index).first << ", Crates: " << getCrates() << endl;
    else
        cout << " " + getState() << endl;
}

void Truck::setRoutes(const routesVec &routes) {
    _routes = routes;
    int crates = 0;
    for(auto &el: routes){ // calculate the all the crates.
        crates += el.second.second;
    }
    setCrates(crates);
}

bool Truck::checkCops() {

  for(const auto &obj : *Model::get().getSimObjects())
    if(obj->getType() == "State_trooper")
      if(Point::getDistance(*getLoc(),*obj->getLoc()) <= 10)
        return true;

  return false;
}

void Truck::robbed() {
  setCrates(0);
  setState("Off road");
}

void Truck::calcSpeed() {
    auto nextDest = *Model::get().findWareHouse(_routes.at(_index).first);
    double dist = Point::getDistance(*getLoc(), *nextDest.getLoc());
    double time = _routes.at(_index).second.first;

    this->setSpeed(dist/time); // S = V*T
}

void Truck::calcCourse() {

    auto nextDest = getNextDest();
    double course = Point ::getAngle(getLoc(),nextDest->getLoc());
    setCourse(course);
}

void Truck::init() {

    calcSpeed();
    calcCourse();
}

void Truck::update() {

    if (needToMove()) {
        if (getState() == "Parked")
            startMove();
        else  // "Moving" status
            if (move(*getNextDest()->getLoc())) {
                arrived();
                startMove();
            }
    }
}

void Truck::updateInventory() {

    auto nextDest = getNextDest();
    int currCrate  = _routes.at(_index).second.second;

    nextDest->setInventory(nextDest->getInventory() + currCrate);
    _crates -= currCrate;
}

void Truck::arrived() {
    updateInventory();
    updateIndex();
    if(done())
        return;
    init();
}

void Truck::updateIndex() {
    _index++;
    if(_index == _routes.size()) {
        setState("OffRoad");
    }
}

// if current sim Time > given time, it returns the difference else returns 0
double Truck::calcTimeLeft(int time) {
    int minutes = ((time / 100) * 60) + time % 100;
    int currTimeMinutes = Model::get().getTime() * 60;

    if(currTimeMinutes > minutes)
        return currTimeMinutes - minutes;

    return 0;
}
// true if need to move
bool Truck::needToMove() {
    if (getState() == "OffRoad")
        return false;

    if (getState() == "Parked")
        return stay();

    return true;
}

// return true if object need to stay, false otherwise.
bool Truck::stay()
{
    double toStay = calcTimeLeft(stoi(_times.at(_index - 1).second));
    return (toStay > 0);
}

void Truck::startMove() {

    if(done())
        return;

    //loop for going to all dests in current time
    while(inRange(stoi(_times.at(_index).first))) {
        arrived();
        if(done())
            return;
    }


    //if need to leave current warehouse
    if(inRange(stoi(_times.at(_index - 1).second)))
    {
        drive(calcTimeLeft(stoi(_times.at(_index - 1).second))/60);
        setState("Moving");
    }
    else // if need to stay at warehouse
    {

        setLocation(*getCurrentWarehouse()->getLoc());
        if(_index == _routes.size())
            setState("OffRoad");
        else{
            init();
            setState("Parked");
        }

    }

}

bool Truck::inRange(int arriveTime) {

    int currTime = Model::get().getTime();
    if(arriveTime / 100 == currTime)
        if(arriveTime % 100 == 0)
            return true;
    if(arriveTime / 100 < currTime)
        return true;
    return false;
}

bool Truck::done()
{
    return (getState() == "OffRoad");
}

warehousePtr Truck::getCurrentWarehouse() {
    return Model::get().findWareHouse(_routes.at(_index - 1).first);
}

