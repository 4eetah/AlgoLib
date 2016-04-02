#include <vector>

/*
 * Find a cycle in an undirected graph
 */
class Cycle
{
    using Bag = std::vector<int>;
    std::vector<bool> marked;
    std::vector<int>  edgeTo;
    Bag m_cycle;
public:

    Cycle(Graph& G) {
        if (hasSelfLoop(G)) return;
        
        marked.reserve(G.V());        
        for (int v = 0; v < G.V(); ++v) marked[v] = false;
        if (hasParallelEdges(G)) return;

        edgeTo.reserve(G.V());
        for (int v = 0; v < G.V(); ++v)
            if (!marked[v])
                if (dfs(G, -1, v)) return;
    }
    
    bool hasSelfLoop(Graph& G) {
        for (int v = 0; v < G.V(); ++v)
            for (int w : G.adj(v))
                if (v == w) {
                    m_cycle.push_back(v);
                    m_cycle.push_back(v);
                    return true;
                }
        return false; 
    }

    bool hasParallelEdges(Graph& G) {
        for (int v = 0; v < G.V(); ++v) {
            for (int w : G.adj(v)) {
                if (marked[w]) {
                    m_cycle.push_back(v);
                    m_cycle.push_back(w);
                    m_cycle.push_back(v);
                    return true;
                }
                marked[w] = true;
            }
            for (int w : G.adj(v))
                marked[w] = false;
        }
        return false;
    }

    bool hasCycle() {
        return !m_cycle.empty();
    }

    Bag cycle() {
        return m_cycle;
    }

    bool dfs(Graph& G, int u, int v) {
        marked[v] = true;        
        for (int w : G.adj(v)) {
            if (!m_cycle.empty()) return true;
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(G, v, w);
            } else if (u != w) {
                for (int x = v; x != w; x = edgeTo[x])
                    m_cycle.push_back(x);
                m_cycle.push_back(w);
                m_cycle.push_back(v);
                return true;
            }
        }
        return false;
    }
};
