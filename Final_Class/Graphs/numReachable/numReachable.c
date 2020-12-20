
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

int numReachable(Graph g, int src) {
    // TODO
    int numberOfVertex = GraphNumVertices(g);
    for (int i = 0; i < numberOfVertex; i++) {
        for (int j = 0; j < numberOfVertex; j++) {
            for (int k = 0; k < numberOfVertex; k++) {
                if (GraphIsAdjacent(g, i, j) && GraphIsAdjacent(g, j, k)) {
                    GraphAddEdge(g, i, k);
                }
            }
        }
    }

    int result = -1;
    for (int i = 0; i < numberOfVertex; i++) {
        if (GraphIsAdjacent(g, src, i)) {
            result++;
        }
    }
    return result;
}

