#include "Digraph.h"
#include "DirectedCycle.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "Using: ./main [inputFile]\n";
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
    Digraph graph(V);
    for (int i = 0; i < V; i++)
    {

        fin >> vstr >> wstr;
        int v = stoi(vstr);
        int w = stoi(wstr);
        graph.addEdge(v, w);
    }
    cout << graph.toString();

    DirectedCycle finder(graph);
    if (finder.hasDirectedCycle()) {
        std::cout << "\nFound cycle:\n"; 
        for (int v : finder.cycle())
            std::cout << v << " ";
        std::cout << std::endl;
    } else {
        std::cout << "\nDigraph is acyclic\n";
    }
}
