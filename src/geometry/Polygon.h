#pragma once

#include <geometry/Convex.h>

class Polygon : public Convex
{
public:

    Polygon(vec2f point1, vec2f point2, vec2f point3, vec2f point4)
    {

    }

    ~Polygon() {}

    //
    // Convex implementation
    //

    vec2f getCenter()
    {
        return vec2f();
    }

private:

};

