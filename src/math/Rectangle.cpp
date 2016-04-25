#include <math/Rectangle.h>

#include <algorithm>
#include <cmath>

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(int32_t x0, int32_t y0, int32_t w, int32_t h)
        : x(x0), y(y0), width(w), height(h)
{
}

Rectangle::Rectangle(const Rectangle& rect)
        : x(rect.x), y(rect.y), width(rect.width), height(rect.height)
{
}

float Rectangle::getAspect() const
{
    return (float) width / float(height);
}

bool Rectangle::intersect(const Rectangle& a, const Rectangle& b)
{
    int ax1 = a.x + a.width - 1;
    int ay1 = a.y + a.height - 1;
    int bx1 = b.x + b.width - 1;
    int by1 = b.y + b.height - 1;

    // trivial reject
    if (ax1 < b.x) return false; // a completely left of b
    if (ay1 < b.y) return false; // a completely above of b
    if (a.x > bx1) return false; // a completely right of b
    if (a.y > by1) return false; // a completely below of b

    // intersecting area
    x = std::max(a.x, b.x);
    y = std::max(a.y, b.y);
    int x1 = std::min(ax1, bx1);
    int y1 = std::min(ay1, by1);

    if (x > x1) return false;
    if (y > y1) return false;

    width = x1 - x + 1;
    height = y1 - y + 1;

    return true;
}

bool Rectangle::isPointInside(int32_t px, int32_t py)
{
    if (px < x || px >= (x + width)) return false;
    if (py < y || py >= (y + height)) return false;

    return true;
}

bool Rectangle::isPointInside(float px, float py)
{
    return isPointInside(static_cast<int>(px), static_cast<int>(py));
}