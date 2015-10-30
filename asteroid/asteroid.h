#ifndef ASTEROID_H
#define ASTEROID_H

#include "point.h"
#include "line.h"
#include "vec2.h"

class Asteroid {
  private:
    Point position;
    Vec2 velocity;
    float radius, angle, angularVelocity;

  public:
    Asteroid( const Point& pos, const Vec2& vel, float rad, float ang,
              float angVel );

    Asteroid( float x, float y, float vx, float vy, float rad, float ang,
              float angVel );

    bool collidesPoint( const Point& point );
    bool collidesLine( const Line& line );
};

#endif
