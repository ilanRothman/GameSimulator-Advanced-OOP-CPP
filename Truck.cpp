//
// Created by iroth on 6/1/2022.
//

#include "Truck.h"

string Truck::getStatus() {
    if(getState() == "Moving")
        return " Heading to " + routs.at(_nextIndex).first + ", Crates: " + to_string(getCrates());
    return " " + getState();

}

void Truck::setRouts(const vector<pair<string, pair<double, int>>> &routs) {
    Truck::routs = routs;
    int crates = 0;
    for(auto &el: routs){
        crates += el.second.second;
    }
    setCrates(crates);
}
