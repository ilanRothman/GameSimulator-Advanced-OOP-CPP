

#include "Controller.h"

Controller::Controller(int argc, char** argv):_commandsMap(),_model(Model::get()),_view(make_shared<View>()),_files() {
  _files.insert(_files.end(),argv, argv + argc);
  checkWareHouse(); // check and add the warehouses.
  checkTrucks(); // check and add the trucks.
  mapInit();
  cout << fixed << showpoint;
  cout << setprecision(3);
}

void Controller::getCommand() {

  string command;

  cout << "Time " << _model.getTime() << " Enter Command " << endl;

  getline(cin,command);

  analyzeCmd(command);
}

void Controller::analyzeCmd(string& command) {
    string cmd;
    stringstream ss(command);

    if (command == "exit")
        exit(0);

    ss >> cmd; // getting the first command
    try
    {
        if (_model.findVehicle(cmd)) { // if first word in the command is vehicle name
            vehicleCmd(ss, cmd);
            return;
        }
        doCommand(ss, cmd);
    }
    catch(MyException& e){}
    catch(ExitException& e){}
    catch(exception &e)
    {
        cerr << "Invalid Arguments"<< endl;
    }

}

void Controller::run() {

    while (true){
        _view->update();
        getCommand();
    }

}

void Controller::vehicleCmd(stringstream& ss, string& vehicleName) {
    string cmd;
    ss >> cmd;

    vehiclePtr vehicle = _model.findVehicle(vehicleName);
    if (!vehicle)
        throw MyException("Vehicle Not Found");

    switch (_commandsMap.at(cmd)) {
        case 0: // Course
        {
         if(vehicle->getType() != "Chopper")
            throw MyException("Function only valid for Choppers");

         int deg, speed;

          ss >> deg >> speed;
          deg = (450 - deg) % 360;
            if(speed > 170)
              throw MyException("Maximum speed for Chopper is 170 KM/H");

          _model.course(deg, speed, vehicleName);
          break;
        }

        case 1: // Position
        {
          string x, y, speed;

          ss >> x >> y;

          stoi(x); // checking if valid input
          stoi(y);

          if (vehicle->getType() == "Chopper") {
            ss >> speed;
            if(stoi(speed) > 170)
                throw MyException("Maximum speed for Chopper is 170 KM/H");

             _model.position(x, y, vehicle,stoi(speed));
             return;
          }
          _model.position(x, y, vehicle);
          break;
        }

        case 2: // Destination
        {
          string wareHouse;

          ss >> wareHouse;
          if (!_model.findWareHouse(wareHouse))
            throw MyException("WareHouse Not Found");

          _model.destination(wareHouse, vehicle);
          break;
        }

        case 3: // Attack
        {
          string truckName;

          ss >> truckName;

          _model.attack(truckName,vehicle);
          break;
        }

        case 4: // Stop
        {
            _model.stop(vehicle);
            break;
        }
      }
}

void Controller::checkWareHouse() {
  string line, name, corX, corY, file;
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
        ss >> name >> corX >> corY >> inventory;
        name = name.substr(0, name.size() - 1);
        corX = corX.substr(1, corX.size() - 2);
        corY = corY.substr(0, corY.size() - 2);
        Point warePoint(stof(corX), stof(corY));
        _model.addWareHouse(name,warePoint,inventory);
      }

      catch (...){ // catching stof exception
          cerr << "Invalid WareHouse file" << endl;
          exit(1);
      }
    }

  _model.addWareHouse("Frankfurt",Point(40,10),100000);
}

