#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

// TEST_CASE("Default-Constructor Sphere", "[Aufgabe 5.2]") {
//   Sphere k1;
//   REQUIRE(k1.radius_ == 1.0f);
//   REQUIRE(k1.mpoint_.x == 0.0f);
// }

TEST_CASE("Sphere area + volume", "[Aufgabe 5.2]") {

  Sphere k1 = Sphere("Kugel 1", {1.0f, 0.0f, 0.0f}, float {2.0f}, glm::vec3 {5.0f, 1.0f, 3.0f});
  REQUIRE(Approx(k1.area()) == 16 * M_PI); 
  REQUIRE(Approx(k1.volume()) == 33.5103f);

  Sphere k2 = Sphere("Kugel 2", {1.0f, 1.0f, 0.0f},float {10.0f}, glm::vec3 {8.0f, 4.0f, 6.0f});
  REQUIRE(Approx(k2.area()) == 400 * M_PI); 
  REQUIRE(Approx(k2.volume()) == 4188.7902f);
}

TEST_CASE("Box area + volume", "[Aufgabe 5.2]") {

  Box q1 = Box("Quader 1", {0.0f, 1.0f, 0.0f}, glm::vec3 {2.0f, 3.0f, 4.0f}, glm::vec3 {5.0f, 6.0f, 7.0f});
  REQUIRE(Approx(q1.area()) == 54.0f);
  REQUIRE(Approx(q1.volume()) == 27.0f);

  Box q2 = Box("Quader 2", {0.0f, 1.0f, 1.0f}, glm::vec3 {4.0f, 1.0f, 6.0f}, glm::vec3 {1.0f, 2.0f, 3.0f});
  REQUIRE(Approx(q2.area()) == 30.0f);
  REQUIRE(Approx(q2.volume()) == 9.0f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
