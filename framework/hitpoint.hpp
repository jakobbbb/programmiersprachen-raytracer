#ifndef HITPOINT_CPP
#define HITPOINT_CPP

#include <cmath>
#include <string>
#include <glm/glm.hpp>
#include "color.hpp"

/** Result of an intersection */
struct HitPoint {
  /** True iff the ray intersects the object. */
  bool did_intersect = false;
  /** Distance of ray origin to intersection point. */
  float distance = NAN;
  /** Name of the intersected object. */
  std::string name = "";
  /** Color of the intersected object. */
  Color color = {0.f, 0.f, 0.f};
  /** Point where the ray intersects the object. */
  glm::vec3 intersection_point = {0.f, 0.f, 0.f};
  /** Direction in which the ray intersects the object. */
  glm::vec3 intersection_direction = {0.f, 0.f, 0.f};
};

#endif  // HITPOINT_CPP
