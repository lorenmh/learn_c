#include "shape.h"

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>


// class Shape {
//   public:
//     Shape(glm::vec2 const*, short);
//     virtual ~Shape() {}
//     std::vector<glm::vec2> points;
//     glm::vec2 position;
//     float rotation;
//     glm::vec2 scale;
//     int size();
//     void lineVertices(float*);
//     void triangleVertices(float*);
//     void triangleStripVertices(float*);
//     glm::mat3 transform();
// };

Shape::Shape(glm::vec2 const* pointsArray, short size)
  : points(pointsArray, pointsArray + size)
{
}

int Shape::size()
{
  return points.size();
}

int Shape::sizeLines() {
  return 4 * size();
}

void Shape::lines(float* lines)
{
  int size = points.size();

  for (int i = 0; i < size; i++) {
    std::cout << "INDEX: " << i << "\n";
    int linesIndex = i * 4;
    lines[linesIndex] = points[i][0];
    lines[linesIndex + 1] = points[i][1];
    lines[linesIndex + 2] = points[(i + 1) % size][0];
    lines[linesIndex + 3] = points[(i + 1) % size][1];
  }
}
