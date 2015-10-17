#ifndef RECT_H
#define RECT_H

#include "SDL2/SDL.h"

class Rect {
  private:
    SDL_Rect sdlRect;
    short int r, g, b, a;
  public:
    Rect( int x, int y, int w, int h );
    Rect( int x, int y, int w, short int h,
          short int r, short int g, short int b, short int a
    );
};

#endif
