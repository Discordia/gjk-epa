#include <iostream>

#include <geometry/Triangle.h>
#include <geometry/Polygon.h>
#include <math/Transform2.h>
#include <collision/GJKCollisionDetector.h>

using namespace std;

int main()
{
    Triangle triangle(vec2f(4.0f, 11.0f), vec2f(9.0f, 9.0f), vec2f(4.0f, 5.0f));
    Transform2f transform1;

    Polygon polygon(vec2f(5.0f, 7.0f), vec2f(12.0f, 7.0f), vec2f(10.0f, 2.0f), vec2f(7.0f, 3.0f));
    Transform2f transform2;

    GJKCollisionDetector collisionDetector;
    bool collision = collisionDetector.detect(triangle, transform1, polygon, transform2);

    cout << "Do we have a collision: " << collision << endl;

    return 0;
}