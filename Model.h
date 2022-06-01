
#ifndef GAMESIMULATOR_MODEL_H
#define GAMESIMULATOR_MODEL_H
#include "SimObjFactory.h"
#include "SimulatorObj.h"
#include "Vehicle.h"
#include "Warehouse.h"
#include "vector"
#include <memory>
using namespace std;
using vehiclePtr = shared_ptr<Vehicle> ;
using warehousePtr = shared_ptr<Warehouse> ;

class Model{

    private:
    int _time;
    vector<SimulatorObj*> _simObjects;
    vector<vehiclePtr> _vehicleLst;
    vector<Warehouse*> _warehouseLst;
    SimObjFactory* _simObjFactory;

    Model();
    static Model* Model_Instance;

    public:
        static Model& get();
        Model(const Model& rhs) = delete;
        Model& operator=(const Model& rhs) = delete;
        ~Model(){delete Model_Instance;}
        int getTime()const {return _time;}
        vehiclePtr findVehicle(string &name);
};


#endif //GAMESIMULATOR_MODEL_H
