#define CATCH_CONFIG_RUNNER

#include <catch.hpp>
#include <iostream>

#include <sphere.hpp>
#include <box.hpp>


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
    REQUIRE("Shape \"Bjarne\", color (1,1,1)\n" == os.str());
  }
  GIVEN("a sphere") {
    Sphere s{{0, 0, 0}, 1, "Bjarne", {1, 1, 1}};
    std::ostringstream os;
    os << s;
    REQUIRE("Shape \"Bjarne\", color (1,1,1)\n" == os.str());
  }
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
