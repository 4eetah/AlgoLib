#pragma once
#include <vector>
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

// adjacent list representation of an undirected graph
class Graph
{ 
    int vertices;
    int edges;

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
    Graph(int V) : vertices(V), edges(0), adjList(V) {}
    Graph(const Graph& g) : vertices(g.vertices), edges(g.edges), adjList(g.adjList) {}
    ~Graph() {}
    int V() const { return vertices; }
    int E() const { return edges; }
    int addEdge(int v, int w)
    {
        validateVertex(v);
        validateVertex(w);
        edges++;
        adjList[v].push_back(w);
        adjList[w].push_back(v);
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
