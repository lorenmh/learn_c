#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_W = 640;
const int SCREEN_H = 480;

int main( int argc, char *argv[] ) {
  printf( "Hello" );

  SDL_Window *window = NULL;

  SDL_Surface *screenSurface = NULL;

  if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not be initialized, %s\n", SDL_GetError() );
    return 1;
  }

  window = SDL_CreateWindow(
      "Window Name", 
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_W,
      SCREEN_H,
      SDL_WINDOW_SHOWN
  );

  if ( window == NULL ) {
    printf( "Window could not be created, %s\n", SDL_GetError() );
    return 1;
  }

  screenSurface = SDL_GetWindowSurface( window );

  SDL_FillRect(
      screenSurface,
      NULL,
      SDL_MapRGB(
        screenSurface->format,
        0xFF,
        0xFF,
        0xFF
      )
  );

  SDL_UpdateWindowSurface( window );

  SDL_Delay( 2000 );

  SDL_DestroyWindow( window );

  SDL_Quit();

  return 0;
}
