
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Stack.h"

#define MAX_NODES 1000
int visited[MAX_NODES];

int CycleCheck(Graph g,Vertex v,Vertex u){
    visited[v] = true;
    Vertex w;
    for(w=0;w<GraphNumVertices(g);w++){
        if(GraphIsAdjacent(g,v,w)){
            if(!visited[w]){
                if(CycleCheck(g,w,v))
                    return 1;
            }else if(w!=u){
                return 1;
            }
        }
    }
    return 0;
}

bool hasCycle(Graph g) {
	// TODO
    int v;
    for(v=0;v<GraphNumVertices(g);v++)
        visited[v] = false;
    for(v=0;v<GraphNumVertices(g);v++)
        if(!visited[v])
            if(CycleCheck(g,v,v))
                return true;
	return false;
}

