#pragma once

#include <ostream>
#include <utility>
#include <vector>

using Vertex = std::pair<int, int>;

class Polygon
{
    friend std::ostream& operator<<(std::ostream& stream, const Polygon& polygon);

public:
    void   add_vertex(int p1, int p2);
    Vertex operator[](int index) const { return _vertices[index]; }

private:
    std::vector<Vertex> _vertices;
};
