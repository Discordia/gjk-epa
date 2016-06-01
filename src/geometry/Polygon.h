#pragma once

#include <memory>
#include <vector>
#include <cmath>
#include <limits>

#include <geometry/Convex.h>

using std::vector;
using std::unique_ptr;

class Polygon : public Convex
{
public:

    //!
    //!
    //!
    Polygon(const ConvexType convexType, std::initializer_list<fvec2> points);

    //!
    //!
    //!
    static unique_ptr<Polygon> createPolygon(std::initializer_list<fvec2> points);

    //!
    //!
    //!
    static unique_ptr<Polygon> createTriangle(fvec2 point1, fvec2 point2, fvec2 point3);

    //!
    //! Constructs a Rectangle with width and height centered around origin
    //!
    static unique_ptr<Polygon> createRectangle(float width, float height);

    //!
    //!
    //!
    const fvec2& getCenter() const;

    //!
    //!
    //!
    const fvec2 getFarthestPoint(const fvec2 direction, const Transform2& transform) const;

private:

    //!
    //!
    //!
    bool valid() const;

    //!
    //!
    //!
    fvec2 calcAreaWeightedCenter(const vector<fvec2>& points);

private:

    //!
    vector<fvec2> vertices;

    //!
    fvec2 center;

};

