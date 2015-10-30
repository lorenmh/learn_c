#include "iostream"

#include "point.h"
#include "vec2.h"
#include "line.h"

int main( int argc, char* argv[] ) {
  Point p1 ( 1.0f, 1.0f );
  Point p2 ( 3.0f, 3.0f );

  Line l ( p1, p2 );

  l.print();
  std::cout << '\n';
}
