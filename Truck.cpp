

#include "Truck.h"

void Truck::getStatus() {
    if(getState() == "Moving")
        cout << " Heading to " <<  routs.at(_nextIndex).first << ", Crates: " << getCrates() << endl;
    else
        cout << " " + getState() << endl;

}

void Truck::setRouts(const vector<pair<string, pair<double, int>>> &routs) {
    Truck::routs = routs;
    int crates = 0;
    for(auto &el: routs){
        crates += el.second.second;
    }
    setCrates(crates);
}
