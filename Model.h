
#ifndef GAMESIMULATOR_MODEL_H
#define GAMESIMULATOR_MODEL_H

#include "SimObjFactory.h"
#include "vector"
#include <memory>

struct MyException:public exception{
    explicit MyException(const string& msg)
    {cerr << msg << endl;}
};

struct ExitException:public exception{
    explicit ExitException(const string& msg)
    {cerr << msg << endl << "Exiting Program" << endl;
        exit(1);}
};

using namespace std;
using vehiclePtr = shared_ptr<Vehicle> ;
using warehousePtr = shared_ptr<Warehouse> ;
using simuPtr = shared_ptr<SimulatorObj>;
using timeVec = vector< pair<string,string> >;
using routesVec = vector < pair<string, pair<double, int> > >;

/**
 * Singleton Object
 * receive and gather all the information needed in order to run the simulation
 * was no need to implement the big 5.
 * **/

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

    // Given Vehicle name, the function returns smart pointer of the Vehicle.
    vehiclePtr findVehicle(const string &name) const;

    // Given Warehouse name, the function returns smart pointer of the Warehouse.
    warehousePtr findWareHouse(const string& name) const;

    // After given valid parameters, the function implements them into the given Chopper.
    void course(double deg, double speed, string& vehicleName) const;

    // After given valid parameters, the function implements them into the given *Vehicle*.
    void position(const string& corX, const string& corY, vehiclePtr& vehicle,int speed = 0);

    // by given proper WareHouse name, the function sends a State Trooper for it.
    void destination(const string& wareHouse, vehiclePtr& vehicle);

    // Command availble only for Chooper.
    // By given valid Truck name and valid Chooper, the Chooper tries to attack the Truck.
    // if Chooper in proper range it will succeeds -> truck will be offRoad and inventory will be
    // deleted, else Chooper will be Stopped.
    void attack(const string& truck, vehiclePtr& vehicle);

    void startAttack() const;

    // Stops the vehicle
    void stop(vehiclePtr& vehicle){vehicle->setState("Stopped");};

    // Run One hour of the game
    void go();

    // prints the status of all the WareHouses
    void getWarehousesStatus();

    // prints the status of all the Vehicles
    void getVehiclesStatus();

    /**
     * Create and Add Commands.
     * given valid input the functions below add
     * the proper SimObject into the simulation.
     *
    * **/

    void addWareHouse(string name,const Point& point, int inventory);

    void createChopper(string &name, Point &startingPoint);

    void createTrooper(string &name, string &wareHouse);

    void addTruck(string &startingPoint, string truckName, const routesVec & routes, timeVec &times);

    /**
     * Setters and Getters
     */
    static Model& get();

    vector<simuPtr>* getSimObjects() {return &_simObjects;};

    void getStatus();

    int getTime()const {return _time;}

};


#endif //GAMESIMULATOR_MODEL_H
