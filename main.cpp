#include <iostream>
#include "Controller.h"

int main(int argc,char** argv) {
    if(argc < 3){
        cerr << "Program needs files to run";
        exit(1);
    }

    Controller cnt(argc,argv);
    cnt.run();
    return 0;
}
