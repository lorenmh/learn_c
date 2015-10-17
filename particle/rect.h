#ifndef RECT_H
#define RECT_H

#include "SDL2/SDL.h"

class Rect {
  private:
    SDL_Rect sdlRect;
    Uint32 color;
  public:
    Rect( int x, int y, int w, int h );
    
    Rect( int x, int y, int w, int h, Uint32 color );

    void position( int (* pos)[ 2 ] );
    void setPosition( int (* newPos)[ 2 ] );

    void draw( SDL_Surface *target );
};

#endif
