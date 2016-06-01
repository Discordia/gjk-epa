#pragma once

#include <glm/vec2.hpp>
#include <glm/fwd.hpp>

using glm::fvec2;

struct Penetration
{
    fvec2 normal;
    float depth;
};
