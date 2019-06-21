#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

// TEST_CASE("Default-Constructor Sphere", "[Aufgabe 5.2]") {
//   Sphere k1;
//   REQUIRE(k1.radius_ == 1.0f);
//   REQUIRE(k1.mpoint_.x == 0.0f);
// }

TEST_CASE("Sphere area + volume + name_ und color_", "[Aufgabe 5.2]") {

  glm::vec3 middle =  {1.0f, 0.0f, 0.0f};
  Sphere k1 = Sphere("Kugel 1", {1.0f, 0.0f, 0.0f}, float {2.0f}, glm::vec3 {5.0f, 1.0f, 3.0f});
  REQUIRE(Approx(k1.area()) == 16 * M_PI); 
  REQUIRE(Approx(k1.volume()) == 33.5103f);
  REQUIRE(k1.getName() == "Kugel 1");
  REQUIRE(k1.getColor().r == middle.r);
  REQUIRE(k1.getColor().g == middle.g);
  REQUIRE(k1.getColor().b == middle.b);

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

TEST_CASE("print Shape", "[Aufgabe 5.4]") {

  std::cout << "print Sphere (Aufgabe 5.4) \n \n";
  Sphere k3 = Sphere("Kugel 3", {1.0f, 0.0f, 0.0f}, float {2.0f}, glm::vec3 {5.0f, 1.0f, 3.0f});
  std::cout << k3;

  std::cout << "\n";

  std::cout << "print Box (Aufgabe 5.4) \n \n";
  Box q3 = Box("Quader 3", {0.0f, 1.0f, 0.0f}, glm::vec3 {2.0f, 3.0f, 4.0f}, glm::vec3 {5.0f, 6.0f, 7.0f});
  std::cout << q3;  
}

TEST_CASE("print Sphere", "[Aufgabe 5.5]") {

  std::cout << "\n";

  std::cout << "print Sphere (Aufgabe 5.5) \n \n";
  Shape* k4 = new Sphere("Kugel 4", {1.0f, 0.0f, 0.0f}, float {2.0f}, glm::vec3 {5.0f, 1.0f, 3.0f});
  std::cout << *k4; 

  delete k4;
}

TEST_CASE("print Box", "[Aufgabe 5.5]") {

  std::cout << "\n";
  
  std::cout << "print Box (Aufgabe 5.5) \n \n";
  // Box q4 = Box("Quader 4", {0.0f, 1.0f, 0.0f}, glm::vec3 {2.0f, 3.0f, 4.0f}, glm::vec3 {5.0f, 6.0f, 7.0f});
  // std::cout << q4;

  Shape* q4 = new Box("Quader 4", {0.0f, 1.0f, 0.0f}, glm::vec3 {2.0f, 3.0f, 4.0f}, glm::vec3 {5.0f, 6.0f, 7.0f});
  std::cout << *q4;

  delete q4;
}

TEST_CASE("intersect_ray_sphere", "[intersect || Aufgabe 5.6]") {
  // Ray
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f}; //1
  // ray direction has to be normalized
  // you can use:
  // v = glm::normalize(some_vector)
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};

  // Sphere
  glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
  float sphere_radius{1.0f};

  float distance = 0.0f;
  auto result = glm::intersectRaySphere(
    ray_origin, ray_direction, 
    sphere_center, 
    sphere_radius * sphere_radius, // squared radius !!!
    distance);
    REQUIRE(distance == Approx(4.0f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
