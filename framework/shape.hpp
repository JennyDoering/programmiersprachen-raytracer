#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape{
    public:

    Shape() = default;
    virtual float area() const = 0; // Oberfläche des Objekts
    virtual float volume() const = 0; // Volumen des Objekts

};

#endif 