#include "asteroid.h"
#include "point.h"
#include "vec2.h"

Asteroid::Asteroid( const Point& pos, const Vec2& vel, float rad, float ang,
                    float angVel )
  : position( pos.x, pos.y ),
    velocity( vel.x, vel.y )
{
  radius = rad;
  angle = ang;
  angularVelocity = angVel;
}

Asteroid::Asteroid( float x, float y, float vx, float vy, float rad, float ang,
                    float angVel )
  : position( x, y ),
    velocity( vx, vy )
{
  radius = rad;
  angle = ang;
  angularVelocity = angVel;
}

bool Asteroid::collidesPoint( const Point& point ) {
  return position.distance( point ) < radius;
}

bool Asteroid::collidesLine( Line line ) {
  return line.distance( position ) < radius;
}
