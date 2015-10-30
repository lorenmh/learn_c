#ifndef LINE_H
#define LINE_H

#include "iostream"

#include "point.h"

class Line {
  public:
    Point p1, p2;
    Line( const Point& p1, const Point& p2 );
    Line( float x1, float y1, float x2, float y2 );

    float distance( const Point& p ); 

    void print();
};

#endif
