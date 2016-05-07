#pragma once

#include <memory>
#include <vector>
#include <cmath>
#include <limits>

#include <geometry/Convex.h>
#include <glm/geometric.hpp>

using std::vector;
using std::unique_ptr;
using glm::cross;

const double INV_3 = 1.0 / 3.0;

class Polygon : public Convex
{
public:

    //!
    //!
    //!
    Polygon(std::initializer_list<dvec2> points)
    {
        vertices.insert(vertices.end(), points.begin(), points.end());
        center = calcAreaWeightedCenter(vertices);
    }

    static unique_ptr<Polygon> createTriangle(dvec2 point1, dvec2 point2, dvec2 point3)
    {
        return unique_ptr<Polygon>(new Polygon({point1, point2, point3}));
    }

    static unique_ptr<Polygon> createRectangle(dvec2 point1, dvec2 point2, dvec2 point3, dvec2 point4)
    {
        return unique_ptr<Polygon>(new Polygon({point1, point2, point3, point4}));
    }

    ~Polygon() {}

    //
    // Convex implementation
    //

    dvec2 getCenter()
    {
        return center;
    }

private:

    dvec2 calcAreaWeightedCenter(const vector<dvec2>& points)
    {
        size_t size = points.size();

        // check for empty list
        if (size <= 0) assert("Empty set of points");

        // check for list of one point
        if (size == 1) {
            dvec2 p = points[0];
            return p;
        }

        // get the average center
        dvec2 ac;
        for (int i = 0; i < size; i++) {
            dvec2 p = points[i];
            ac += p;
        }

        ac *= (1.0 / size);

        // otherwise perform the computation
        dvec2 center;
        double area = 0.0;

        // loop through the vertices
        for (int i = 0; i < size; i++) {
            // get two vertices
            dvec2 p1 = points[i];
            dvec2 p2 = i + 1 < size ? points[i + 1] : points[0];
            p1 -= ac;
            p2 -= ac;

            // perform the cross product (yi * x(i+1) - y(i+1) * xi)
            double d = (p1.x * p2.y) - (p1.y * p2.x);

            // multiply by half
            double triangleArea = 0.5 * d;

            // add it to the total area
            area += triangleArea;

            // area weighted centroid
            // (p1 + p2) * (D / 3)
            // = (x1 + x2) * (yi * x(i+1) - y(i+1) * xi) / 3
            // we will divide by the total area later
            center += p1 + p2 * INV_3 * triangleArea;
        }

        // check for zero area
        if (abs(area) <= std::numeric_limits<double>::epsilon()) {
            // zero area can only happen if all the points are the same point
            // in which case just return a copy of the first
            return points[0];
        }

        // finish the centroid calculation by dividing by the total area
        center *= (1.0 / area);
        center += ac;

        // return the center
        return center;
    }

private:

    //!
    vector<dvec2> vertices;

    //!
    dvec2 center;
};

