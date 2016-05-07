#pragma once

#include <geometry/Convex.h>
#include <math/Transform2.h>

class MinkowskiSum
{
public:
    MinkowskiSum(const Convex& convex1, const Transform2& transform1, const Convex& convex2, const Transform2& transform2)
            : convex1(convex1), transform1(transform1), convex2(convex2), transform2(transform2)
    {
    }

    //! Returns the farthest point in the Minkowski sum given the direction.
    //!
    //! @param direction the search direction
    //! @return the point farthest in the Minkowski sum in the given direction
    dvec2 getSupportPoint(dvec2 direction) const {
        // get the farthest point in the given direction in convex1
        dvec2 point1 = convex1.getFarthestPoint(direction, transform1);

        // get the farthest point in the opposite direction in convex2
        direction *= -1.0;
        dvec2 point2 = convex2.getFarthestPoint(direction, transform2);

        // return the Minkowski sum point
        return point1 - point2;
    }


private:
    const Convex& convex1;
    const Transform2& transform1;

    const Convex& convex2;
    const Transform2& transform2;
};


