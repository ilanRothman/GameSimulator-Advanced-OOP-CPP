
#include <fstream>
#include "Controller.h"

Controller::Controller(int argc, char** argv):_commandsMap(),_model(Model::get()),_view(make_shared<View>()),_files() {
  _files.insert(_files.end(),argv, argv + argc);
  checkWareHouse();
//checkTrucks()
  mapInit();
}

void Controller::getCommand() {

  string command;

  cout << "Time " << _model.getTime() << "Enter Command ";

  getline(cin,command);

  analyzeCmd(command);
}

void Controller::analyzeCmd(string& command) {
    string cmd;
    stringstream ss(command);

    if (command == "exit")
        exitCmd();

    ss >> cmd; // getting the first command

    if (_model.findVehicle(cmd)) // if first word in the command is vehicle name
        vehicleCmd(ss,cmd);
}

void Controller::run() {
    _view->update();
    _view->print();
//    while(true){
//        getCommand();
//    }
}

void Controller::vehicleCmd(stringstream& ss, string& vehicleName) {
    string cmd;
    ss >> cmd;
    try {

      switch (_commandsMap.at(cmd)) {
        case 0: // Course
        {
          string deg, speed;

          ss >> deg;

          if (_model.findVehicle(vehicleName)->getType() == "Chopper") {
            ss >> speed;
//            _model.course(stoi(deg), stoi(speed), vehicleName);
          }
//          _model.course(stoi(deg), vehicleName);
          break;
        }

        case 1: // Position
        {
          string x, y, speed;

          ss >> x >> y;
          if (_model.findVehicle(vehicleName)->getType() == "Chopper") {
            ss >> speed;
//            _model.position(make_pair(stof(x), stof(y)), stoi(speed), vehicleName);
          }
//          _model.position(make_pair(stof(x), stof(y)), vehicleName);
          break;
        }

        case 2: // Destination
        {
          string wareHouse;

          ss >> wareHouse;
          if (!_model.findWareHouse(wareHouse))
            throw;

//          _model.destination(wareHouse, vehicleName);
          break;
        }

        case 3: // Attack
        {
          string truckName;

            ss >> truckName;
            if(!_model.findVehicle(truckName))
              throw;

//            _model.attack(truckName,vehicleName);
            break;
        }

        case 4: // Stop
        {
            if(!_model.findVehicle(vehicleName))
              throw;

//            _model.stop(vehicleName);
            break;
        }

      }
    }

    catch(...){
      InvalidArgs("Invalid Arguments");
      return;
    }

}

void Controller::checkWareHouse() {
  string line, name, location1, location2, file;
  int inventory;
  //getting iterator to point at warehouse
  for(auto iter = _files.begin(); iter != _files.end(); iter++) {
    if (*iter == "-w") {
      file = *++iter; // iter is now on warehouse file.
      break;
    }
  }
  ifstream wareFile(file);
    while(getline(wareFile,line)){
      try {
        stringstream ss(line);
        ss >> name >> location1 >> location2 >> inventory;
        name = name.substr(0, name.size() - 1);
        location1 = location1.substr(1, location1.size() - 2);
        location2 = location2.substr(0, location2.size() - 2);
        Point warePoint(stof(location1), stof(location2));
        _model.addWareHouse(name,warePoint,inventory);
      }

      catch (...){
        InvalidArgs("Invalid Arguments");
        exitCmd();
      }
    }

  _model.addWareHouse("Frankfurt",Point(15,10),100000);
}



void Controller::exitCmd() const{
  cout << "Exiting Program";
  exit(0);
}

void Controller::mapInit()
{
  _commandsMap.insert({"course",0});
  _commandsMap.insert({"position",1});
  _commandsMap.insert({"destination",2});
  _commandsMap.insert({"attack",3});
  _commandsMap.insert({"stop",4});
  _commandsMap.insert({"default",5});
  _commandsMap.insert({"size",6});
  _commandsMap.insert({"zoom",7});
  _commandsMap.insert({"pan",8});
  _commandsMap.insert({"show",9});
}