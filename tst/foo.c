#include <stdlib.h>
#include <stdio.h>

#include <SDL2/sdl.h>

int main( int argc, char *argv[] ) {
  SDL_Window *window;

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow(
      "My Window",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      600,
      400,
      SDL_WINDOW_OPENGL
  );

  if (window == NULL) {
    printf( "Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Delay( 5000 );

  SDL_DestroyWindow( window );

  SDL_Quit();

  return 0;
}
