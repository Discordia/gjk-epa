#include "GJKCollisionDetector.h"

#include <iostream>
#include <vector>

using namespace std;
using std::vector;

GJKCollisionDetector::GJKCollisionDetector()
{

}

bool GJKCollisionDetector::detect(const Convex& convex1, const Transform2& transform1, const Convex& convex2, const Transform2& transform2)
{
    // TODO: If is circle - circle, use faster method of collision detection

    vector<dvec2> simplex(3);

    return false;
}



