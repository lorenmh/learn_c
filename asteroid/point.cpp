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

float Point::distance( const Line& l )
{
  Point p1 = l.p1;
  Point p2 = l.p2;

  return ( 
    (
      std::abs(
        ( ( p2.y - p1.y ) * x ) -
        ( ( p2.x - p1.x ) * y ) +
        ( p2.x * p1.y ) -
        ( p2.y * p1.x )
      )
    ) / (
      std::sqrt(
        std::pow( p2.y - p1.y, 2 ) +
        std::pow( p2.x - p1.x, 2 )
      )
    )
  );
}

void Point::print()
{
  std::cout << "<Point (" << x << ", " << y << ")>";
}
