#include <iostream>

int main( int argc, char *argv[] ) {
  int one = 1;
  int two = 2;
  int three = 3;

  int *f = &one;;
  int *s = &two;

  int *&v = f;

  std::cout << (*v) << '\n';
  
  v = &three;

  std::cout << (*f) << '\n';

  return 0;
}
