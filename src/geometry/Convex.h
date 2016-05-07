#pragma once

#include <glm/vec2.hpp>

using glm::dvec2;

class Convex
{
public:

    //!
    //!
    //!
    Convex() {}

    //!
    //!
    //!
    virtual ~Convex() {}

    //!
    //!
    //!
    virtual dvec2 getCenter() = 0;


private:

};