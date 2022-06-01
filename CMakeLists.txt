cmake_minimum_required(VERSION 3.22)
project(GameSimulator)

set(CMAKE_CXX_STANDARD 11)

add_executable(GameSimulator main.cpp View.cpp View.h Model.cpp Model.h SimulatorObj.cpp SimulatorObj.h
        Vehicle.cpp Vehicle.h Warehouse.cpp Warehouse.h SimObjFactory.cpp SimObjFactory.h
        Controller.h Controller.cpp Chopper.cpp Chopper.h Truck.cpp Truck.h Trooper.cpp Trooper.h Geometry.cpp Geometry.h)
