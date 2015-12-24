#include "lineobject3.h"

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

// given 1 vertex, there will be 3 position components (x,y,z)
#define VERT_LINE_MULT 3
// given 1 vertex, there will be 4 color components (r,g,b,a)
#define VERT_COLOR_MULT 4
// the above is used to determine the size. Macro because they are constants
#define VERT_MULT (VERT_LINE_MULT * VERT_COLOR_MULT)

// class LineObject3 {
//   public:
//     LineObject3(glm::vec3 const*, short, glm::vec4);
//     virtual ~LineObject3() {}
//     std::vector<glm::vec3> vertices;
//     glm::vec3 position;
//     glm::vec3 rotation;
//     glm::vec3 scale;
//     glm::vec4 color;
//     int vboSize();
//     void vbo(float*);
//     glm::mat4 transform();
// };

LineObject3::LineShape3(
    glm::vec3 const* vertices_,
    int size_,
    glm::vec4 color_
) : vertices(vertices_, vertices_ + size_)
{
  color = color_;
}

int LineObject3::vboSize()
{
  return VERT_MULT * vertices.size();
}

void LineObject3::vbo(float* target)
{
  for (int i = 0; i < vertices.size(); i++) {
    int targetIndex = i * VERT_MULT;

    glm::vec3 vertex = vertices[i];

    // position
    target[targetIndex]   = vertex[0]; // x component
    target[++targetIndex] = vertex[1]; // y component
    target[++targetIndex] = vertex[2]; // z component
    
    // color
    target[++targetIndex] = color[0]; // r
    target[++targetIndex] = color[1]; // g
    target[++targetIndex] = color[2]; // b
    target[++targetIndex] = color[3]; // a
  }
}

glm::mat4 LineObject3::transform()
{
  // x,y,z == pitch, yaw, roll
  // glm library wants it in the order of 'Y', 'X', 'Z'
  glm::mat4 tRotation = glm::eulerAngleYXZ(
      rotation[1], // y
      rotation[0], // x
      rotation[2]  // z
  );

  glm::mat4 tScale = glm::scale(
      glm::mat4(1.0f),
      scale
  );

  glm::mat4 tTranslate = glm::translate(
      glm::mat4(1.0f),
      position
  );

  return tRotation * tScale * tTranslate;
}
