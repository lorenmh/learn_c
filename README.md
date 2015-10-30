```
class Asteroid {
  private:
    Point m_position;
    Velocity m_velocity;
    float m_radius, m_angle, m_angularVelocity;
  public
    bool collidesPoint( const Point& point );
    bool collidesLine( const Line& line );
};

class Point {
  public:
    Point( float x, float y );
    float x, y;
};

class Velocity {
  public:
    Point( float x, float y );
    float x, y;
};

class Line {
  public:
    Point x1, y1, x2, y2;
};
```
