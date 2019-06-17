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

  Sphere k1 = Sphere(float {2.0f}, glm::vec3 {5.0f, 1.0f, 3.0f});
  REQUIRE(Approx(k1.area()) == 16 * M_PI); 
  REQUIRE(Approx(k1.volume()) == 33.5103f);

  Sphere k2 = Sphere(float {10.0f}, glm::vec3 {8.0f, 4.0f, 6.0f});
  REQUIRE(Approx(k2.area()) == 400 * M_PI); 
  REQUIRE(Approx(k2.volume()) == 4188.7902f);

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
