//
// Created by robban on 2016-05-29.
//

#include <collision/CircleDetector.h>
#include <math/Vector2Util.h>

bool CircleDetector::detect(
        const Circle& circle1,
        const Transform2& transform1,
        const Circle& circle2,
        const Transform2& transform2)
{
    dvec2 ce1 = transform1.getTransformed(circle1.getCenter());
    dvec2 ce2 = transform2.getTransformed(circle2.getCenter());

    dvec2 v = ce2 - ce1;
    double radii = circle1.getRadius() + circle2.getRadius();
    double mag = Vector2Util::magnitude(v);

    return mag < radii;
}

bool CircleDetector::detect(
        const Circle& circle1,
        const Transform2& transform1,
        const Circle& circle2,
        const Transform2& transform2,
        Penetration& penetration)
{
    dvec2 ce1 = transform1.getTransformed(circle1.getCenter());
    dvec2 ce2 = transform2.getTransformed(circle2.getCenter());

    dvec2 v = ce2 - ce1;
    double radii = circle1.getRadius() + circle2.getRadius();
    double mag = Vector2Util::magnitude(v);

    if (mag < radii)
    {
        penetration.normal = v;
        penetration.depth = radii - mag;

        return true;
    }

    return false;
}
