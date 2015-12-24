#ifndef LINE_OBJECT_3_H
#define LINE_OBJECT_3_H

#include <vector>
#include <glm/glm.hpp>

class LineObject3 {
  public:
    LineObject3(glm::vec3 const*, int, glm::vec4);
    virtual ~LineObject3() {}
    std::vector<glm::vec3> vertices;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::vec4 color;
    void dax(float);
    void day(float);
    int vboSize();
    void vbo(float*);
    void transform(float*);
};

#endif
