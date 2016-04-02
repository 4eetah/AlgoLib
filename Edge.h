#pragma once
#include <stdexcept>
#include <string>
#include <sstream>

class Edge
{
    const int v;
    const int w;
    const double Weight;
public:
    Edge(int v, int w, double weight) : v(v), w(w), Weight(weight)
    {
        if (v < 0 || w < 0) 
            throw std::out_of_range("Vertex name must be a nonnegative integer");
    }
    double weight() const { return Weight; }
    int either() const { return v; }
    int other(int vertex) const
    {
        if      (vertex == v) return w;
        else if (vertex == w) return v;
        else throw std::invalid_argument("Illegal endpoint"); 
    }
    std::string toString()
    {
        std::stringstream ss;        
        ss << v << "-" << w << " " << Weight;
        return ss.str(); 
    }
};
