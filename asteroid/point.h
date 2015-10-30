#ifndef POINT_H
#define POINT_H

#include "iostream"
class Line;

class Point {
  public:
    float x, y;
    Point( float x, float y );

    float distance( const Point& p );
    float distance( const Line& l );

    void print();
};

#endif
