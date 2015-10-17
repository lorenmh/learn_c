#include "window.h"
#include "rect.h"

#include <iostream>
#include "SDL2/SDL.h"

int main( int argc, char **argv ) {
  Uint8 bgRgb[] = { 255, 0, 0 };
  Window window( "This is the title", 1000, 1000, &bgRgb );

  double rectPosition[ 2 ];
  double rectDimension[ 2 ];
  double rectVelocity[ 2 ];

  rectPosition[ 0 ] = 20.0;
  rectPosition[ 1 ] = 20.0;
  
  rectDimension[ 0 ] = 20.0;
  rectDimension[ 1 ] = 20.0;

  rectVelocity[ 0 ] = 0.05;
  rectVelocity[ 1 ] = 0.05;

  Rect rect( &rectPosition, &rectDimension, &rectVelocity );
 
  bool quit = false;
  int counter = 0;

  while (!quit) {
    rect.moveFromVelocity();

    window.draw();
    rect.draw( window.surface );
    window.update();

    if ( (++counter) > 5000 ) {
      quit = true;
    }
  }


}
