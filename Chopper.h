
#ifndef GAMESIMULATOR_CHOPPER_H
#define GAMESIMULATOR_CHOPPER_H

#include "SimulatorObj.h"
#include "Vehicle.h"
#include "Truck.h"



class Truck;

/**
 * Chopper vehicle object.
 * was no need to implement the big 5.
 * **/

class Chopper: public Vehicle{
 private:
  int _attackRange;
public:
    Chopper(string &name, const Point& location, string vType): Vehicle(name,location, vType),_attackRange(2)
    {Vehicle::setState("Stopped");};

    void getStatus(); // returns status of object.

    bool attack(vehiclePtr& truck); // return true if was able to attack given truck. false otherwise.

    void update(); // moves the object if needed.

    void setCourse(double course); // sets the course of the object.

};

#endif //GAMESIMULATOR_CHOPPER_H
