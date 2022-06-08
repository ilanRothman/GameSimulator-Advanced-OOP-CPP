
#include "Chopper.h"

void Chopper::getStatus() {
    if(getState() == "Course")
        cout << " Heading on course " << getCourse() << " deg, " << "speed " << getSpeed() << " km/h" << endl;

    else if(getState() == "Position")
        cout << " Moving to " << getHeadingTo() << " speed " << getSpeed() << " km/h" << endl;
    else
        cout << " " + getState() << endl;
}
