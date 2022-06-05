

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
//    TODO -- add option for adding rout

}
