#ifndef MVRECT_H
#define MVRECT_H

#include "rect.h"

class MvRect : public Rect {
  private:
    typedef Rect super;
    int m_velocity[ 2 ];
  public:
    MvRect( int x, int y, int w, int h, int vx, int vy );
    MvRect( int x, int y, int w, int h, int vx, int vy, Uint32 color );
    void velocity( int (* vel)[ 2 ] ); 
    void move( int (* delta)[ 2 ] ); 
};

#endif
