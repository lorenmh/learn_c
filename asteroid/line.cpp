#include "line.h"

Line::Line( const Point& p1, const Point& p2 )
  : p1( p1.x, p1.y ),
    p2( p2.x, p2.y )
{}

Line::Line( float x1, float y1, float x2, float y2 )
  : p1( x1, y1 ),
    p2( x2, y2 )
{}

void Line::print()
{
  std::cout << "<Line (";
  p1.print();
  std::cout << ", ";
  p2.print();
  std::cout << ")>";
}
