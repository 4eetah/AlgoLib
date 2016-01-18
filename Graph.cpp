#include "Graph.h"

GRAPH::GRAPH(int V, bool Directed)
    : vertices(V), 
      edges(0),
      isDirected(Directed),
      adj(V)
{
}

GRAPH::~GRAPH()
{
}

int V() const
{
    return vertices;
}

int E() const;
{
    return edges;
}

bool directed() const
{
    return isDirected;
}

int insert(Edge)
{
}

int remove(Edge)
{
}

bool edge(int, int)
{
}
