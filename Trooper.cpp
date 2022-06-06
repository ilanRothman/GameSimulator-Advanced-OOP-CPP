
#include "Trooper.h"

string Trooper::getStatus() {
    if(getState() == "Moving")
        return "Heading to " + getHeadingTo() + ", speed " + to_string(getSpeed()) + "km/h";
    if(getState() == "Course")
        return "Heading on course " + to_string(getCourse()) + ", speed " + to_string(getSpeed()) + "km/h";
    return " " + getState();
}