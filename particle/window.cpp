#include "window.h"

#include "SDL2/SDL.h"
#include "string"

Window::Window( std::string title, int width, int height ) {
  sdlWindow = NULL;
  windowSurface = NULL;

	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		sdlWindow = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
		if ( sdlWindow == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {
			windowSurface = SDL_GetWindowSurface( sdlWindow );
		}
	}
}
