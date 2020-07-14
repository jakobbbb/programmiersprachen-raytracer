#include "sphere.hpp"
#include <cmath>

Sphere::Sphere(glm::vec3 center, float radius, std::string name, Color color) :
  Shape{name, color},
  center_{center},
  radius_{radius} {}

float Sphere::area() const {
  return std::abs(4 * M_PI * std::pow(radius_, 2));
}

float Sphere::volume() const {
  return std::abs(4.f/3.f * M_PI * std::pow(radius_, 3));
}
