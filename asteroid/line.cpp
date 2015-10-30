#include "cmath"

#include "line.h"
#include "point.h"

Line::Line( const Point& p1, const Point& p2 )
  : p1( p1.x, p1.y ),
    p2( p2.x, p2.y )
{}

Line::Line( float x1, float y1, float x2, float y2 )
  : p1( x1, y1 ),
    p2( x2, y2 )
{}

float Line::distance( const Point& p ) {
  return ( 
    (
      std::abs(
        ( ( p2.y - p1.y ) * p.x ) -
        ( ( p2.x - p1.x ) * p.y ) +
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

void Line::print()
{
  std::cout << "<Line (";
  p1.print();
  std::cout << ", ";
  p2.print();
  std::cout << ")>";
}
