#include "sphere.hpp"
#include <cmath>

Sphere::Sphere(): radius_(1.0f), mpoint_(0.0f, 0.0f, 0.0f) {}
Sphere::Sphere(std::string const& name, Color const& color, float radius, glm::vec3 mpoint) : Shape{name, color}, radius_(radius), mpoint_(mpoint) {"Aufruf des Sphere Konstruktors \n";}

float Sphere::area() const {
    return (4.0f * M_PI * (radius_ * radius_));
}

float Sphere::volume() const {
    return ((4.0f/3.0f) * M_PI * (radius_ * radius_ * radius_));
}

std::ostream& Sphere::print(std::ostream& os) const {
    Shape::print(os);
    os << "Radius: " << radius_ << "\n" << "Mittelpunkt: {" << mpoint_.x << ", " << mpoint_.y << ", " << mpoint_.z << "} \n";
    return os;
}

HitPoint Sphere::intersect(Ray const& object, float& distance) const {
    HitPoint h{};
    h.schnitt = glm::intersectRaySphere(object.origin, object.direction, mpoint_, radius_ * radius_, distance);
    if(h.schnitt == false) {
        return h;
    }
    else {
        h.distance = distance;
        h.hitcol = color_;
        h.name = name_;
        h.point3d = object.origin + distance * object.direction;
        h.richtung = object.direction;
        h.schnitt = true;
        return h;
    }
}

Sphere::~Sphere() {std::cout << "Aufruf des Sphere Destruktors \n";}
