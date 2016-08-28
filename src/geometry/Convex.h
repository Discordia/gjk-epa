#pragma once

#include <glm/vec2.hpp>
#include <math/Transform2.h>

using glm::fvec2;

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

    Convex(const ConvexType convexType)
        : convexType(convexType) {}

    virtual ~Convex() {}

    const ConvexType& getType() const { return convexType; }
    virtual const fvec2& getCenter() const = 0;
    virtual const fvec2 getFarthestPoint(const fvec2 direction, const Transform2& transform) const = 0;
    virtual const string toString() const = 0;

private:

    //!
    const ConvexType convexType;
};

