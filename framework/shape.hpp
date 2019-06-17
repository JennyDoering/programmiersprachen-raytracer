#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"

class Shape{
    public:
        Shape();
        Shape(std::string name_, Color color_);
        virtual float area() const = 0; // Oberfläche des Objekts
        virtual float volume() const = 0; // Volumen des Objekts

    private:
        Color color_;
        std::string name_;
};

#endif 