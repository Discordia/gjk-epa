#pragma once

#include <glm/vec2.hpp>
#include <math/Transform2.h>

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
    virtual const dvec2& getCenter() const = 0;

    //!
    //!
    //!
    virtual const dvec2 getFarthestPoint(const dvec2 direction, const Transform2& transform) const = 0;


private:

};

