#pragma once
#include <vector>
#include "Digraph.h"

/*
 * Find a cycle in a directed graph
 */
class DirectedCycle
{
    using Bag = std::vector<int>;
    std::vector<bool> marked;
    std::vector<int>  edgeTo;
    std::vector<int>  onStack;
    Bag m_cycle;
public:

    DirectedCycle(Digraph& G)
    : marked(G.V(), false), edgeTo(G.V()), onStack(G.V())
    {
        for (int v = 0; v < G.V(); ++v)
            if (!marked[v] && !hasDirectedCycle())
                dfs(G, v);
    }
    
    bool hasDirectedCycle() {
        return !m_cycle.empty();
    }

    Bag cycle() {
        return m_cycle;
    }

    void dfs(Digraph& G, int v) {
        onStack[v] = true;
        marked[v] = true;        
        for (int w : G.adj(v)) {
            if (!m_cycle.empty()) return;
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(G, w);
            } else if (onStack[w]) {
                for (int x = v; x != w; x = edgeTo[x])
                    m_cycle.push_back(x);
                m_cycle.push_back(w);
                m_cycle.push_back(v);
            }
        }
        onStack[v] = false;
    }
};
