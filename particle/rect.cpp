#include "rect.h"

#include "SDL2/SDL.h"

const int DEFAULT_COLOR = 0xffff00;

Rect::Rect( int x, int y, int w, int h ) {
  sdlRect.x = x;
  sdlRect.y = y;
  sdlRect.w = w;
  sdlRect.h = h;
  color = DEFAULT_COLOR;
}

Rect::Rect( int x, int y, int w, int h, Uint32 color  ) {
  sdlRect.x = x;
  sdlRect.y = y;
  sdlRect.w = w;
  sdlRect.h = h;
  color = color;
}

void Rect::setPosition( int (* newPos)[ 2 ] ) {
  sdlRect.x = (* newPos)[ 0 ];
  sdlRect.y = (* newPos)[ 1 ];
}

void Rect::position( int (* pos)[ 2 ] ) {
  (* pos)[ 0 ] = sdlRect.x;
  (* pos)[ 1 ] = sdlRect.y;
}

void Rect::draw( SDL_Surface *target ) {
  SDL_FillRect( target, &sdlRect, color );
}
