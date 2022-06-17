
#ifndef GAMESIMULATOR_CHOPPER_H
#define GAMESIMULATOR_CHOPPER_H

#include "SimulatorObj.h"
#include "Vehicle.h"
#include "Truck.h"

class Truck;

class Chopper: public Vehicle{
 private:
  int _attackRange;
public:
    Chopper(string &name, const Point& location, string vType): Vehicle(name,location, vType),_attackRange(2)
    {Vehicle::setState("Stopped");};
    void getStatus();
    bool attack(vehiclePtr& truck);
    void update();
    void setCourse(double course);

};

#endif //GAMESIMULATOR_CHOPPER_H
