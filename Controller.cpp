
#include "Controller.h"

Controller::Controller():_commandsMap(),_model(Model::get()),_view(make_shared<View>()) {
mapInit();
}

void Controller::getCommand() {

    string command;

    cout << "Time " << _model.getTime() << "Enter Command ";

    getline(cin,command);
}

void Controller::analyzeCmd(string& command) {
    string cmd;
    stringstream ss(command);

    if (command == "exit")
        exitCmd();

    ss >> cmd; // getting the first command

    if (!_model.findVehicle(cmd)) // if first word in the command is vehicle name
        vehicleCmd(command,ss);


}

void Controller::exitCmd() const{
    cout << "Exiting Program";
    exit(0);
}

void Controller::run() {
    _view->print();
//    while(true){
//        getCommand();
//    }

}

void Controller::vehicleCmd(string& command, stringstream& ss) {
    string cmd;
    ss >> cmd;

    switch (_commandsMap.at(cmd)) {
        case 1:
        {
            string deg,speed;
            ss >> deg;

            if(ss.rdbuf()->in_avail())
                ss >> speed;

            break;
        }
    }
}

void Controller::mapInit()
{
    _commandsMap.insert({"course",0});
    _commandsMap.insert({"position",1});
    _commandsMap.insert({"attack",2});
    _commandsMap.insert({"stop",3});
    _commandsMap.insert({"destination",4});
    _commandsMap.insert({"default",5});
    _commandsMap.insert({"size",6});
    _commandsMap.insert({"zoom",7});
    _commandsMap.insert({"pan",8});
    _commandsMap.insert({"show",9});
}


