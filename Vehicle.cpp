//
// Created by iroth on 6/1/2022.
//

#include "Vehicle.h"

void Vehicle::setCourse(double course) {
    _course = course;
}

void Vehicle::drive(double leftOver) {

    double distance = leftOver * getSpeed();
    double xCor = ((distance) * cos(to_radians(getCourse()))) / 100 + getLoc()->x ;
    double yCor = (distance * sin(to_radians(getCourse()))) / 100 + getLoc()->y ;

    setLocation(Point(xCor,yCor));
}

