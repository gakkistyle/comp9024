
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int shortestDistance(Graph g, int src, int dest) {
	// TODO
    if(src==dest)
        return 0;
    Queue new = QueueNew();
    QueueEnqueue(new,src);
    int visited[g->nV];
    int i;
    for(i=0;i<g->nV;i++)
        visited[i]=-1;
    visited[src] = src;
    while(!QueueIsEmpty(new)){
        Vertex v = QueueDequeue(new);
        Vertex w;
        for(w=0;w<g->nV;w++){
            if(GraphIsAdjacent(g,v,w)&&visited[w]==-1){
                visited[w] = v;
                QueueEnqueue(new,w);
            }
        }
    }
    if(visited[dest]==-1){
        QueueFree(new);
        return -1;
    }
    else{
        int start = visited[dest];
        int dis = 1;
        while(start != src){
            start = visited[start];
            dis ++;
        }
        QueueFree(new);
        return dis;
    }
}

