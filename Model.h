
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
    vector<simuPtr> _vehicleLst;
    vector<simuPtr> _warehouseLst;
    SimObjFactory* _simObjFactory;

    Model();
    static Model* Model_Instance;

    public:
        Model(const Model& rhs) = delete;
        Model& operator=(const Model& rhs) = delete;
        ~Model();

        int getTime()const {return _time;}
        simuPtr findVehicle(string &name);
        simuPtr findWareHouse(const string& name) const;

        void course(float __deg, int __speed, string& vehicleName); // for Chopper
        void course(float __deg, string& vehicleName);
        void position(const pair<float,float>& __cords, string& vehicleName);
        void position(const pair<float,float>& __cords,int __speed, string& vehicleName); // for Chopper
        void destination(const string& wareHouse, const string& vehicleName);
        void attack(const string& truck, const string& chopperName);
        void stop(const string& vehicleName);
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
