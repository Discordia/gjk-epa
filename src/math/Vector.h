#pragma once

#include <math/Vector2.h>
#include <cmath>

struct Vector
{

    //!
    static const vec2f ZERO;

    //!
    static const vec2f NO_DIRECTION;

    //!
    static const vec2f UP;

    //!
    static const vec2f DOWN;

    //!
    static const vec2f LEFT;

    //!
    static const vec2f RIGHT;

    //!
    static const vec2f LEFT_UP;

    //!
    static const vec2f LEFT_DOWN;

    //!
    static const vec2f RIGHT_UP;

    //!
    static const vec2f RIGHT_DOWN;


    //!
    //!
    //!
    template<typename T>
    static T findAngle(const Vector2 <T>& v1, const Vector2 <T>& v2)
    {
        return atan2(v2.y, v2.x) - atan2(v1.y, v1.x);
    }
};
