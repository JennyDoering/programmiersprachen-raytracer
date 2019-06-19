#include "box.hpp"
#include <cmath>

Box::Box() : min_(0.0f, 0.0f, 0.0f), max_(100.0f, 100.0f, 100.0f) {}
Box::Box(std::string const& name, Color const& color, glm::vec3 min, glm::vec3 max) : Shape{name, color}, min_(min), max_(max) {}

float Box::area() const {

    float a = (max_.x - min_.x);
    float b = (max_.y - min_.y);
    float c = (max_.z - min_.z);
    if(a < 0.0f) {
        a = -a;
    }

    if(b < 0.0f) {
        b = -b;
    }

    if(c < 0.0f) {
        c = -c;
    }
    return (2.0f * (a * b + b * c + a * c));
}

float Box::volume() const {

    float a = (max_.x - min_.x);
    float b = (max_.y - min_.y);
    float c = (max_.z - min_.z);
    return (a * b * c);
}

std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);
    os << "Min: {" << min_.x << ", " << min_.y << ", " << min_.z << "} \n" << "Max: {" << max_.x << ", " << max_.y << ", " << max_.z << "} \n";
    return os;
}