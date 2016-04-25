#pragma once

const float PI = 3.14159265358979323846264338327950288419716939937510f;
const float TWO_PI = 2 * PI;
const float HALF_PI = PI / 2;

template<typename T>
inline T degToRad(const T& angle)
{
    return static_cast<T>(angle * (PI / 180.0));
}

template<typename T>
inline T radToDeg(const T& angle)
{
    return static_cast<T>(angle * (180.0 / PI));
}
