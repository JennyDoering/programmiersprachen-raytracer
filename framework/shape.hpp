#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"
#include <string>

class Shape{
    public:
        ~Shape() {};
        Shape(std::string const& name_ = "default_name", Color const& color_ = Color{0.0f, 0.0f, 0.0f} );
        std::string  const& getName();
        Color const& getColor();
        virtual float area() const = 0; // Oberfläche des Objekts
        virtual float volume() const = 0; // Volumen des Objekts
        virtual std::ostream& print(std::ostream& os) const;

    protected:
        Color color_;
        std::string name_;
};

std::ostream& operator <<(std::ostream& os, Shape const& s);

#endif 