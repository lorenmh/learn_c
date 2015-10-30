#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line {
  public:
    Point p1, p2;

    inline Line( Point _p1, Point _p2 )
      : p1( _p1.x, _p1.y ),
        p2( _p2.x, _p2.y )
    {};
};

#endif
