#include <pthread.h>
#include <stdio.h>


void *threadedFunction( void *arg ) {
  int i = *((int *) arg);
  printf("Value: %d\n", i);

  return NULL;
}

int main( int argc, char *argv[] ) {
  pthread_t t1, t2;

  int t1Val = 1,
      t2Val = 2
  ;

  pthread_create( &t1, NULL, threadedFunction, &t1Val );
  pthread_create( &t2, NULL, threadedFunction, &t2Val );

  pthread_join( t1, NULL );
  pthread_join( t2, NULL );
}
