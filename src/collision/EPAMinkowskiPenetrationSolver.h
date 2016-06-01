#pragma once

#include <vector>
#include <glm/vec2.hpp>
#include <glm/fwd.hpp>

using std::vector;
using glm::fvec2;

class MinkowskiSum;
class Penetration;

class EPAMinkowskiPenetrationSolver
{
public:

    //!
    //!
    //!
    EPAMinkowskiPenetrationSolver();

    //!
    //!
    //!
    void findPenetration(const vector<fvec2>& simplex, const MinkowskiSum& minkowskiSum, Penetration& penetration) const;

private:

    //!
    const float DISTANCE_EPSILON;
};