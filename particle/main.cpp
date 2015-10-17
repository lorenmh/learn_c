#include "window.h"
#include "mvrect.h"
#include "rect.h"

#include <iostream>
#include "SDL2/SDL.h"

int main( int argc, char **argv ) {
  Window window( "This is the title", 200, 200 );
  SDL_Surface *bg = window.surface;

  
  MvRect rect( 20, 20, 5, 5, 1, 1 );
  
  int pos[2];
  
  rect.position( &pos );
  std::cout << pos[ 0 ] << '\n' << pos[ 1 ] << '\n' ;

  rect.draw( bg );

  // int delta[] = { 5, 5 };
  // rect.move( &delta ); 

  // rect.position( &pos );
  // std::cout << pos[ 0 ] << '\n' << pos[ 1 ] << '\n' ;


  SDL_FillRect( bg, NULL, SDL_MapRGB( bg->format, 255, 0, 0 ) );

  window.update();
}
