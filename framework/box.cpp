#include "box.hpp"
#include <cmath>

Box::Box() : min_{0.0f, 0.0f, 0.0f}, max_{100.0f, 100.0f, 100.0f} {}
Box::Box(glm::vec3 min_, glm::vec3 max_) : min_(min_), max_(max_) {}

float Box::area() const {

    float a = (max_.x - min_.x);
    float b = (max_.y - min_.y);
    float c = (max_.z - min_.z);
    return (2.0f * (a * b + b * c + a * c));
}

float Box::volume() const {

    float a = (max_.x - min_.x);
    float b = (max_.y - min_.y);
    float c = (max_.z - min_.z);
    return (a * b * c);
}