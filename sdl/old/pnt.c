#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define DELAY 3000

SDL_Window *gWindow = NULL;
SDL_Surface *gWindowSurface = NULL;
SDL_Surface *gImageSurface = NULL;

bool init() {
  
  if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "Error initializing SDL, %s\n", SDL_GetError() );
    return false;
  }

  gWindow = SDL_CreateWindow(
      "SDL",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN
  );

  if ( gWindow == NULL ) {
    printf( "Error initializing window, %s\n", SDL_GetError() );
    return false;
  }

  gWindowSurface = SDL_GetWindowSurface( gWindow );

  return true;
}

bool loadMedia() {
  gImageSurface = SDL_LoadBMP( "img.bmp" );

  if ( gImageSurface == NULL ) {
    printf( "Error loading image, %s\n", SDL_GetError() );
    return false;
  }

  return true;
}

void close() {
  SDL_FreeSurface( gImageSurface );
  gImageSurface = NULL;

  SDL_DestroyWindow( gWindow );
  gWindow = NULL;

  SDL_Quit();
}

int main( int argc, char *argv[] ) {
  if ( init() && loadMedia() ) {
    SDL_BlitSurface( gImageSurface, NULL, gWindowSurface, NULL );
    SDL_UpdateWindowSurface( gWindow );
    SDL_Delay( DELAY );
    close();
    return 0;
  }
  return 1;
}
