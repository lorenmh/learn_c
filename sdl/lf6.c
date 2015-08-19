#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define DELAY 3000

SDL_Window *gWindow = NULL;
SDL_Surface *gWindowSurface = NULL;
SDL_Surface *gImageSurface = NULL;

// prototypes
SDL_Surface *loadSurface( char *path );


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
  gImageSurface = loadSurface( "img.bmp" );

  if ( gImageSurface == NULL ) {
    printf( "Error loading image, %s\n", SDL_GetError() );
    return false;
  }

  return true;
}

SDL_Surface *loadSurface( char *path ) {
  SDL_Surface *optimizedSurface = NULL;

  SDL_Surface *loadedSurface = SDL_LoadBMP( path );

  if ( loadedSurface == NULL ) {
    printf( "Unable to load image %s: %s", path, SDL_GetError() );
  } else {
    optimizedSurface = SDL_ConvertSurface(
        loadedSurface,
        gWindowSurface->format,
        0
    );

    SDL_FreeSurface( loadedSurface );
  }

  return optimizedSurface;

}

void close() {
  SDL_FreeSurface( gImageSurface );
  gImageSurface = NULL;

  SDL_DestroyWindow( gWindow );
  gWindow = NULL;

  SDL_Quit();
}

int main( int argc, char *argv[] ) {
  if ( !init() || !loadMedia() ) { return 1; }
  
  bool quit = false;
  SDL_Event e;

  while ( !quit ) {

    while ( SDL_PollEvent( &e ) != 0 ) {

      if ( e.type == SDL_KEYDOWN ) {
        printf( 
            "[KeyDown]%c\n",
            e.key.keysym.sym
        );
      }

      if ( e.type == SDL_KEYUP ) {
        printf( 
            "[KeyUp]%c\n",
            e.key.keysym.sym
        );
      }

      if ( e.type == SDL_QUIT ) {
        quit = true;
      }
    }

    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = SCREEN_WIDTH;
    stretchRect.h = SCREEN_HEIGHT;

    SDL_BlitScaled(
        gImageSurface,
        NULL,
        gWindowSurface,
        &stretchRect
    );

    SDL_UpdateWindowSurface( gWindow );
  }

  close();
  return 0;
}
