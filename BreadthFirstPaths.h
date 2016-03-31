#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class BreadthFirstPaths
{
    using Bag = std::vector<int>;
    std::vector<bool> marked;
    Bag edgeTo; 
    Bag m_distTo;
    const int source;
public:
    BreadthFirstPaths(Graph& G, int s)
    : source(s), marked(G.V()), edgeTo(G.V()), m_distTo(G.V(), INT_MAX)
    {
        bfs(G, s);
    }

    void bfs(Graph& G, int s) {
        std::queue<int> q;
        q.push(s); 
        m_distTo[s] = 0;
        marked[s] = true;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : G.adj(v)) {
                if (!marked[w]) {
                    marked[w] = true;
                    edgeTo[w] = v;
                    m_distTo[w] = m_distTo[v] + 1;
                    q.push(w);
                }
            }
        }
    }

    // breadth first search from multiple sources
    void bfs(Graph& G, const Bag& sources) {
        std::queue<int> q;
        for (int s : sources) {
            q.push(s); 
            m_distTo[s] = 0;
            marked[s] = true;
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : G.adj(v)) {
                if (!marked[w]) {
                    marked[w] = true;
                    edgeTo[w] = v;
                    m_distTo[w] = m_distTo[v] + 1;
                    q.push(w);
                }
            }
        }

    }

    bool hasPathTo(int v) {
        return marked[v];
    }

    int distTo(int v) {
        return m_distTo[v];
    }

    Bag pathTo(int v) {
        if (!hasPathTo(v)) return Bag();
        Bag stack;
        for (int x = v; x != source; x = edgeTo[x])
            stack.push_back(x);
        stack.push_back(source);
        std::reverse(stack.begin(), stack.end());
        return stack;
    }
};