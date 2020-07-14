#define CATCH_CONFIG_RUNNER
#include <sphere.hpp>
#include <box.hpp>
#include <catch.hpp>

TEST_CASE("sphere", "[sphere]") {
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

TEST_CASE("box", "[box]") {
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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
