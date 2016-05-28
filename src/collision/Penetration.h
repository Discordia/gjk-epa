#pragma once

#include <glm/vec2.hpp>

using glm::dvec2;

struct Penetration
{
    dvec2 normal;
    double depth;
};
