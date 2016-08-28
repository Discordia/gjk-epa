#pragma once

#include <math/Vector2Util.h>
#include <memory>
#include <glm/gtx/string_cast.hpp>

using std::shared_ptr;
using std::string;

class ExpandingSimplexEdge
{
public:

    ExpandingSimplexEdge(const fvec2 point1, const fvec2 point2, const int32_t winding)
    {
        this->normal = fvec2(point2.x - point1.x, point2.y - point1.y);

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

    const fvec2& getPoint1() const
    {
        return point1;
    }

    const fvec2& getPoint2() const
    {
        return point2;
    }

    const float getDistance() const
    {
        return distance;
    }

    const fvec2& getNormal() const
    {
        return normal;
    }

    string to_string()
    {
        return "ExpandingSimplexEdge - point1: " + glm::to_string(point1) +
               ", point2: " + glm::to_string(point2) +
               ", normal: " + glm::to_string(normal) +
               ", distance: " + std::to_string(distance);
    }


private:

    //!
    fvec2 point1;

    //!
    fvec2 point2;

    //!
    fvec2 normal;

    //!
    float distance;
};

struct DistancePredicate
{
    bool operator()(const shared_ptr<ExpandingSimplexEdge>& lhs, const shared_ptr<ExpandingSimplexEdge>& rhs) const
    {
        return lhs->getDistance() > rhs->getDistance();
    }
};