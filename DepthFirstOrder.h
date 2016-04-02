#pragma once
#include <vector>
#include "Digraph.h"

class DepthFirstOrder
{
    using Bag = std::vector<int>;
    std::vector<bool> marked;
    std::vector<int>  m_pre;
    std::vector<int>  m_post;
    Bag m_preorder;
    Bag m_postorder;
    int preCounter;
    int postCounter;
public:
    
    DepthFirstOrder(Digraph& G)
    : marked(G.V(), false), m_pre(G.V()), m_post(G.V()),
      preCounter(0), postCounter(0)
    {
        for (int v = 0; v < G.V(); ++v)
            if (!marked[v]) dfs(G, v);
    }

    void dfs(Digraph& G, int v) {
        marked[v] = true;
        m_pre[v] = preCounter++;
        m_preorder.push_back(v);
        for (int w : G.adj(v))
            if (!marked[w]) dfs(G, w);
        m_post[v] = postCounter++;
        m_postorder.push_back(v);
    }

    int pre(int v) const {
        return m_pre[v];
    }

    int post(int v) const {
        return m_post[v];
    }

    Bag preorder() const {
        return m_preorder;
    }

    Bag postorder() const {
        return m_postorder;
    }

    // This is actually a topological sort order
    Bag reversePost() const {
        return Bag(m_postorder.rbegin(), m_postorder.rend());
    }
};
