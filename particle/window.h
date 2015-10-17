#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include "string"

class Window {
  private:
    SDL_Window *sdlWindow;
    SDL_Surface *windowSurface;
  public:
    Window( std::string, int, int );
};

#endif
