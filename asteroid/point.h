#ifndef POINT_H
#define POINT_H

#include "iostream"

class Point {
  public:
    float x, y;
    Point( float x, float y );

    float distance( const Point& p );

    void print();
};

#endif
