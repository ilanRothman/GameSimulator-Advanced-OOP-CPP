
#ifndef GAMESIMULATOR_VIEW_H
#define GAMESIMULATOR_VIEW_H
#include <iostream>

using namespace std;
class View{
    private:
        float _scale;
        int _size;
        int _originX;
        int _originY;

    public:
        View(): _scale(2.0),_size(25), _originX(-10), _originY(-10){};
        void print();

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
