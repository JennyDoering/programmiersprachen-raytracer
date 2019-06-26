#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include "ray.hpp"
#include "hitpoint.hpp"

class Sphere: public Shape {
    public: 
        Sphere();
        ~Sphere();
        Sphere(std::string const& name_, Color const& color_, float radius_, glm::vec3 mpoint_);
        virtual float area() const override;
        virtual float volume() const override;
        virtual std::ostream& print(std::ostream& os) const override;
        HitPoint intersect(Ray const& object, float& distance) const;

    private:
        float radius_;
        glm::vec3 mpoint_;
        Ray object;
};

#endif