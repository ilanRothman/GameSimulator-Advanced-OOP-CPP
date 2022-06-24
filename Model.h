
#ifndef GAMESIMULATOR_MODEL_H
#define GAMESIMULATOR_MODEL_H

#include "SimObjFactory.h"
#include "vector"
#include <memory>

using namespace std;
using vehiclePtr = shared_ptr<Vehicle> ;
using warehousePtr = shared_ptr<Warehouse> ;
using simuPtr = shared_ptr<SimulatorObj>;
using timeVec = vector< pair<string,string> >;
using routesVec = vector < pair<string, pair<double, int> > >;

class Model{
    class TruckAttack{
        string name;
        vehiclePtr vehicle;
    public:
        TruckAttack(const string& truck, vehiclePtr& vehicle): name(truck),vehicle(vehicle){}
        TruckAttack() = default;
        void setName(const string &name) {TruckAttack::name = name;}
        void setVehicle(const vehiclePtr &vehicle) {TruckAttack::vehicle = vehicle;}
        const vehiclePtr &getVehicle() const { return vehicle;}
        const string &getName() const {return name;}
    };

    private:
    int _time;
    vector<simuPtr> _simObjects;
    vector<vehiclePtr> _vehicleLst;
    vector<warehousePtr> _warehouseLst;
    SimObjFactory* _simObjFactory;
    bool _attack = false;
    TruckAttack _truckAttack;
    // Private Singleton Constructor
    Model();

public:
    void setAttack(bool attack);

    static Model* _Model_Instance;

    // Copy Constructor, Need to be deleted.
    Model(const Model& rhs) = delete;

    // = Operator, Need to be deleted aswell.
    Model& operator=(const Model& rhs) = delete;

    Model& operator=(const Model&& rhs) = delete;

    // Destructor
    ~Model();

        int getTime()const {return _time;}
        vehiclePtr findVehicle(const string &name) const;
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

    void addTruck(string &startingPoint, string truckName, const routesVec & routes, timeVec &times);

    void getStatus();

    void getWarehousesStatus();

    void getVehiclesStatus();

    void createChopper(string &name, Point &startingPoint);

    void createTrooper(string &name, string &wareHouse);

    void go();
};


#endif //GAMESIMULATOR_MODEL_H
