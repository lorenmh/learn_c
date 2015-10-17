#include "mvrect.h"

MvRect::MvRect( int x, int y, int w, int h, int vx, int vy )
  : super( x, y, w, h ) {
    m_velocity[ 0 ] = vx;
    m_velocity[ 1 ] = vy;
}

MvRect::MvRect( int x, int y, int w, int h, int vx, int vy, Uint32 color )
  : super( x, y, w, h, color ) {
    m_velocity[ 0 ] = vx;
    m_velocity[ 1 ] = vy;
}

void MvRect::velocity( int (* vel)[ 2 ] ) {
  (* vel)[ 0 ] = m_velocity[ 0 ];
  (* vel)[ 1 ] = m_velocity[ 1 ];
}

void MvRect::move( int (* delta)[ 2 ] ) {
  int position[ 2 ];

  super::position( &position );
  
  position[ 0 ] += (* delta)[ 0 ];
  position[ 1 ] += (* delta)[ 1 ];

  super::setPosition( &position );
}
  
