#include <stdio.h>

void add_1( int &x ) {
  x += 1;
}

int main( int argc, char *argv[] ) {
  int i = 0;

  int *p = &i;

  add_1( i );

  printf( "%i\n", i );
}
