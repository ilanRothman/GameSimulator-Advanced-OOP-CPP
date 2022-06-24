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

bool Vehicle::move(const Point &p) {
    double currDist = Point::getDistance(*getLoc(), p);
    double coverDist = getSpeed();

    if(coverDist >= currDist){
        setLocation(p);
        return true;
    }

    drive(1);
    return false;
}

Point Vehicle::headingToPoint()
{
    string p = getHeadingTo();
    int xCor = stoi(p.substr(0,p.find(' ')));
    int yCor = stoi(p.substr(p.find(' '),p.size()));

    return Point(xCor,yCor);
}

