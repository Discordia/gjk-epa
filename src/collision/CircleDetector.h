#pragma once

#include <geometry/Circle.h>
#include <collision/Penetration.h>

class CircleDetector
{
public:

    //!
    //!
    //!
    static bool detect(const Circle& circle1,
                       const Transform2& transform1,
                       const Circle& circle2,
                       const Transform2& transform2);

    //!
    //!
    //!
    static bool detect(const Circle& circle1,
                       const Transform2& transform1,
                       const Circle& circle2,
                       const Transform2& transform2,
                       Penetration& penetration);

private:

    //!
    //!
    //!

};
