#pragma once
#include "Digraph.h"
#include "DepthFirstOrder.h"

/*
 * Finds strong connected components
 * in a directed graph
 */

class SCC
{
    std::vector<bool> marked;
    std::vector<int>  m_id;
    std::vector<int>  m_size;
    int m_count;
public:

    SCC(Digraph& G)
    : marked(G.V()), m_id(G.V()), m_size(G.V()), m_count(0)
    {
        Digraph revGraph = G.reverse();
        DepthFirstOrder rdfs(revGraph);
        for (int v : rdfs.reversePost())
            if (!marked[v]) {
                dfs(G, v);
                m_count++;
            }
    }

    void dfs(Digraph& G, int v)
    {
        marked[v] = true;
        m_id[v] = m_count;
        m_size[m_count]++;
        for (int w : G.adj(v))
            if (!marked[w]) dfs(G, w);
    }

    /* 
     * Number of connected components
     */
    int count()
    {
        return m_count;
    }

    /* 
     * Id of the connected component
     * given vertice belongs to
     */
    int id(int v)
    {
        return m_id[v];
    }

    /*
     * Number of vertices in the connected
     * component containing vertex
     */
    int size(int v)
    {
        return m_size[m_id[v]];
    }

    /*
     * Are vertices in the same connected component?
     */
    bool stronglyConnected(int v, int w)
    {
        return m_id[v] == m_id[w];
    }
};
