#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <glm/glm.hpp>

class Shape {
  public:
    Shape(glm::vec2 const*, short, glm::vec4);
    virtual ~Shape() {}
    std::vector<glm::vec2> points;
    glm::vec2 position;
    glm::vec4 color;
    float rotation;
    glm::vec2 scale;
    int size();
    int sizeColors();
    void vertices(float*);
    void colors(float*);
    glm::mat3 transform();
};

#endif
