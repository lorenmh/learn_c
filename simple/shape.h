#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <glm/glm.hpp>

class Shape {
  public:
    Shape(glm::vec2 const*, short);
    virtual ~Shape() {}
    std::vector<glm::vec2> points;
    glm::vec2 position;
    float rotation;
    glm::vec2 scale;
    int size();
    int sizeLines();
    void lines(float*);
    void triangleVertices(float*);
    void triangleStripVertices(float*);
    glm::mat3 transform();
};

#endif
