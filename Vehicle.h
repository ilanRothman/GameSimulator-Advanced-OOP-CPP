
#ifndef GAMESIMULATOR_VEHICLE_H
#define GAMESIMULATOR_VEHICLE_H

#include "SimulatorObj.h"
#include "Warehouse.h"

/**
 * Vehicle class
 * One of the simulator object.
 * No need for the implementation of the "Big Five".
 * **/

class Vehicle: public SimulatorObj{


  private:
      double _course;
      string _state;
      double _speed;
      string _headingTo;

  public:
      using vehiclePtr = shared_ptr<Vehicle>;
      using warehousePtr = shared_ptr<Warehouse>;

      // Constructor
      Vehicle(string &name, const Point& location,string type): SimulatorObj(name, location,type), _course(0), _speed(0){};

      // Destructor
      virtual ~Vehicle() = default;

      // with given amount of Minutes the vehicle will move the proper distance by its speed and time.
      virtual void drive(double leftOver);

      // updates the Vehicle Location
      virtual void update() = 0;

      // moves the Vehicle towards certain pair of cords.
      // returns true if the vehicle reaches it, false otherwise.
      virtual bool move(const Point &p);

      // Convert Point in string form into regular Point.
      Point headingToPoint();

      /**
    * Getters and setters
    * **/
      virtual void getStatus() = 0;

      virtual double getCourse() const { return _course;};

      double getSpeed() const { return _speed;}

      virtual void setCourse(double course);

      void setSpeed(double speed) { _speed = speed;}

      const string &getState() const { return _state;}

      void setState(const string &state) { this->_state = state;}

      const string &getHeadingTo() const { return _headingTo; }

      void setHeadingTo(const string &goTo) { this-> _headingTo = goTo; };
};

#endif //GAMESIMULATOR_VEHICLE_H
