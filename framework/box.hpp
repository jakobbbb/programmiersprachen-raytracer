#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape {
  public:
    Box(glm::vec3 min, glm::vec3 max, std::string name, Color color);
    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;

  protected:
    glm::vec3 min_;
    glm::vec3 max_;
};
#endif // BOX_HPP
