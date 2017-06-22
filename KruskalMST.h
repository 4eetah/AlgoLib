#pragma once
#include <vector>
#include "Edge.h"

class KruskalMST
{
    using Bag = std::vector<Edge>;
    Bag msg; // edges in MST
    double weight;  // weight of MST

public:

    KruskalMST(EdgeWeightedGraph& G) {
        std::vector<Edge> edges(G.E());
        for (int v = 0; v < G.V(); ++v)
            for (Edge e : G.adj(v)) 
                edges.push_back(e);
        sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
            return e1.weight() < e2.weight();
        });


    }

};
