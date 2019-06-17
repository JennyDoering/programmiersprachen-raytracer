#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere: public Shape {
    public: 
        Sphere();
        Sphere(float radius_, glm::vec3 mpoint_);
        virtual float area() const override;
        virtual float volume() const override;

    private:
        float radius_;
        glm::vec3 mpoint_;
};

#endif