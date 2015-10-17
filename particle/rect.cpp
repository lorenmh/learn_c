#include "rect.h"

#include "SDL2/SDL.h"

Rect::Rect( int x, int y, int w, int h ) {
  sdlRect.x = x;
  sdlRect.y = y;
  sdlRect.w = w;
  sdlRect.h = h;
}

Rect::Rect( int x, int y, int w, int h,
            short int r, short int g, short int b, short int a ) {
  sdlRect.x = x;
  sdlRect.y = y;
  sdlRect.w = w;
  sdlRect.h = h;
}
