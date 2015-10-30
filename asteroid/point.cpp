#include "point.h"


Point::Point( float x, float y )
{
  this->x = x;
  this->y = y;
}

void Point::print()
{
  std::cout << "<Point (" << x << ", " << y << ")>";
}
