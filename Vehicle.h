
#ifndef GAMESIMULATOR_VEHICLE_H
#define GAMESIMULATOR_VEHICLE_H

#include "SimulatorObj.h"
#include "Warehouse.h"

class Vehicle: public SimulatorObj{


  private:
      double _course;
      string _state;
      double _speed;
      string _headingTo;

  public:
      using vehiclePtr = shared_ptr<Vehicle>;
      using warehousePtr = shared_ptr<Warehouse>;

      Vehicle(string &name, const Point& location,string type): SimulatorObj(name, location,type), _course(0), _speed(0){};

      virtual ~Vehicle() = default;

      virtual double getCourse() const { return _course;};

      double getSpeed() const { return _speed;}

      virtual void setCourse(double course);

      void setSpeed(double speed) { _speed = speed;}

      const string &getState() const { return _state;}

      void setState(const string &state) { this->_state = state;}

      const string &getHeadingTo() const { return _headingTo; }

      void setHeadingTo(const string &goTo) { this-> _headingTo = goTo; };

      virtual void getStatus() = 0;

      virtual void update() = 0;


};

#endif //GAMESIMULATOR_VEHICLE_H
