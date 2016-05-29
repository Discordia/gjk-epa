#pragma once

#include <math/Vector2Util.h>
#include <memory>

using std::shared_ptr;

class ExpandingSimplexEdge
{
public:

    ExpandingSimplexEdge(const dvec2 point1, const dvec2 point2, const int32_t winding)
    {
        this->normal = dvec2(point2.x - point1.x, point2.y - point1.y);

        if (winding < 0) {
            this->normal = Vector2Util::right(normal);
        } else {
            this->normal = Vector2Util::left(normal);
        }
        
        // normalize the vector
        this->normal = glm::normalize(normal);
        
        // project the first point onto the normal (it doesnt matter which
        // you project since the normal is perpendicular to the edge)
        this->distance = abs(point1.x * normal.x + point1.y * normal.y);
        this->point1 = point1;
        this->point2 = point2;
    }

    const dvec2& getPoint1() const
    {
        return point1;
    }

    const dvec2& getPoint2() const
    {
        return point2;
    }

    const double getDistance() const
    {
        return distance;
    }

    const dvec2& getNormal() const
    {
        return normal;
    }


private:

    //!
    dvec2 point1;

    //!
    dvec2 point2;

    //!
    dvec2 normal;

    //!
    double distance;
};

struct DistancePredicate
{
    bool operator()(const shared_ptr<ExpandingSimplexEdge>& lhs, const shared_ptr<ExpandingSimplexEdge>& rhs) const
    {
        return lhs->getDistance() > rhs->getDistance();
    }
};