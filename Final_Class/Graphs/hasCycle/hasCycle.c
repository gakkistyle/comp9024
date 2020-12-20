
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Stack.h"

// look for a cycle that does not go back directly to u
bool dfsCycleCheck(Graph graph, Vertex v, Vertex u, int numberOfVertices, int visited[]) {
    // mark v as visited
    visited[v] = 1;
    // for each (v,w)∈edges(G) do
    for (Vertex w = 0; w < numberOfVertices; w++) {
        if (GraphIsAdjacent(graph, v, w)) {
            // 如果这个节点访问过了，同时w!=u 返回true
            if (visited[w] && w != u) {
                return true;
            }
            // 如果这个节点没有访问过，那么check后续的节点是否访问过
            if (!visited[w] && dfsCycleCheck(graph, w, v, numberOfVertices, visited)) {
                return true;
            }
        }
    }
    // return false
    return false;
}


bool hasCycle(Graph g) {
    // variable
    Vertex vertex;

    int visited[1000];

    int numberOfVertices = GraphNumVertices(g);

    // set default
    for (vertex = 0; vertex < numberOfVertices; vertex++) {
        visited[vertex] = 0;
    }
    // for each all vertices
    for (vertex = 0; vertex < numberOfVertices; vertex++) {
        if (!visited[vertex]
            && dfsCycleCheck(g, vertex, vertex, numberOfVertices,visited)) {
            return true;
        }
    }

    // TODO
    return false;
}

