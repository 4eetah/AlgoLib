#include <vector>

struct Edge 
{
    int v, w;
    Edge(int v = -1, int w = -1) : v(v), w(w) { }
};

class GRAPH
{ 
private:
    int vertices;
    int edges;
    bool isDirected;

    typename vector<Edge> Bag;
    vector<Bag> adj;
      
public:
    GRAPH(int, bool)
    ~GRAPH();
    int V() const;
    int E() const;
    bool directed() const;
    int insert(const Edge&);
    int remove(const Edge&);
    bool edge(int, int);
    class adjIterator
    { 
    public:
        adjIterator(const GRAPH &, int);
        int beg();
        int nxt();
        bool end();
    };
};
