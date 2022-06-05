
#ifndef GAMESIMULATOR_VIEW_H
#define GAMESIMULATOR_VIEW_H
#include <iostream>
#include "map"
#include "Model.h"

using namespace std;
class View{
    private:
        float _scale;
        int _size;
        int _originX;
        int _originY;
        map<pair<int,int>,string> _objects;
        Model& _model;


    public:
        View(): _scale(2.0),_size(15), _originX(-10), _originY(-10), _objects(), _model(Model::get()){};
        void print() const;
        void update(); // updates ALL the simObject Cords
        void getCords(int& x, int& y,const Point& p);

    float getScale() const;

    void setScale(float scale);

    int getSize() const;

    void setSize(int size);

    int getOriginX() const;

    void setOriginX(int originX);

    int getOriginY() const;

    void setOriginY(int originY);

    void draw(int corX, int corY) const;

    void drawLineBegin(int cor) const;
};

#endif //GAMESIMULATOR_VIEW_H
