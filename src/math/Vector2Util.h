#pragma once

#include <glm/vec2.hpp>
#include <glm/geometric.hpp>
#include <cmath>

using glm::fvec2;
using glm::dot;
using std::abs;

class Vector2Util
{
public:

    static float cross(const fvec2& p1, const fvec2& p2)
    {
        return p1.x * p2.y - p1.y * p2.x;
    }

    //!
    //! Computes:
    //! b * (a . c) - a * (b . c)
    //!
    static fvec2 tripleProduct(const fvec2& a, const fvec2& b, const fvec2& c)
    {
        return (b * dot(a, c)) - (a * dot(b, c));
    }

    //!
    //! Magnitude squared:
    //! v.x * v.x + v.y * v.y
    //!
    static float magnitudeSquared(const fvec2& v)
    {
        return v.x * v.x + v.y * v.y;
    }

    //! Returns the left-handed normal of this vector.
    static fvec2 left(const fvec2& v)
    {
        return fvec2(v.y, -v.x);
    }

    //! Returns the right-handed normal of this vector.
    static fvec2 right(const fvec2& v)
    {
        return fvec2(-v.y, v.x);
    }

    static bool isZero(const fvec2& v)
    {
        return abs(v.x) <= std::numeric_limits<float>::epsilon()
               && abs(v.y) <= std::numeric_limits<float>::epsilon();
    }
};
