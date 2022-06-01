
#include "SimObjFactory.h"
#include "Warehouse.h"

shared_ptr<SimulatorObj> SimObjFactory::create(Objects type,string &name, Point &location, string &vType) {
    switch (type){
        case WAREHOUSE:
            return make_shared<Warehouse>(name,location);
        case TROOPER:
            return make_shared<Trooper>(name,location,vType);
        case CHOPPER:
            return make_shared<Chopper>(name,location,vType);
        case TRUCK:
            return make_shared<Truck>(name,location, vType);
        default:
            return nullptr;
    }

}
