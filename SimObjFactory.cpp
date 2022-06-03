
#include "SimObjFactory.h"
#include "Warehouse.h"

SimObjFactory::SimObjFactory():_types() {
  _types.insert({"WAREHOUSE",1});
  _types.insert({"TROOPER",2});
  _types.insert({"CHOPPER",3});
  _types.insert({"TRUCK",4});
}

shared_ptr<SimulatorObj> SimObjFactory::create(string& name,
                                               const Point& location, string type = "NONE", int inventory = 0) {
    switch (_types.at(type)){
        case 1:
            return make_shared<Warehouse>(name,location,inventory, "WAREHOUSE");
        case 2:
            return make_shared<Trooper>(name,location,type);
        case 3:
            return make_shared<Chopper>(name,location,type);
        case 4:
            return make_shared<Truck>(name,location, type);
        default:
            return nullptr;
    }

}

