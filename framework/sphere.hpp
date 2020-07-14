#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape {
  public:
    Sphere(glm::vec3 center, float radius, std::string name, Color color);
    float area() const override;
    float volume() const override;

  protected:
    glm::vec3 center_;
    float radius_;
};
#endif // SPHERE_HPP
