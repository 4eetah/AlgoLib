#include "Digraph.h"
#include "DepthFirstOrder.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Using: ./main DigraphInputFile\n";
        exit(1);
    }
    std::fstream fin(argv[1]);
    if (!fin.is_open()) {
        std::cerr << "Can't open " << argv[1] << std::endl;
        exit(1);
    }
    std::string vstr, wstr;
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
    std::cout << graph.toString();


    DepthFirstOrder dfs(graph);
    std::cout << "Printing Depth Search Orders\n";
    std::cout << "   v  pre post\n";
    std::cout << "--------------\n";
    for (int v = 0; v < graph.V(); ++v) {
        std::cout.width(4);
        std::cout << v;
        std::cout.width(4);
        std::cout << dfs.pre(v);
        std::cout.width(4);
        std::cout << dfs.post(v);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\nPreorder:\n";
    for (int v : dfs.preorder())
        std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "\nPostorder:\n";
    for (int v : dfs.postorder())
        std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "\nReverse postorder(Topological sort order)\n";
    for (int v : dfs.reversePost())
        std::cout << v << " ";
    std::cout << std::endl;
}
