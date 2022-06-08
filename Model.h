
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
using simuPtr = shared_ptr<SimulatorObj>;

class Model{



    private:
    int _time;
    vector<simuPtr> _simObjects;
    vector<vehiclePtr> _vehicleLst;
    vector<warehousePtr> _warehouseLst;
    SimObjFactory* _simObjFactory;

    Model();
    static Model* Model_Instance;

    public:
        Model(const Model& rhs) = delete;
        Model& operator=(const Model& rhs) = delete;
        ~Model();

        int getTime()const {return _time;}
        vehiclePtr findVehicle(string &name);
        warehousePtr findWareHouse(const string& name) const;

        void course(double deg, double speed, string& vehicleName); // for Chopper
        void position(const string& corX, const string& corY, vehiclePtr& vehicle,int speed = 0);
        void destination(const string& wareHouse, vehiclePtr& vehicle);
        void attack(const string& truck, vehiclePtr& vehicle);
        void stop(vehiclePtr& vehicle){vehicle->setState("Stopped");};
        void addWareHouse(string name,const Point& point, int inventory);

        /**
         * Setters and Getters
         */
        static Model& get();
        vector<simuPtr>* getSimObjects() {return &_simObjects;};

    void addTruck(string &startingPoint, string truckName, const vector < pair<string, pair<double, int> > >& routs);

    void getStatus();

    void getWarehousesStatus();

    void getVehiclesStatus();

    void createChopper(string &name, Point &startingPoint);

    void createTrooper(string &name, string &wareHouse);
};


#endif //GAMESIMULATOR_MODEL_H
