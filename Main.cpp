#include <iostream>

#include <geometry/Polygon.h>
#include <collision/GJKCollisionDetector.h>
#include <glm/geometric.hpp>
#include <geometry/Circle.h>

using namespace std;

int main()
{
    unique_ptr<Polygon> triangle = Polygon::createTriangle(
            dvec2(4.0f, 11.0f),
            dvec2(4.0f, 5.0f),
            dvec2(9.0f, 9.0f));
    Transform2 triangleTransform;

    unique_ptr<Polygon> polygon = Polygon::createPolygon({
            dvec2(5.0f, 7.0f),
            dvec2(7.0f, 3.0f),
            dvec2(10.0f, 2.0f),
            dvec2(12.0f, 7.0f)});
    Transform2 polygonTransform;

    unique_ptr<Polygon> rectangle = Polygon::createRectangle(10.0, 12.0);
    Transform2 rectangleTransform;

    unique_ptr<Circle> circle = Circle::create(2.0f);
    Transform2 circleTransform;
    circleTransform.translate(6.0, 0.0);


    GJKCollisionDetector collisionDetector;

    // Detect collision between triangle and polygon, should be a collision
    bool collisionTP = collisionDetector.detect(*triangle, triangleTransform, *polygon, polygonTransform);
    cout << "Do we have a collision between triangle and polygon: " << collisionTP << endl;

    // Detect collision between polygon and rectangle, should *not* be a collision
    bool collisionPR = collisionDetector.detect(*polygon, polygonTransform, *rectangle, rectangleTransform);
    cout << "Do we have a collision between polygon and rectangle: " << collisionPR << endl;

    // Detect collision between triangle and rectangle, should be a collision
    bool collisionTR = collisionDetector.detect(*triangle, triangleTransform, *rectangle, rectangleTransform);
    cout << "Do we have a collision between triangle and rectangle: " << collisionTR << endl;

    // Detect collision between rectangle and circle, should be a collision
    bool collisionRC = collisionDetector.detect(*rectangle, rectangleTransform, *circle, circleTransform);
    cout << "Do we have a collision between rectangle and circle: " << collisionRC << endl;

    return 0;
}