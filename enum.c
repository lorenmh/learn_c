#include <stdio.h>

int main( int argc, char *argv[] ) {
  enum foo {
    BAR,
    BAZ,
    BOT
  };

  enum foo a = BAR;
  enum foo b = BAZ;
  enum foo c = BOT;

  printf( "%d, %d, %d\n", c, b, a );

  typedef enum {
    FIRST,
    SECOND,
    THIRD
  } my_type;

  my_type one = FIRST;
  my_type two = SECOND;
  my_type three = THIRD;

  printf( "%d, %d, %d\n", one, two, three );

  printf( "%d, %d, %d\n", FIRST, SECOND, THIRD );

  return 0;
}
