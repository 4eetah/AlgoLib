#include "EdgeWeightedGraph.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2) {
        cerr << "Using: ./main EdgeWeightedInputFile\n";
        exit(1);
    }
    fstream fin(argv[1]);
    if (!fin.is_open()) {
        cerr << "Can't open " << argv[1] << endl;
        exit(1);
    }
    string vstr, wstr, weightstr;
    fin >> vstr >> wstr;
    int V = stoi(vstr); 
    int E = stoi(wstr);
    EdgeWeightedGraph graph(V);
    for (int i = 0; i < V; i++) {
        fin >> vstr >> wstr >> weightstr;
        int v = stoi(vstr);
        int w = stoi(wstr);
        double weight = stod(weightstr);
        Edge e(v, w, weight);
        graph.addEdge(e);
    }
    cout << graph.toString();
}
