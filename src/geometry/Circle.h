#pragma once

#include <geometry/Convex.h>
#include <memory>

using std::unique_ptr;

class Circle : public Convex
{
public:

    //!
    //!
    //!
    Circle(double radius);

    //!
    //!
    //!
    static unique_ptr<Circle> create(double radius);

    //!
    //!
    //!
    const dvec2& getCenter() const;

    //!
    //!
    //!
    const dvec2 getFarthestPoint(const dvec2 direction, const Transform2& transform) const;

private:

    //!
    dvec2 center;

    //!
    double radius;
};

