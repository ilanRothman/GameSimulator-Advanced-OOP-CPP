
#include "SimObjFactory.h"
#include "Warehouse.h"

SimObjFactory::SimObjFactory():_types() {
  _types.insert({"State_trooper",1});
  _types.insert({"Chopper",2});
  _types.insert({"TRUCK",3});
}

vehiclePtr SimObjFactory::create(string& name, const Point& location, string type) {
    switch (_types.at(type)){
        case 1:
            return make_shared<Trooper>(name,location,type);
        case 2:
            return make_shared<Chopper>(name,location,type);
        case 3:
            return make_shared<Truck>(name,location, type);
        default:
            return nullptr;
    }

}

