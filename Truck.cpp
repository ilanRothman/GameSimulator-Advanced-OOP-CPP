

#include "Truck.h"
#include "Model.h"

void Truck::getStatus() {
    if(getState() == "Moving")
        cout << " Heading to " <<  _routes.at(_nextIndex).first << ", Crates: " << getCrates() << endl;
    else
        cout << " " + getState() << endl;
}

void Truck::setRoutes(const routesVec &routes) {
    _routes = routes;
    int crates = 0;
    for(auto &el: routes){
        crates += el.second.second;
    }
    setCrates(crates);

}
bool Truck::checkCops() {

  for(const auto &obj : *Model::get().getSimObjects())
    if(obj->getType() == "TROOPER")
      if(Point::getDistance(*getLoc(),*obj->getLoc()) <= 10)
        return true;

  return false;
}
void Truck::robbed() {
  setCrates(0);
  setState("Off road");
}

void Truck::calcSpeed() {
    auto nextDest = *Model::get().findWareHouse(_routes.at(_nextIndex).first);
    double dist = Point::getDistance(*getLoc(), *nextDest.getLoc());
    double time = _routes.at(_nextIndex).second.first;
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
    if(getState() == "OffRoad")
        return;

    bool reachedDest;
    reachedDest = move();
    if(reachedDest){
        arrived();
    }

}

bool Truck::move() {
    auto nextDest = getNextDest();
    double currDist = Point::getDistance(*getLoc(), *nextDest->getLoc());
    double coverDist = getSpeed();
    if(coverDist >= currDist){
        setLocation(*nextDest->getLoc());
        return true;
    }
    drive(1);
    return false;
}

void Truck::updateInventory() {
    auto nextDest= getNextDest();
    int currCrate  = _routes.at(_nextIndex).second.second;
    nextDest->setInventory(nextDest->getInventory() + currCrate);
    _crates -= currCrate;
}

void Truck::setTimes(const timeVec &times) {
    _times = times;
}

void Truck::arrived() {
    updateInventory();
    setState("Parked");
    if(updateIndex())
        return;
    calcSpeed();
    calcCourse();
    checkIfLeave();
}

bool Truck::updateIndex() {
    _nextIndex++;
    if(_nextIndex > _routes.size()) {
        setState("OffRoad");
        return true;
    }
    return false;
}

void Truck::checkIfLeave() {
    double simTime = Model::get().getTime();
    double leaveTime = stof(_times.at(_nextIndex).second);
    double leftOver = calcTimeLeft(simTime,leaveTime);
    if(leftOver)
    {
        auto nextDest = getNextDest();
        setHeadingTo(nextDest->getName());
        drive(leftOver/60);
    }

}

void Truck::drive(double leftOver) {
    double distance = leftOver * getSpeed();
    double xCor = ((distance) * cos(to_radians(getCourse()))) / 100 + getLoc()->x ;
    double yCor = (distance * sin(to_radians(getCourse()))) / 100 + getLoc()->y ;
    setState("Moving");
    setLocation(Point(xCor,yCor));
}

double Truck::calcTimeLeft(double currTime, double leaveTime) {
    double minutes = ((leaveTime / 100) * 60) + static_cast<int>(leaveTime) % 100;
    double currTimeMinutes = currTime * 60;

    if(currTimeMinutes > minutes)
        return currTimeMinutes - minutes;

    return 0;
}

shared_ptr<Warehouse> Truck::getNextDest() {
    return Model::get().findWareHouse(_routes.at(_nextIndex).first);
}





