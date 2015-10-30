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
