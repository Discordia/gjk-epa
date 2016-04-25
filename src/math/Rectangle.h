#pragma once

#include <cstdint>

class Rectangle
{
public:

    //!
    //!
    //!
    Rectangle();

    //!
    //!
    //!
    Rectangle(int32_t x, int32_t y, int32_t width, int32_t height);

    //!
    //!
    //!
    Rectangle(const Rectangle& rect);

    //!
    //!
    //!
    float getAspect() const;

    //!
    //!
    //!
    bool intersect(const Rectangle& a, const Rectangle& b);

    //!
    //!
    //!
    bool isPointInside(int32_t px, int32_t py);

    //!
    //!
    //!
    bool isPointInside(float px, float py);

public:
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
};