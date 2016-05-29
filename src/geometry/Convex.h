#pragma once

#include <glm/vec2.hpp>
#include <math/Transform2.h>

using glm::dvec2;

enum ConvexType
{
    CIRCLE,
    TRIANGLE,
    RECTANGLE,
    POLYGON
};

class Convex
{
public:

    //!
    //!
    //!
    Convex(const ConvexType convexType)
        : convexType(convexType)
    {}

    //!
    //!
    //!
    virtual ~Convex() {}

    //!
    //!
    //!
    const ConvexType& getType() const { return convexType; }

    //!
    //!
    //!
    virtual const dvec2& getCenter() const = 0;

    //!
    //!
    //!
    virtual const dvec2 getFarthestPoint(const dvec2 direction, const Transform2& transform) const = 0;


private:

    //!
    const ConvexType convexType;
};

