#include <geometry/Circle.h>
#include <glm/geometric.hpp>

using glm::normalize;

Circle::Circle(float radius)
    : Convex(ConvexType::CIRCLE), radius(radius)
{
    assert(radius > 0.0);
}

unique_ptr<Circle> Circle::create(float radius)
{
    return unique_ptr<Circle>(new Circle(radius));
}

const fvec2& Circle::getCenter() const
{
    return center;
}

const float Circle::getRadius() const
{
    return radius;
}

const fvec2 Circle::getFarthestPoint(const fvec2 direction, const Transform2& transform) const
{
    fvec2 nAxis = normalize(direction);

    // add the radius along the vector to the transformedCenter to get the farthest point
    fvec2 transformedCenter = transform.getTransformed(this->center);
    transformedCenter.x += radius * nAxis.x;
    transformedCenter.y += radius * nAxis.y;

    return transformedCenter;
}





