#ifndef RECT_H
#define RECT_H

#include "SDL2/SDL.h"

class Rect {
  private:
    SDL_Rect _sdlRect;
    double _position[2];
    double _dimension[2];
    double _velocity[2];
    Uint32 _color;

  public:
    Rect( double (* pos)[ 2 ], double (* dimen)[ 2 ] );
    Rect( double (* pos)[ 2 ], double (* dimen)[ 2 ], Uint32 color );
    Rect( double (* pos)[ 2 ], double (* dimen)[ 2 ], double (* vel)[ 2 ] );
    Rect(
        double (* pos)[ 2 ],
        double (* dimen)[ 2 ],
        double (* vel)[ 2 ],
        Uint32 color
    );

    void getPosition( double (* pos)[ 2 ] );
    void setPosition( double (* newPos)[ 2 ] );
    
    void getVelocity( double (* vel)[ 2 ] );
    void setVelocity( double (* newVel)[ 2 ] );

    void move( double (* delta)[ 2 ] );
    void moveFromVelocity();

    void draw( SDL_Surface *target );
};

#endif
