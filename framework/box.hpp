#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape {
  public:
    Box(glm::vec3 min, glm::vec3 max);
    float area() const override;
    float volume() const override;

  protected:
    glm::vec3 min_;
    glm::vec3 max_;
};
#endif // BOX_HPP
