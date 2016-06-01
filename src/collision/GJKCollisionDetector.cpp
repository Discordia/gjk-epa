#include <collision/GJKCollisionDetector.h>
#include <collision/CircleDetector.h>
#include <collision/MinkowskiSum.h>
#include <math/Epsilon.h>
#include <math/Vector2Util.h>

using namespace std;

GJKCollisionDetector::GJKCollisionDetector()
{
    penetrationSolver = unique_ptr<EPAMinkowskiPenetrationSolver>(new EPAMinkowskiPenetrationSolver);
}

bool GJKCollisionDetector::detect(
        const Convex& convex1,
        const Transform2& transform1,
        const Convex& convex2,
        const Transform2& transform2)
{
    if (convex1.getType() == ConvexType::CIRCLE && convex2.getType() == ConvexType::CIRCLE)
    {
        return CircleDetector::detect(
                reinterpret_cast<const Circle&>(convex1),
                transform1,
                reinterpret_cast<const Circle&>(convex2),
                transform2);
    }

    vector<fvec2> simplex;
    MinkowskiSum minkowskiSum(convex1, transform1, convex2, transform2);
    fvec2 direction = calcInitialDirection(convex1, transform1, convex2, transform2);

    return detect(minkowskiSum, simplex, direction);
}

bool GJKCollisionDetector::detect(const Convex& convex1, const Transform2& transform1, const Convex& convex2,
                                  const Transform2& transform2, Penetration& penetration)
{
    if (convex1.getType() == ConvexType::CIRCLE && convex2.getType() == ConvexType::CIRCLE)
    {
        return CircleDetector::detect(
                reinterpret_cast<const Circle&>(convex1),
                transform1,
                reinterpret_cast<const Circle&>(convex2),
                transform2,
                penetration);
    }

    vector<fvec2> simplex;
    MinkowskiSum minkowskiSum(convex1, transform1, convex2, transform2);
    fvec2 direction = calcInitialDirection(convex1, transform1, convex2, transform2);

    if (detect(minkowskiSum, simplex, direction))
    {
        penetrationSolver->findPenetration(simplex, minkowskiSum, penetration);
        return true;
    }

    return false;
}

fvec2 GJKCollisionDetector::calcInitialDirection(
        const Convex& convex1,
        const Transform2& transform1,
        const Convex& convex2,
        const Transform2& transform2)
{
    fvec2 c1 = transform1.getTransformed(convex1.getCenter());
    fvec2 c2 = transform2.getTransformed(convex2.getCenter());

    return c2 - c1;
}

bool GJKCollisionDetector::detect(const MinkowskiSum& minkowskiSum, vector<fvec2>& simplex, fvec2& direction)
{
    // check for a zero direction vector
    if (Vector2Util::isZero(direction))
    {
        direction = fvec2(1.0, 0.0);
    }

    // add the first point
    simplex.push_back(minkowskiSum.getSupportPoint(direction));

    // is the support point past the origin along d?
    if (glm::dot(simplex[0], direction) <= 0.0) {
        return false;
    }
    
    // negate the search direction
    direction *= -1.0;
    
    // start the loop
    while (true) {
        // always add another point to the simplex at the beginning of the loop
        simplex.push_back(minkowskiSum.getSupportPoint(direction));
        
        // make sure that the last point we added was past the origin
        fvec2 lastPoint = simplex.back();
        if (dot(lastPoint, direction) <= 0.0) {
            // a is not past the origin so therefore the shapes do not intersect
            // here we treat the origin on the line as no intersection
            // immediately return with null indicating no penetration
            return false;
        } else {
            // if it is past the origin, then test whether the simplex contains the origin
            if (checkSimplex(simplex, direction)) {
                // if the simplex contains the origin then we know that there is an intersection.
                // if we broke out of the loop then we know there was an intersection
                return true;
            }

            // if the simplex does not contain the origin then we need to loop using the new
            // search direction and simplex
        }
    }
}


bool GJKCollisionDetector::checkSimplex(vector<fvec2>& simplex, fvec2& direction) {
    // get the last point added (a)
    fvec2 a = simplex.back();

    // this is the same as a.to(ORIGIN);
    fvec2 ao = -a;

    // check to see what type of simplex we have
    if (simplex.size() == 3)
    {
        // then we have a triangle
        fvec2 b = simplex[1];
        fvec2 c = simplex[0];

        // get the edges
        fvec2 ab = b - a;
        fvec2 ac = c - a;

        // get the edge normals
        fvec2 abPerp = Vector2Util::tripleProduct(ac, ab, ab);
        fvec2 acPerp = Vector2Util::tripleProduct(ab, ac, ac);

        // see where the origin is at
        float acLocation = dot(acPerp, ao);

        if (acLocation >= 0.0) {
            // the origin lies on the right side of A->C
            // because of the condition for the gjk loop to continue the origin
            // must lie between A and C so remove B and set the
            // new search direction to A->C perpendicular vector
            simplex.erase(simplex.begin() + 1);

            // this used to be direction.set(Vector.tripleProduct(ac, ao, ac));
            // but was changed since the origin may lie on the segment created
            // by a -> c in which case would produce a zero vector normal
            // calculating ac's normal using b is more robust
            direction = acPerp;
        } else {
            float abLocation = dot(abPerp, ao);

            // the origin lies on the left side of A->C
            if (abLocation < 0.0) {
                // the origin lies on the right side of A->B and therefore in the
                // triangle, we have an intersection
                return true;
            } else {
                // the origin lies between A and B so remove C and set the
                // search direction to A->B perpendicular vector
                simplex.erase(simplex.begin());

                // this used to be direction.set(Vector.tripleProduct(ab, ao, ab));
                // but was changed since the origin may lie on the segment created
                // by a -> b in which case would produce a zero vector normal
                // calculating ab's normal using c is more robust
                direction = abPerp;
            }
        }
    } else {
        // get the b point
        fvec2 b = simplex[0];
        fvec2 ab = b - a;

        // otherwise we have 2 points (line segment)
        // because of the condition for the gjk loop to continue the origin
        // must lie in between A and B, so keep both points in the simplex and
        // set the direction to the perp of the line segment towards the origin
        direction = Vector2Util::tripleProduct(ab, ao, ab);

        // check for degenerate cases where the origin lies on the segment
        // created by a -> b which will yield a zero edge normal
        if (Vector2Util::magnitudeSquared(direction) <= Epsilon::getEpsilon()) {
            // in this case just choose either normal (left or right)
            direction = Vector2Util::left(ab);
        }
    }

    return false;
}









