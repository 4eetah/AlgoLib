#include "Digraph.h"
#include "SCC.h"
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2) {
        cerr << "Using: ./main DigraphInputFile\n";
        exit(1);
    }
    fstream fin(argv[1]);
    if (!fin.is_open()) {
        cerr << "Can't open " << argv[1] << endl;
        exit(1);
    }
    string vstr, wstr;
    fin >> vstr >> wstr;
    int V = stoi(vstr); 
    int E = stoi(wstr);
    Digraph graph(V);
    for (int i = 0; i < V; i++) {
        fin >> vstr >> wstr;
        int v = stoi(vstr);
        int w = stoi(wstr);
        graph.addEdge(v, w);
    }
    cout << graph.toString();

    SCC scc(graph);
    // array of connected components 
    std::queue<int> components[scc.count()];
    for (int v = 0; v < graph.V(); ++v) {
        components[scc.id(v)].push(v);
    }

    // print strongly connected components
    std::cout << "\nStrongly Connected components:\n";
    std::cout << scc.count() << " components\n"
    for (int c = 0; c < scc.count(); ++c) {
        std::cout << c << " : ";
        while (!components[c].empty()) {
            std::cout << components[c].front() << " ";
            components[c].pop();
        }
        std::cout << std::endl;
    }
}
