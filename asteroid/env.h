#ifndef ENV_H
#define ENV

#include <vector>
#include <asteroid.h>

class Env {
  private:
    std::vector<Asteroid> asteroids;
    float width, height;

  public:
    Env(float _width, float _height);

}

#endif
