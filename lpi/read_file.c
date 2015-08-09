#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_READ 128

int main( int argc, char *argv[] ) {
  int fd,
      read_value,
      num_read
  ;

  char buffer[ MAX_READ + 1 ];

  if ( argc > 2 ) {
    printf( "Wrong number of args, must be 1 or none.\n" );
    return 1;
  }

  if ( argc == 1 ) {
    // set fd to stdin
    fd = STDIN_FILENO;
  } else {
    // set fd to the argument, argv[ 1 ] should be a path
    fd = open( argv[ 1 ], O_RDONLY );
    if ( fd == -1 ) {
      printf( "Error opening file, %s.\n", argv[ 1 ] );
      return 1;
    }
  }


  while ( (num_read = read( fd, buffer, MAX_READ )) != 0 ) {
    buffer[ num_read ] = '\0';
    printf( "%s", buffer );
  }

  printf( "\n" );

  return 0;
}