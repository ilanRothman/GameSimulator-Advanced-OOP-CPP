#include <iostream>
#include "Controller.h"

int main(int argc,char** argv) {
    Controller cnt(argc,argv);
    cnt.run();
    cout << "\nALL GOOD";
    return 0;
}
