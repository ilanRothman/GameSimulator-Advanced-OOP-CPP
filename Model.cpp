
#include <exception>
#include "Model.h"
Model* Model::Model_Instance;

Model::Model():_time(0),_simObjects(),_vehicleLst(),_warehouseLst(),_simObjFactory(new SimObjFactory()) {
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

warehousePtr Model::findWareHouse(const string &name) const {
  for(auto& w: _warehouseLst)
    if(w->getName() == name)
      return w;
  return nullptr;
}
void Model::addWareHouse(string name,const Point &point, int inventory) {

  auto newWare = make_shared<Warehouse>(name,point,inventory,"WAREHOUSE");
  _warehouseLst.emplace_back(newWare);
  _simObjects.emplace_back(newWare);
}
Model::~Model() {
  delete Model_Instance;
  delete _simObjFactory;
}

void Model::addTruck(string &startingPoint, string truckName, const vector < pair<string, pair<double, int> > >& routs) {
    Point startLoc(findWareHouse(startingPoint)->getLoc()->x,findWareHouse(startingPoint)->getLoc()->y);
    auto  newTruck = (_simObjFactory->create(truckName, startLoc,"TRUCK"));
    dynamic_pointer_cast<Truck>(newTruck)->setRouts(routs);
    _simObjects.emplace_back(newTruck);
    _vehicleLst.emplace_back(newTruck);
}

void Model::getStatus() {
    getWarehousesStatus();
    getVehiclesStatus();
}

void Model::getWarehousesStatus() {
    for(auto &wHouse : _warehouseLst){
        cout << wHouse->getName() << " at position ";
        wHouse->printLoc();
        cout << ", Inventory: " << wHouse->getInventory() << endl;
    }

}

void Model::getVehiclesStatus() {
    for(auto &vehicle : _vehicleLst){
        cout << vehicle->getType() << " " << vehicle->getName() << " at ";
        vehicle->printLoc();
        vehicle->getStatus();
    }

}

void Model::course(double deg, double speed, string &vehicleName) {
    vehiclePtr chopper =  findVehicle(vehicleName);
    chopper->setCourse(deg);
    chopper->setSpeed(speed);
}

void Model::createChopper(string &name, Point &startingPoint) {
    if (findVehicle(name)){
        throw;
    }
    auto  newChopper = (_simObjFactory->create(name, startingPoint,"CHOPPER"));
    _simObjects.emplace_back(newChopper);
    _vehicleLst.emplace_back(newChopper);

}

void Model::createTrooper(string &name, string &wareHouse) {
    if(!findWareHouse(wareHouse))
        throw;
    auto newTrooper = _simObjFactory->create(name, *findWareHouse(wareHouse)->getLoc(),"TROOPER");
    dynamic_pointer_cast<Trooper>(newTrooper)->init(_warehouseLst, findWareHouse(wareHouse));
    newTrooper->setSpeed(90);
    _simObjects.emplace_back(newTrooper);
    _vehicleLst.emplace_back(newTrooper);
}

void Model::position(const string& corX, const string& corY, vehiclePtr &vehicle, int speed) {
    vehicle->setState("Position");
    vehicle->setHeadingTo(corX+" "+corY);

    if(speed)
        vehicle->setSpeed(speed);
}



