
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

simuPtr Model::findVehicle(string &name) {
   for(auto& v: _vehicleLst){
       if (v->getName() == name)
           return v;
   }
   return nullptr;
}

simuPtr Model::findWareHouse(const string &name) const {
  for(auto& w: _warehouseLst)
    if(w->getName() == name)
      return w;
  return nullptr;
}
void Model::addWareHouse(string name,const Point &point, int inventory) {

  auto newWare = _simObjFactory->create(name,point,"WAREHOUSE",inventory);
  _warehouseLst.emplace_back(newWare);
  _simObjects.emplace_back(newWare);
}
Model::~Model() {
  delete Model_Instance;
  delete _simObjFactory;
}

void Model::addTruck(string &startingPoint, string truckName, const vector < pair<string, pair<double, int> > >& routs) {
    Point startLoc(findWareHouse(startingPoint)->getLoc()->x,findWareHouse(startingPoint)->getLoc()->y);
    auto  newTruck = (_simObjFactory->create(truckName, startLoc,"TRUCK", 0));
    newTruck->setRouts(routs);
    _simObjects.emplace_back(newTruck);
    _vehicleLst.emplace_back(newTruck);
}

void Model::getStatus() {
    getWarehousesStatus();
    getVehiclesStatus();

}

void Model::getWarehousesStatus() {
    for(auto &wHouse : _warehouseLst){
        cout << wHouse->getName() << " at position " << wHouse->printLoc();
        cout << ", Inventory: " << wHouse->getInventory() << endl;
    }

}

void Model::getVehiclesStatus() {
    for(auto &vehicle : _vehicleLst){
        cout << vehicle->getType() << " " << vehicle->getName() << " at " << vehicle->printLoc();
        cout << vehicle->getStatus() << endl;
    }

}

void Model::course(float __deg, int __speed, string &vehicleName) {
    shared_ptr<SimulatorObj> chopper =  findVehicle(vehicleName);
    chopper->setCourse(__deg);
    chopper->setSpeed(__speed);
}

void Model::course(float __deg, string &vehicleName) {
    shared_ptr<SimulatorObj> vehicle =  findVehicle(vehicleName);
    vehicle->setCourse(__deg);
}

void Model::createChopper(string &name, Point &startingPoint) {
    if (findVehicle(name)){
        throw;
    }
    auto  newChopper = (_simObjFactory->create(name, startingPoint,"CHOPPER", 0));
    _simObjects.emplace_back(newChopper);
    _vehicleLst.emplace_back(newChopper);

}

void Model::createTrooper(string &name, string &wareHouse) {
    if(!findWareHouse(wareHouse))
        throw;
    auto newTrooper = _simObjFactory->create(name, *findWareHouse(wareHouse)->getLoc(),"TROOPER", 0);
    _simObjects.emplace_back(newTrooper);
    _vehicleLst.emplace_back(newTrooper);
}


