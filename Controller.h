#include "View.h"
#include "Model.h"
#include "vector"
#include <iostream>
#include <sstream>
#include "map"

struct InvalidArgs{
    explicit InvalidArgs(const string& msg)
    {cerr << msg << endl;}
};

using viewPtr = shared_ptr<View>;

using namespace std;
/* Controller
This class is responsible for controlling the Model and View according to interactions
with the user.
*/

class Controller {
public:
    Controller(int argc, char **argv);

    void getCommand();

    void checkWareHouse();


    // creates View object, runs the program by accepting user commands, then destroys View object
    void run();

private:
    map<string, int> _commandsMap;
    Model &_model;
    viewPtr _view;
    vector<string> _files;

    void analyzeCmd(string &command);

    void exitCmd() const;

    void vehicleCmd(stringstream &ss, string &vehicleName);

    void mapInit();

    void checkTrucks();

    int getFirstTruckIndex();

    double getTime( string &startTime, string &endTime);
};