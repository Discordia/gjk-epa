#include "GJKCollisionDetector.h"

#include <vector>

using std::vector;

GJKCollisionDetector::GJKCollisionDetector()
{

}

bool GJKCollisionDetector::detect(const Convex& convex1, const Transform2f& transform1, const Convex& convex2, const Transform2f& transform2)
{
    // TODO: If is circle - circle, use faster method of collision detection


    vector<vec2f> simplex(3);

    return false;
}



