#define CATCH_CONFIG_RUNNER

#include <catch.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <iostream>
#include <memory>

#include <box.hpp>
#include <sphere.hpp>

TEST_CASE("sphere: area, volume", "[sphere]") {
  GIVEN("a sphere") {
    Sphere s{{1, -1, 2}, 4.2, "Horst", {0, 1, 1}};
    REQUIRE(Approx(221.671) == s.area());
    REQUIRE(Approx(310.339) == s.volume());
  }
  GIVEN("a sphere with radius 0") {
    Sphere s{{1, -1, 2}, 0, "Horst", {0, 1, 1}};
    REQUIRE(0 == s.area());
    REQUIRE(0 == s.volume());
  }
  GIVEN("a sphere with negative radius") {
    Sphere s{{1, -1, 2}, -4.2, "Horst", {0, 1, 1}};
    REQUIRE(Approx(221.671) == s.area());
    REQUIRE(Approx(310.339) == s.volume());
  }
}

TEST_CASE("box: area, volume", "[box]") {
  glm::vec3 p{-1, -2, -5};
  glm::vec3 q{0, 4, 2};
  GIVEN("a box defined by points `p` and `q`") {
    Box b{p, q, "Horst", {0, 1, 1}};
    REQUIRE(Approx(110) == b.area());
    REQUIRE(Approx(1 * 6 * 7) == b.volume());
  }
  GIVEN("the same box, but with `p` and `q` swapped") {
    Box b{q, p, "Horst", {0, 1, 1}};
    REQUIRE(Approx(110) == b.area());
    REQUIRE(Approx(1 * 6 * 7) == b.volume());
  }
  GIVEN("an infinitely small box") {
    Box b{{0, 0, 0}, {0, 0, 0}, "Horst", {0, 1, 1}};
    REQUIRE(0 == b.area());
    REQUIRE(0 == b.volume());
  }
  GIVEN("a plane") {
    Box b{{-42, -42, 0}, {0, 0, 0}, "Horst", {0, 1, 1}};
    REQUIRE(Approx(2 * 42 * 42) == b.area());
    REQUIRE(0 == b.volume());
  }
}

TEST_CASE("shapes: print", "[shape]") {
  GIVEN("a box") {
    Box b{{0, 0, 0}, {1, 1, 1}, "Bjarne", {1, 1, 1}};
    std::ostringstream os;
    os << b;
    REQUIRE("Box from (0,0,0) to (1,1,1), named \"Bjarne\", color (1,1,1)\n" ==
            os.str());
  }
  GIVEN("a sphere") {
    Sphere s{{0, 0, 0}, 1, "Bjarne", {1, 1, 1}};
    std::ostringstream os;
    os << s;
    REQUIRE("Sphere at (0,0,0) radius 1, named \"Bjarne\", color (1,1,1)\n" ==
            os.str());
  }
}

TEST_CASE("intersect_ray_sphere", "[intersect]") {
  // Ray
  glm::vec3 ray_origin{0.f, 0.f, 0.f};
  glm::vec3 ray_direction{0.f, 0.f, 1.f}; // normalized!

  // Sphere
  glm::vec3 sphere_center{0.f, 0.f, 5.f};
  float sphere_radius = 1.f;

  float distance = 0.f;
  auto result = glm::intersectRaySphere(
      ray_origin, ray_direction,
      sphere_center,
      sphere_radius * sphere_radius,
      distance);
  REQUIRE(distance == Approx(4.f));

  Color purple{0.42f, 0.09f, 0.59f};
  Sphere s{sphere_center, sphere_radius, "Bob", purple};
  Ray r{ray_origin, ray_direction * 4.2f};  // use non-normalized direction
  auto hitpoint = s.intersect(r);
  REQUIRE(hitpoint.did_intersect);
  REQUIRE(hitpoint.distance == Approx(4.f));
  REQUIRE(hitpoint.name == "Bob");
  REQUIRE(hitpoint.color == purple);
  REQUIRE(hitpoint.intersection_point ==
          ray_origin + (distance * ray_direction));
  REQUIRE(hitpoint.intersection_direction == ray_direction);
}

void task7() {
  Color red{255, 0, 0};
  glm::vec3 position{0.f, 0.f, 0.f};

  std::shared_ptr<Sphere> s1 =
      std::make_shared<Sphere>(position, 1.2f, "sphere0", red);
  std::shared_ptr<Shape> s2 =
      std::make_shared<Sphere>(position, 1.2f, "sphere1", red);

  s1->print(std::cout << "s1: ");
  s2->print(std::cout << "s2: ") << "\n";
}

int main(int argc, char *argv[]) {
  task7();
  return Catch::Session().run(argc, argv);
}
