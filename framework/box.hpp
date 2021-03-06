#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Box: public Shape {
    public: 
        Box();
        Box(std::string const& name_, Color const& color_, glm::vec3 min_, glm::vec3 max_);

        virtual float area() const override;
        virtual float volume() const override;
        virtual std::ostream& print(std::ostream& os) const override;

    private:
        glm::vec3 min_;
        glm::vec3 max_;
};

#endif