
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#define MAXNODE 1000
int visted[MAXNODE];
void depthFirstSearch(Graph g, int src) {
	// TODO
    Vertex v;
    visted[src] = 1;
    printf("%d ",src);
    for(v=0;v<g->nV;v++){
        if(GraphIsAdjacent(g,src,v)&&visted[v]==0){
            visted[v] = 1;
            depthFirstSearch(g,v);
        }
    }
    return;
}

