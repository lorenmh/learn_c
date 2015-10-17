#include "window.h"

#include "SDL2/SDL.h"
#include "string"

const Uint8 DEFAULT_RGB[] = { 255, 0, 0 };

Window::Window( std::string title, int width, int height ) {
  sdlWindow = NULL;
  surface = NULL;
  color = 0;

	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		sdlWindow = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
		if ( sdlWindow == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {
			surface = SDL_GetWindowSurface( sdlWindow );
      color = SDL_MapRGB(
          surface->format,
          DEFAULT_RGB[0],
          DEFAULT_RGB[1],
          DEFAULT_RGB[2]
      );
		}
	}
}

Window::Window( std::string title, int width, int height, Uint8 (* rgb)[3] ) {
  sdlWindow = NULL;
  surface = NULL;
  color = 0;

	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		sdlWindow = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
		if ( sdlWindow == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {
			surface = SDL_GetWindowSurface( sdlWindow );
      color = SDL_MapRGB( surface->format, (* rgb)[0], (* rgb)[1], (* rgb)[2] );
		}
	}
}

void Window::draw() {
  SDL_FillRect( surface, NULL, color );
}

void Window::update() {
  SDL_UpdateWindowSurface( sdlWindow );
}
