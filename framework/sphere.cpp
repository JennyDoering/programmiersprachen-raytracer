#include "sphere.hpp"
#include <cmath>

Sphere::Sphere(): radius_{1.0f}, mpoint_{0.0f, 0.0f, 0.0f} {}
Sphere::Sphere(std::string name_, Color color_, float radius_, glm::vec3 mpoint_) : name_(name_), color_(color_), radius_(radius_), mpoint_(mpoint_) {}

float Sphere::area() const {
    return (4.0f * M_PI * (radius_ * radius_));
}

float Sphere::volume() const {
    return ((4.0f/3.0f) * M_PI * (radius_ * radius_ * radius_));
}