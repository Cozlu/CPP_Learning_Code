#include "Polygon.h"

#include <ostream>
#include <utility>

void Polygon::add_vertex(int p1, int p2)
{
    _vertices.emplace_back(p1, p2);
}

std::ostream& operator<<(std::ostream& stream, const Polygon& polygon)
{
    for (auto vertex : polygon._vertices)
    {
        stream << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    return stream;
}