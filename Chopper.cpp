
#include "Chopper.h"

void Chopper::getStatus() {
    if(getState() == "Course")
        cout << " Heading on course " << getCourse() << " deg, " << "speed " << getSpeed() << " km/h" << endl;

    else if(getState() == "Position")
        cout << " Moving to " << getHeadingTo() << " speed " << getSpeed() << " km/h" << endl;
    else
        cout << " " + getState() << endl;
}
bool Chopper::attack(Vehicle::vehiclePtr &truck) {

  bool copsAround = dynamic_pointer_cast<Truck>(truck)->checkCops(); // checks if cops around the truck
  bool robbed = false;

  if(getDistance(*getLoc(),*truck->getLoc()) <= _attackRange && !copsAround) // checks if chopper in attack range
  {
    dynamic_pointer_cast<Truck>(truck)->robbed();
    _attackRange++;
    robbed = true;
  }

  setState("Stopped");
  return robbed;
}
