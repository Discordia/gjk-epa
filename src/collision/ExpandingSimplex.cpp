#include <collision/ExpandingSimplex.h>

ExpandingSimplex::ExpandingSimplex(const vector<fvec2>& simplex)
{
    this->winding = calcWinding(simplex);

    size_t size = simplex.size();
    for (int i = 0; i < size; i++) {
        int j = i + 1 == size ? 0 : i + 1;

        // create the edge
        fvec2 a = simplex[i];
        fvec2 b = simplex[j];
        edgeQueue.push(shared_ptr<ExpandingSimplexEdge>(new ExpandingSimplexEdge(a, b, this->winding)));
    }
}

shared_ptr<ExpandingSimplexEdge> ExpandingSimplex::findClosestEdge()
{
    return edgeQueue.top();
}

void ExpandingSimplex::expand(fvec2 point)
{
    // remove the edge we are splitting
    shared_ptr<ExpandingSimplexEdge> edge = edgeQueue.top();
    edgeQueue.pop();

    // create two new edges
    shared_ptr<ExpandingSimplexEdge> edge1(new ExpandingSimplexEdge(edge->getPoint1(), point, winding));
    edgeQueue.push(edge1);

    shared_ptr<ExpandingSimplexEdge> edge2(new ExpandingSimplexEdge(point, edge->getPoint2(), winding));
    edgeQueue.push(edge2);
}

//! TODO: enum for winding?
int32_t ExpandingSimplex::calcWinding(const vector<fvec2>& simplex)
{
    size_t size = simplex.size();
    for (int i = 0; i < size; i++)
    {
        int j = i + 1 == size ? 0 : i + 1;

        fvec2 a = simplex[i];
        fvec2 b = simplex[j];

        float aCrossB = Vector2Util::cross(a, b);
        if (aCrossB > 0)
        {
            return 1;
        } else if (aCrossB < 0)
        {
            return -1;
        }
    }

    return 0;
}
