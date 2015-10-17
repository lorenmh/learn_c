#include "rect.h"

#include "SDL2/SDL.h"

const int DEFAULT_COLOR = 0xffff;


Rect::Rect( double (* pos)[ 2 ], double (* dimen)[ 2 ] ) {

  _position[ 0 ] = (* pos)[ 0 ];
  _position[ 1 ] = (* pos)[ 1 ];

  _dimension[ 0 ] = (* dimen)[ 0 ];
  _dimension[ 1 ] = (* dimen)[ 1 ];

  _color = DEFAULT_COLOR;
}

Rect::Rect( double (* pos)[ 2 ], double (* dimen)[ 2 ], Uint32 color ) 
    : Rect( pos, dimen ) {
  _color = color;
}

Rect::Rect( double (* pos)[ 2 ], double (* dimen)[ 2 ], double (* vel)[ 2 ] )
    : Rect( pos, dimen, DEFAULT_COLOR ) {
  _velocity[ 0 ] = (* vel)[ 0 ];
  _velocity[ 1 ] = (* vel)[ 1 ];
}


Rect::Rect(
    double (* pos)[ 2 ],
    double (* dimen)[ 2 ],
    double (* vel)[ 2 ],
    Uint32 color
) : Rect( pos, dimen, vel ){
  _color = color;
}


void Rect::setPosition( double (* newPos)[ 2 ] ) {
  _position[ 0 ] = (* newPos)[ 0 ];
  _position[ 1 ] = (* newPos)[ 1 ];
}

void Rect::getPosition( double (* pos)[ 2 ] ) {
  (* pos)[ 0 ] = _position[ 0 ];
  (* pos)[ 1 ] = _position[ 1 ];
}

void Rect::setVelocity( double (* newVel)[ 2 ] ) {
  _velocity[ 0 ] = (* newVel)[ 0 ];
  _velocity[ 1 ] = (* newVel)[ 1 ];
}

void Rect::getVelocity( double (* vel)[ 2 ] ) {
  (* vel)[ 0 ] = _velocity[ 0 ];
  (* vel)[ 1 ] = _velocity[ 1 ];
}

void Rect::move( double (* delta)[ 2 ] ) {
  _position[ 0 ] += (* delta)[ 0 ];
  _position[ 1 ] += (* delta)[ 1 ];
}

void Rect::moveFromVelocity() {
  move( &_velocity );
}

void Rect::draw( SDL_Surface *target ) {
  _sdlRect.x = (Uint16) _position[ 0 ];
  _sdlRect.y = (Uint16) _position[ 1 ];
  _sdlRect.w = (Uint16) _dimension[ 0 ];
  _sdlRect.h = (Uint16) _dimension[ 1 ];

  SDL_FillRect( target, &_sdlRect, _color );
}
