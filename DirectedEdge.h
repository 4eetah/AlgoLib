#pragma once
#include <stdexcept>
#include <string>
#include <sstream>

class DirectedEdge
{
    const int v;
    const int w;
    const double Weight;
public:
    DirectedEdge(int v, int w, double weight) : v(v), w(w), Weight(weight)
    {
        if (v < 0 || w < 0) 
            throw std::out_of_range("Vertex name must be a nonnegative integer");
    }
    double weight() const { return Weight; }
    int from() const     { return v; }
    int to() const       { return w; }
    std::string toString()
    {
        std::stringstream ss;        
        ss << v << "->" << w << " " << Weight;
        return ss.str(); 
    }
};
