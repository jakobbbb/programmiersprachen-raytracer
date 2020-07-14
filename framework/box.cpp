#include "box.hpp"
#include <cmath>

Box::Box(glm::vec3 min, glm::vec3 max) :
  min_{min}, max_{max} {}

float Box::area() const {
  float dx = min_.x - max_.x;
  float dy = min_.y - max_.y;
  float dz = min_.z - max_.z;
  return std::abs(2 * dx * dy) + std::abs(2 * dx * dz) + std::abs(2 * dy * dz);
}

float Box::volume() const {
  return std::abs((min_.x - max_.x) * (min_.y - max_.y) * (min_.z - max_.z));
}
