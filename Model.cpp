

#include "Model.h"
Model* Model::Model_Instance;
Model::Model():_time(0) {

}

Model &Model::get() {
    if(Model_Instance == nullptr){
        Model_Instance = new Model();
    }
    return *Model_Instance;
}

vehiclePtr Model::findVehicle(string &name) {
   for(auto& v: _vehicleLst){
       if (v->getName() == name)
           return v;
   }
   return nullptr;
}
