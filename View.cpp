
#include "View.h"

void View::print() {
  int num;
    for(int i = 0; i < _size; i++) {
      cout<< "  ";
        if(i%3 == 0){
            num = _originY + (_size * _scale) - (i+1)*_scale;
            cout << num;
            switch(to_string(num).size()) {
              case 1:
                cout << "  ";
                break;
              case 2:
                cout << " ";
                break;
              case 3:
                cout << "";
                break;
            }
        }
        else{
          cout << "   ";
        }
        for (int j = 0; j < _size; j++) {

            cout << ". ";
        }
        cout << endl;
    }
    cout << " ";
    for(int i = _size ; i >= 0; i--){
        if(i%3 == 0){
            cout << _originX + (_size * _scale) - (i+1)*_scale;
        }
        else{
            cout<< "  ";
        }
    }
}

float View::getScale() const {
    return _scale;
}

void View::setScale(float scale) {
    _scale = scale;
}

int View::getSize() const {
    return _size;
}

void View::setSize(int size) {
    _size = size;
}

int View::getOriginX() const {
    return _originX;
}

void View::setOriginX(int originX) {
    _originX = originX;
}

int View::getOriginY() const {
    return _originY;
}

void View::setOriginY(int originY) {
    _originY = originY;
}
