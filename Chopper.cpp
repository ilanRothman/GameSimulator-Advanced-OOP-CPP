//
// Created by iroth on 6/1/2022.
//

#include "Chopper.h"

string Chopper::getStatus() {
    if(getState() == "Course"){
        return " Heading on course " + to_string(getCourse()) + " deg, " + "speed " + to_string(getSpeed()) + "km/h";
    }
    return " " + getState();

}
