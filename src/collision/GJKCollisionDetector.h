#pragma once

#include <geometry/Convex.h>
#include <math/Transform2.h>
#include <vector>

using std::vector;

class MinkowskiSum;

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
    bool detect(const Convex& convex1, const Transform2& transform1, const Convex& convex2, const Transform2& transform2);

private:

    //!
    //!
    //!
    dvec2 calcInitialDirection(const Convex& convex1, const Transform2& transform1, const Convex& convex2, const Transform2& transform2);

    //!
    //!
    //!
    bool detect(const MinkowskiSum& minkowskiSum, vector<dvec2>& simplex, dvec2& direction);

    //! Determines whether the given simplex contains the origin.  If it does contain the origin,
    //! then this method will return true.  If it does not, this method will update both the given
    //! simplex and also the given search direction.
    //!
    //! This method also assumes that the last point in the simplex is the most recently added point.
    //!
    //! This method should never be supplied anything other than 2 or 3 points for the simplex
    //!
    //! @param simplex the simplex
    //! @param direction the search direction
    //! @return boolean true if the simplex contains the origin
    bool checkSimplex(vector<dvec2>& simplex, dvec2& direction);

private:


};

