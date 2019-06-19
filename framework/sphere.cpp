#include "sphere.hpp"
#include <cmath>

Sphere::Sphere(): Shape(), radius_(1.0f), mpoint_(0.0f, 0.0f, 0.0f) {}
Sphere::Sphere(std::string name, Color color, float radius, glm::vec3 mpoint) : Shape(name, color), radius_(radius), mpoint_(mpoint) {}

float Sphere::area() const {
    return (4.0f * M_PI * (radius_ * radius_));
}

float Sphere::volume() const {
    return ((4.0f/3.0f) * M_PI * (radius_ * radius_ * radius_));
}