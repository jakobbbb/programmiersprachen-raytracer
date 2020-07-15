#ifndef RAY_HPP
#define RAY_HPP

#include <glm/glm.hpp>

struct Ray {
  glm::vec3 origin{0.f, 0.f, 0.f};
  glm::vec3 direction{0.f, 0.f, 0.f};
};

#endif  // RAY_HPP
