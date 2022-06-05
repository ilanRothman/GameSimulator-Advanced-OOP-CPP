
#ifndef GAMESIMULATOR_VEHICLE_H
#define GAMESIMULATOR_VEHICLE_H

#include "SimulatorObj.h"

class Vehicle: public SimulatorObj{
private:
    int _course;
    string _state;

public:
    Vehicle(string &name, const Point& location,string type): SimulatorObj(name, location,type), _course(0){};

    virtual ~Vehicle() = default;

    int getCourse() const {
        return _course;
    }

    void setCourse(int course) {
        this->_course = course;
    }

    const string &getState() const {
        return _state;
    }

    void setState(const string &state) {
        this->_state = state;
    }

};

#endif //GAMESIMULATOR_VEHICLE_H
