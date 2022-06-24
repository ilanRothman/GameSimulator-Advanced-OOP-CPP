
#include "View.h"

void View::print() const {
  int corX,corY,originY,originX,size,scale,printCount;
  originY = static_cast<int>(_originY);
  originX = static_cast<int>(_originX);
  size = static_cast<int>(_size);
  scale = static_cast<int>(_scale);

  printCount = 0;
  corY = originY + size * scale - scale;
  printFirstLine();

  for(;corY >= originY; corY-= scale) { // Row Print
    cout << setw(5);

    if (!printCount)
      drawLineBegin(corY);
    else
      cout << setw(7);

    for(corX = originX; corX <= size * scale + originX - scale; corX += scale) // Col Print
      draw(corX,corY);

    cout << endl;
    printCount == 2 ? printCount = 0 : printCount++;
  }

  printCount = 0;

  for(corX = originX; corX <= size * scale + originX - scale; corX += scale)
  {
    if(!printCount)
      cout << setw(6)<< corX;

    printCount == 2 ? printCount = 0 : printCount++;
  }
  cout << endl;
}
void View::drawLineBegin(int cor) const {
  cout << cor;

  if(to_string(cor).size() == 3)
    cout << setw(1);
  else
    cout << setw(2);
}

void View::printFirstLine() const{
    cout <<  "Display size:" << to_string(getSize());
    cout << " , scale: ";
    cout << getScale();
    cout << " , origin: (" << to_string(getOriginX()) << ", "  << to_string(getOriginY()) << ")" << endl;
}

void View::draw(int corX, int corY) const {
    if(_objects.find(make_pair(corX,corY)) != _objects.end())
        cout << _objects.at(make_pair(corX,corY));
    else
        cout << ". ";
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

void View::update() {
  _objects.clear();
  int x,y;
  string name;

  for(const auto& obj:*_model.getSimObjects())
  {
    getCords(x,y,*obj->getLoc());
    name = obj->getName().substr(0,2);

    _objects.insert({make_pair(x,y),name});
  }
}

void View::getCords(int& x,int& y,const Point& p) {
    x = static_cast<int>(p.x);
    y = static_cast<int>(p.y);
    x -= x % static_cast<int>(_scale);
    y -= y % static_cast<int>(_scale);
}

void View::setDefault() {
    this->setOriginX(-10);
    this->setOriginY(-10);
    this->setSize(25);
    this->setScale(2.00);
}


