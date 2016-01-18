#include <vector>
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

// adjacent list representation of an directed graph
class Digraph
{ 
    int vertices;
    int edges;
    std::vector<int> m_indegree; // vertices indegree

    using BagIterator = std::vector<int>::iterator;
    using Bag = std::vector<int>;
    std::vector<Bag> adjList;
      
    void validateVertex(int v) 
    {
        if (v < 0 || v >= vertices)
        {
            std::stringstream msg;
            msg << "vertex " << v << " is not between 0 and " << (vertices-1); 
            throw std::out_of_range(msg.str());
        }
    }

public:
    Digraph(int V)
        : vertices(V), edges(0), adjList(V), m_indegree(V)
    {}
    Digraph(const Digraph& g) 
        : vertices(g.vertices),
          edges(g.edges),
          adjList(g.adjList),
          m_indegree(g.m_indegree)
    {}
    ~Digraph() {}
    int V() const { return vertices; }
    int E() const { return edges; }
    int addEdge(int from, int to)
    {
        validateVertex(from);
        validateVertex(to);
        edges++;
        adjList[from].push_back(to);
        m_indegree[to]++;
    }
    Bag& adj(int v)
    {
        validateVertex(v);
        return adjList[v];
    }
    BagIterator begin(int v)
    {
        validateVertex(v);
        return adjList[v].begin();
    }
    BagIterator end(int v)
    {
        validateVertex(v);
        return adjList[v].end();
    }
    int indegree(int v)
    {
        validateVertex(v);
        return m_indegree[v];
    }
    int outdegree(int v)
    {
        validateVertex(v);
        return adjList[v].size();
    }
    Digraph reverse()
    {
        Digraph R(vertices);
        for (int v = 0; v < vertices; v++)
            for (int w : adjList[v])
                R.addEdge(w, v);
        return R;
    }
    std::string toString()
    {
        std::stringstream ss;
        ss << vertices << " vertices, " << edges << " edges\n";
        for (int v = 0; v < vertices; v++)
        {
            ss.width(2); ss << v << ": ";
            for (int w : adjList[v])
            { ss.width(2); ss << w << " "; }
            ss << std::endl;
        }
        return ss.str();
    }
};
