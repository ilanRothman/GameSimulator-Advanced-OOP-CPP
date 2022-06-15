
#include "SimulatorObj.h"


const string &SimulatorObj::getName() const {
    return this->_name;
}

Point *SimulatorObj::getLoc() {
    return &_location;
}

void SimulatorObj::setLocation(const Point &location) {
    _location = location;
}



