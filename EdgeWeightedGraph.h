#pragma once
#include <vector>
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Edge.h"

class EdgeWeightedGraph
{ 
    int vertices;
    int edges;

    using BagIterator = std::vector<Edge>::iterator;
    using Bag = std::vector<Edge>;
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
    EdgeWeightedGraph(int V) : vertices(V), edges(0), adjList(V) {}
    EdgeWeightedGraph(const EdgeWeightedGraph& g) : vertices(g.vertices), edges(g.edges), adjList(g.adjList) {}
    int V() const { return vertices; }
    int E() const { return edges; }

    int addEdge(const Edge& e)
    {
        int v = e.either();
        int w = e.other(v);
        validateVertex(v);
        validateVertex(w);
        edges++;
        adjList[v].push_back(e);
        adjList[w].push_back(e);
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

    int degree(int v)
    {
        return adjList[v].size();
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << vertices << " vertices, " << edges << " edges\n";
        for (int v = 0; v < vertices; v++)
        {
            ss.width(2); ss << v << ":\n";
            for (Edge& e : adjList[v])
            { ss.width(2); ss << e.toString() << std::endl; }
            ss << std::endl;
        }
        return ss.str();
    }
};
