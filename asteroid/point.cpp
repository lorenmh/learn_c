#include "cmath"

#include "point.h"
#include "line.h"

Point::Point( float x, float y )
{
  this->x = x;
  this->y = y;
}

float Point::distance( const Point& p )
{
  return hypot( x - p.x, y - p.y );
}


void Point::print()
{
  std::cout << "<Point (" << x << ", " << y << ")>";
}
