

#include "Truck.h"
#include "Model.h"

void Truck::getStatus() {
    if(getState() == "Moving")
        cout << " Heading to " <<  _routes.at(_nextIndex).first << ", Crates: " << getCrates() << endl;
    else
        cout << " " + getState() << endl;
}

void Truck::setRouts(const routesVec &routes) {
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
      if(getDistance(*getLoc(),*obj->getLoc()) <= 10)
        return true;

  return false;
}
void Truck::robbed() {
  setCrates(0);
  setState("Off road");
}
