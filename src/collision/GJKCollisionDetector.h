#pragma once

#include <geometry/Triangle.h>
#include <math/Transform2.h>

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
    bool detect(Triangle triangle1, Transform2f transform1, Triangle triangle2, Transform2f transform2);

private:

};

