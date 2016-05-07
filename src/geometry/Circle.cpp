#include <geometry/Circle.h>

#include <glm/geometric.hpp>
#include <cassert>

using glm::normalize;

Circle::Circle(double radius)
    : radius(radius)
{
    assert(radius > 0.0);
}

unique_ptr<Circle> Circle::create(double radius)
{
    return unique_ptr<Circle>(new Circle(radius));
}

const dvec2& Circle::getCenter() const
{
    return center;
}

const dvec2 Circle::getFarthestPoint(const dvec2 direction, const Transform2& transform) const
{
    dvec2 nAxis = normalize(direction);

    // add the radius along the vector to the transformedCenter to get the farthest point
    dvec2 transformedCenter = transform.getTransformed(this->center);
    transformedCenter.x += radius * nAxis.x;
    transformedCenter.y += radius * nAxis.y;

    return transformedCenter;
}





