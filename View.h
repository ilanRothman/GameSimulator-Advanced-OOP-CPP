
#ifndef GAMESIMULATOR_VIEW_H
#define GAMESIMULATOR_VIEW_H
#include <iostream>
#include "map"
#include "Model.h"

using namespace std;

/**
 * View class
 * Part of the MVC design pattern.
 * No need for the implementation of the "Big Five".
 * **/

class View{
    private:
        float _scale;
        int _size;
        int _originX;
        int _originY;
        map<pair<int,int>,string> _objects; // object locations.
        Model& _model;


    public:
        View(): _scale(2.0),_size(25), _originX(-10), _originY(-10), _objects(), _model(Model::get()){};

        void print() const; // prints the map.

        void update(); // updates ALL the simObject Cords

        void draw(int corX, int corY) const; // print dot or name of object.

        void drawLineBegin(int cor) const; // prints the beginning of the line.

        void printFirstLine() const; // prints the details of the map.

        void setDefault(); // resets the map settings.


    /**
    *  Setters and Getters.
    * **/

        void getCords(int& x, int& y,const Point& p);

        float getScale() const;

        void setScale(float scale);

        int getSize() const;

        void setSize(int size);

        int getOriginX() const;

        void setOriginX(int originX);

        int getOriginY() const;

        void setOriginY(int originY);

};

#endif //GAMESIMULATOR_VIEW_H
