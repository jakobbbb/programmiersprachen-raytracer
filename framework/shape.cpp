#include "shape.hpp"
#include <iostream>

Shape::Shape(std::string name, Color color) : name_{name}, color_{color} {
  std::cout << "Shape constructor called.\n";
}

Shape::~Shape() { std::cout << "Shape destructor called.\n"; }

std::ostream& Shape::print(std::ostream& os) const {
  os << "named \"" << name_ << "\", color " << color_;
  return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
  return s.print(os);
}

std::ostream& operator<<(std::ostream& os, glm::vec3 const& v) {
  return os << "(" << v.x << "," << v.y << "," << v.z << ")";
}
