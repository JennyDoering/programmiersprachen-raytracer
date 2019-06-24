#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <string>
#include "color.hpp"
#include "shape.hpp"
#include <glm/vec3.hpp>

struct HitPoint {
    
    bool schnitt;
    float distance = 0;
    std::string name;
    Color hitcol{0.0f, 0.0f, 0.0f};
    glm::vec3 point3d;
    glm::vec3 richtung;
};

#endif