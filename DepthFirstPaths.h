#include <vector>
#include <algorithm>

class DepthFirstPaths
{
    using Bag = std::vector<int>;
    std::vector<bool> marked;
    Bag edgeTo; 
    const int source;
public:
    DepthFirstPaths(Graph& G, int s)
        : source(s), marked(G.V()), edgeTo(G.V())
    {
        dfs(G, s);
    }

    void dfs(Graph& G, int v) {
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(G, w);
            }
        }
    }

    bool hasPathTo(int v) {
        return marked[v];
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
