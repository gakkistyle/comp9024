
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

#define MAX_NODES 1000
#define VERY_HIGH_VALUE 9999999

int dijkstraSSSP(Graph g, int nV, Vertex source, int distance) {
    int dist[MAX_NODES];
    int pred[MAX_NODES];
    bool vSet[MAX_NODES];  // vSet[v] = true <=> v has not been processed
    int s, t;

    int result = 0;

    Queue pQueue = QueueNew();
    for (s = 0; s < nV; s++) {
        QueueEnqueue(pQueue, s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
    }
    dist[source] = 0;
    while (!QueueIsEmpty(pQueue)) {
        s = QueueDequeue(pQueue);
        vSet[s] = false;
        for (t = 0; t < nV; t++) {
            if (vSet[t]) {
                int weight = GraphIsAdjacent(g, t, s);

                printf("dist %d: weight: %d, dist %d, s:%d,t:%d\n", dist[s], weight, dist[t],s,t);

                if (weight > 0 && dist[s] + weight < dist[t]) {  // relax along (s,t,weight)
                    dist[t] = dist[s] + weight;
                    pred[t] = s;
                }
            }
        }
    }
    printf("\n");
    for (s = 0; s < nV; s++) {
        printf("node %d: dist: %d \n", s, dist[s]);
        if (dist[s] <= distance ) {
            result++;
        }
    }

    printf("\n");


    // free
    QueueFree(pQueue);

    return result;
}

int numWithin(Graph g, int src, int dist) {
	// TODO

	int numberOfVertex = GraphNumVertices(g);
    return dijkstraSSSP(g,numberOfVertex,src,dist);

    // return 0;
}

