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
    Polygon(std::initializer_list<dvec2> points);

    //!
    //!
    //!
    static unique_ptr<Polygon> createTriangle(dvec2 point1, dvec2 point2, dvec2 point3);

    //!
    //!
    //!
    static unique_ptr<Polygon> createPolygon(std::initializer_list<dvec2> points);

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
    //!
    //!
    bool valid() const;

    //!
    //!
    //!
    dvec2 calcAreaWeightedCenter(const vector<dvec2>& points);

private:

    //!
    vector<dvec2> vertices;

    //!
    dvec2 center;

};

