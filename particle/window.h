#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include "string"

class Window {
  private:
    SDL_Window *sdlWindow;
    Uint32 color;
  public:
    Window( std::string title, int w, int h );
    Window( std::string title, int w, int h, Uint8 (* rgb)[3] );
    SDL_Surface *surface;
    void update();
    void draw();
};

#endif
