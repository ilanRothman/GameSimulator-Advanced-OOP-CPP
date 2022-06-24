#include "View.h"
#include "Model.h"
#include "vector"
#include <iostream>
#include <sstream>
#include "map"
#include <fstream>
#include <algorithm>
#include <iomanip>

struct InvalidArgs{
    explicit InvalidArgs(const string& msg)
    {cerr << msg << endl;}
};

using viewPtr = shared_ptr<View>;

using namespace std;
/** Controller
This class is responsible for controlling the Model and View as part of the MVC design pattern.
All according to interactions with the user.
was no need to implement the big 5.
**/

class Controller {
public:
    Controller(int argc, char **argv);

    void getCommand(); // gets the command form the user.

    void checkWareHouse(); // checks the warehouse file and creates the warehouse objects.


    // creates View object, runs the program by accepting user commands, then destroys View object
    void run();

private:
    map<string, int> _commandsMap; // holds all the possible commands.
    Model &_model; // the model object of the program.
    viewPtr _view; // the view object of the program.
    vector<string> _files; // holds all the files given to the program.

    void analyzeCmd(string &command); // checks for the type of the command and call the correct command function.

    void exitCmd() const;

    void vehicleCmd(stringstream &ss, string &vehicleName);

    void mapInit(); // initializes the command map.

    void checkTrucks(); // checks the trucks file and creates the trucks object.

    int getFirstTruckIndex(); // for parsing the truck file.

    double getTime( string &startTime, string &endTime, string & leaveTime); // parsing the time from the truck file.

    void parseLine(string &line, string &nextStop, string &arriveTime, int &crates, string &leaveTime); // parsing the lines from truck file.

    void parseFirstLine(string &line, int index, string &truckName, string &startingPoint, ifstream &truckFile); // parsing the first line from truck file.
};