#include "iostream"

#include "point.h"
#include "vec2.h"
#include "line.h"

int main( int argc, char* argv[] )
{
  Point p1 ( 0.0f, 0.0f );
  Point p2 ( 0.0f, 1.0f );

  Point p3 ( 2.0f, 2.0f );

  Line l ( p1, p2 );

  l.print();

  std::cout << '\n';
  std::cout << p3.distance( l ) << '\n';
}
