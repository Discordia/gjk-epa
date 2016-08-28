#pragma once

#include <geometry/Convex.h>
#include <memory>

using std::unique_ptr;

class Circle : public Convex
{
public:

    Circle(float radius);
    static unique_ptr<Circle> create(float radius);

    const fvec2& getCenter() const;
    const float getRadius() const;
    const fvec2 getFarthestPoint(const fvec2 direction, const Transform2& transform) const;

    const string toString() const;

private:

    fvec2 center;
    float radius;
};

