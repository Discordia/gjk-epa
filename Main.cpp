#include <iostream>

#include <geometry/Polygon.h>
#include <math/Transform2.h>
#include <collision/GJKCollisionDetector.h>

using namespace std;

int main()
{
    unique_ptr<Polygon> triangle = Polygon::createTriangle(dvec2(4.0f, 11.0f), dvec2(9.0f, 9.0f), dvec2(4.0f, 5.0f));
    Transform2 transform1;

    unique_ptr<Polygon> rectangle = Polygon::createRectangle(dvec2(5.0f, 7.0f), dvec2(12.0f, 7.0f), dvec2(10.0f, 2.0f), dvec2(7.0f, 3.0f));
    Transform2 transform2;

    GJKCollisionDetector collisionDetector;
    bool collision = collisionDetector.detect(*triangle, transform1, *rectangle, transform2);

    cout << "Do we have a collision: " << collision << endl;

    return 0;
}