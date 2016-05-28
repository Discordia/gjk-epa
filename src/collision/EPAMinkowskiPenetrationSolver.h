#pragma once

#include <vector>
#include <glm/vec2.hpp>

using std::vector;
using glm::dvec2;

class MinkowskiSum;
class Penetration;

class EPAMinkowskiPenetrationSolver
{
public:

    //!
    //!
    //!
    void findPenetration(const vector<dvec2>& simplex, const MinkowskiSum& minkowskiSum, Penetration& penetration) const;

private:
};