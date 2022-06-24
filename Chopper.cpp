
#include "Chopper.h"

void Chopper::getStatus() {
    if(getState() == "Course")
        cout << " Heading on course " << static_cast<unsigned int>(450 - getCourse()) % 360  << " deg, " << "speed " << getSpeed() << " km/h" << endl;

    else if(getState() == "Position")
        cout << " Moving to (" << getHeadingTo() << "), speed " << getSpeed() << " km/h" << endl;
    else
        cout << " " + getState() << endl;
}
bool Chopper::attack(Vehicle::vehiclePtr &truck) {

  bool copsAround = dynamic_pointer_cast<Truck>(truck)->checkCops(); // checks if cops around the truck
  bool robbed = false;
  double dist = Point::getDistance(*getLoc(),*truck->getLoc());
  if( dist <= _attackRange && !copsAround) // checks if chopper in attack range
  {
    dynamic_pointer_cast<Truck>(truck)->robbed();
    _attackRange < 20 ?  _attackRange++ : _attackRange;
    robbed = true;
  }

  setState("Stopped");
  return robbed;
}

void Chopper::update(){

    if(getState() == "Stopped")
        return;

    if(getState() == "Position") {
        if(move(headingToPoint()))
            setState("Stopped");
        return;
    }
    drive(1);

}

void Chopper::setCourse(double course) {
    Vehicle::setCourse(course);
    setState("Course");
}




