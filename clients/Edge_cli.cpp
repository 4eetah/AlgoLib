#include "Edge.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        cerr << "Using: ./main v w weight\n";
        exit(1);
    }
    int v = std::stoi(argv[1]);
    int w = std::stoi(argv[2]);
    double weight = std::stod(argv[3]);
    Edge e(v, w, weight);
    std::cout << e.toString() << std::endl;
}
