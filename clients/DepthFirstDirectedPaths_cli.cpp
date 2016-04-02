#include "Digraph.h"
#include "DepthFirstDirectedPaths.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cerr << "Using: ./main [DigraphInputFile] [sourceVertex]\n";
        exit(1);
    }
    fstream fin(argv[1]);
    if (!fin.is_open())
    {
        cerr << "Can't open " << argv[1] << endl;
        exit(1);
    }
    string vstr, wstr;
    fin >> vstr >> wstr;
    int V = stoi(vstr); 
    int E = stoi(wstr);
    int sourceVertex = stoi(argv[2]);
    Digraph graph(V);
    for (int i = 0; i < V; i++)
    {

        fin >> vstr >> wstr;
        int v = stoi(vstr);
        int w = stoi(wstr);
        graph.addEdge(v, w);
    }
    cout << graph.toString();

    DepthFirstDirectedPaths dfs(graph, sourceVertex);
    std::cout << "\nChecking paths from source:\n";
    for (int v = 0; v < graph.V(); ++v) {
        if (dfs.hasPathTo(v)) {
            std::cout << sourceVertex << " to " << v << " : ";
            auto path = dfs.pathTo(v);
            for (int w : path)
                if (w == sourceVertex)
                    std::cout << w;
                else
                    std::cout << "-" << w; 
            std::cout << std::endl;
        } else {
            std::cout << sourceVertex << " to " << v << " : " << "not connected\n"; 
        }
    }
}
