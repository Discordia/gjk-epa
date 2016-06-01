#pragma once

#include <vector>
#include <queue>
#include <memory>
#include <glm/vec2.hpp>

#include <collision/ExpandingSimplexEdge.h>

using std::vector;
using std::priority_queue;
using std::shared_ptr;
using glm::fvec2;

class ExpandingSimplex
{
public:

    //!
    //!
    //!
    ExpandingSimplex(const vector<fvec2>& simplex);

    //!
    //!
    //!
    shared_ptr<ExpandingSimplexEdge> findClosestEdge();

    //!
    //!
    //!
    void expand(fvec2 tvec2);

private:

    //!
    int32_t calcWinding(const vector<fvec2>& simplex);

private:

    //!
    int32_t winding;

    //!
    priority_queue<shared_ptr<ExpandingSimplexEdge>, vector<shared_ptr<ExpandingSimplexEdge>>, DistancePredicate> edgeQueue;
};