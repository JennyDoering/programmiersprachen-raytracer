#include "shape.hpp"



Shape::Shape(std::string const& name_, Color const& color_) : name_(name_), color_(color_) {}

std::string const& Shape::getName() {
    return name_;
}

Color const& Shape::getColor() {
    return color_;
}

std::ostream& Shape::print(std::ostream& os) const {
    os << "Name: " << name_ << ", \nFarbe: (" << color_.r << ", " << color_.g << ", " << color_.b << ") \n";
    return os; 
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
    return s.print(os);
}