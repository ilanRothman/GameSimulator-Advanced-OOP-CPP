

#include "Truck.h"
#include "Model.h"

void Truck::setTimes(const timeVec &times) {
  _times = times;
}

shared_ptr<Warehouse> Truck::getNextDest() {
  return Model::get().findWareHouse(_routes.at(_nextIndex).first);
}

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

    if(needToMove())
    {
      if(move())   // true if arrived to warehouse
        arrived();
    }


//    auto next
//    double distLeft =


//    if(Model::get().getTime() - 1)
//      if(getState() == "Parked")
//        if(!calcTimeLeft(Model::get().getTime(), stof(_times.at(_nextIndex).second)))
//          return;
//
//    if(move())
//      arrived();
}

// return true if arrived
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

    auto nextDest = getNextDest();
    int currCrate  = _routes.at(_nextIndex).second.second;

    nextDest->setInventory(nextDest->getInventory() + currCrate);
    _crates -= currCrate;
}

void Truck::arrived() {

    updateInventory();
    setState("Parked");
    update();
}

bool Truck::updateIndex() {
    _nextIndex++;
    if(_nextIndex > _routes.size()) {
        setState("OffRoad");
        return true;
    }
    return false;
}

bool Truck::checkIfLeave() {

    double leaveTime = stof(_times.at(_nextIndex).second);
    double leftOver = calcTimeLeft(leaveTime);

    if(leftOver)
    {
        auto nextDest = getNextDest();
        setHeadingTo(nextDest->getName());
        drive(leftOver/60);
        return true;
    }
    return false;
}

void Truck::drive(double leftOver) {

    double distance = leftOver * getSpeed();
    double xCor = ((distance) * cos(to_radians(getCourse()))) / 100 + getLoc()->x ;
    double yCor = (distance * sin(to_radians(getCourse()))) / 100 + getLoc()->y ;

    setLocation(Point(xCor,yCor));
}

// if current sim Time > given time, it returns the difference else returns 0
double Truck::calcTimeLeft(double time) {
    double minutes = ((time / 100) * 60) + static_cast<int>(time) % 100;
    double currTimeMinutes = Model::get().getTime() * 60;

    if(currTimeMinutes > minutes)
        return currTimeMinutes - minutes;

    return 0;
}

bool Truck::needToMove()
{
  if(getState() == "OffRoad")
    return false;

  if(getState() == "Parked")
  {
    if (stay()) // checks if truck need to stay
      return false;

    // getting out of Warehouse

//    double timeLeft = calcTimeLeft(stof(_times.at(_nextIndex).second));

    updateIndex();
    checkWithinIteration();

    init(); // calc speed and course
    setState("Moving");
//    drive(timeLeft/60);
//    return false;
  }

  return true;
}

bool Truck::stay()
{
  return !(static_cast<bool>(calcTimeLeft(stof(_times.at(_nextIndex).second))));
}

// Checks if next warehouse is in the same iteration
//void Truck::checkWithinIteration()
//{
//  bool flag = true;
//  double timeLeft;
//
//}



