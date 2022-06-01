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
	Controller();
    void getCommand();


	// creates View object, runs the program by accepting user commands, then destroys View object
	void run();

private:
    map<string,int> _commandsMap;
    Model& _model;
	viewPtr _view;

    void analyzeCmd(string& command);
    void exitCmd()const;
    void vehicleCmd(string& command, stringstream& ss);
    void mapInit();

};