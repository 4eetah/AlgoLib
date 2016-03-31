/* Allow to find connected components in an undirected graph 
 * in constant time after making preprocessing in constructor.
 * This implementation uses depth first search for graph detour.
 */

class CC
{
    std::vector<bool> marked;
    std::vector<int>  m_id;
    std::vector<int>  m_size;
    int m_count;
public:

    CC(Graph& G)
    : marked(G.V()), m_id(G.V()), m_size(G.V()), m_count(0)
    {
        for (int v = 0; v < G.V(); ++v)
            if (!marked[v]) {
                dfs(G, v);
                m_count++;
            }
    }

    void dfs(Graph& G, int v)
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
    bool connected(int v, int w)
    {
        return m_id[v] == m_id[w];
    }
};