void Controller::doCommand(stringstream& ss, string &cmd) {

        switch (_commandsMap.at(cmd)) {
            case 5: {
                _view->setDefault();
                break;
            }
            case 6: {
                int size;
                ss >> size;
                if(ss.fail())
                    throw MyException("Not an integer");

                if(size < 6 || size > 30)
                    throw MyException("This size is not allowed.");

                _view->setSize(size);
                break;
            }
            case 7: {
                float scale;
                ss >> scale;
                if(scale < 0)
                    throw MyException("Map scale must be positive.");
                _view->setScale(scale);
                break;
            }
            case 8: {
                int orgX;
                int orgY;
                ss >> orgX >> orgY;

                if(ss.fail())
                    throw MyException("Not an integer");

                _view->setOriginX(orgX);
                _view->setOriginY(orgY);
                break;
            }
            case 9: {
                _view->print();
                break;
            }
            case 10: {
                _model.getStatus();
                break;
            }
            case 11: {
                string vehicleName, type, corX, corY, startWarehouse;
                ss >> vehicleName >> type;

                if (vehicleName.size() > 12)
                    throw MyException("Vehicle name too long");

                if (type == "Chopper") {
                    ss >> corX >> corY;
                    if(corX[0] != '(' || corY[corY.size()-1] != ')')
                        throw MyException("Not correct format");
                    corX = corX.substr(1, corX.size() - 2);
                    corY = corY.substr(0, corY.size() - 1);
                    Point startPoint(stof(corX), stof(corY));
                    _model.createChopper(vehicleName, startPoint);
                    break;
                }
                ss >> startWarehouse;

                _model.createTrooper(vehicleName, startWarehouse);
                break;
            }
            case 12:{
                _model.go();
            }
        }
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
  _commandsMap.insert({"status",10});
  _commandsMap.insert({"create",11});
  _commandsMap.insert({"go",12});
}

void Controller::checkTrucks() {
    string line, truckName, nextStop, arriveTime, leaveTime, prevLeaveTime, startingPoint;
    int index, crates = 0;
    double time;
    vector < pair<string, pair<double, int> > > routes; // hold the rout of the truck.
    vector< pair<string,string> > times; // holds arrive times and leave times.

    index = getFirstTruckIndex(); // gets the truck file index.

    while(index != _files.size()){

        ifstream truckFile(_files[index]); // getting next file.
        parseFirstLine(line ,index, truckName, startingPoint, truckFile); // name and first line.
        stringstream ss(line);
        ss >> startingPoint;
        prevLeaveTime = "00:00";

        while (getline(truckFile,line)){
            parseLine(line, nextStop, arriveTime, crates, leaveTime);
            _model.findWareHouse(nextStop);
            time = getTime(prevLeaveTime,arriveTime , leaveTime); // calculate travel time to dest.
            prevLeaveTime = leaveTime;
            routes.emplace_back(nextStop, make_pair(time,crates)); //adds next destination in correct order.
            times.emplace_back(arriveTime,leaveTime);
        }
        _model.addTruck(startingPoint, truckName, routes, times);
        index++;

    }
}

int Controller:: getFirstTruckIndex(){
    int index = 0;
    for(auto & _file : _files) {
        index++;
        if (_file == "-t")
            return index; // index is now on first truck file.
    }
    return index;
}

double Controller::getTime( string &startTime, string &endTime, string & leaveTime) {
    startTime.erase(remove(startTime.begin(), startTime.end(), ':'), startTime.end());
    endTime.erase(remove(endTime.begin(), endTime.end(), ':'), endTime.end());
    leaveTime.erase(remove(leaveTime.begin(), leaveTime.end(), ':'), leaveTime.end());
    int sTime = stoi(startTime);
    int eTime = stoi(endTime);
    // turning times into minutes
    int first_time_min = sTime / 100 * 60 + sTime % 100;
    int second_time_min = eTime / 100 * 60 + eTime % 100;
    double diff_time_min = second_time_min - first_time_min;
    return diff_time_min / 60;
}

void Controller::parseLine(string &line, string &nextStop, string &arriveTime, int &crates, string &leaveTime) {
    std::replace( line.begin(), line.end(), ',', ' ');
    stringstream ss(line);
    ss >> nextStop >> arriveTime >> crates >> leaveTime;
}

void Controller::parseFirstLine(string& line, int index, string &truckName, string &startingPoint, ifstream &truckFile) {
    truckName = _files[index].substr(0,_files[index].size()-4); // name of truck
    getline(truckFile,line);
    std::replace( line.begin(), line.end(), ',', ' ');
}



