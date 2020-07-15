#include "sphere.hpp"
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

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

std::ostream& Sphere::print(std::ostream& os) const {
  os << "Sphere at " << center_ << " radius " << radius_ << ", ";
  return Shape::print(os);
}

HitPoint Sphere::intersect(Ray const& r) const {
  float distance = NAN;
  auto ray_direction = glm::normalize(r.direction);
  bool did_intersect = glm::intersectRaySphere(
      r.origin,              // rayStarting
      ray_direction,         // rayNormalizedDirection
      center_,               // sphereCenter
      std::pow(radius_, 2),  // sphereRadiusSquered
      distance               // intersectionDistance
      );
  return HitPoint{did_intersect,
                  distance,
                  name_,
                  color_,
                  r.origin + (distance * ray_direction), // intersection_point
                  ray_direction};
}
