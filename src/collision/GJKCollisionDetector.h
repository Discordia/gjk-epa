#pragma once

#include <geometry/Convex.h>
#include <math/Transform2.h>

class GJKCollisionDetector
{
public:

    //!
    //!
    //!
    GJKCollisionDetector();

    //!
    //!
    //!
    bool detect(const Convex& convex1, const Transform2f& transform1, const Convex& convex2, const Transform2f& transform2);

private:

};

