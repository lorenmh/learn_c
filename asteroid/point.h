#ifndef POINT_H
#define POINT_H

#include "iostream"

class Point {
  public:
    float x, y;
    inline Point( float x, float y ) {
      this->x = x;
      this->y = y;
    };
};

#endif
