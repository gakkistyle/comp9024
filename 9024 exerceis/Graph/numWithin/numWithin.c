
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int numWithin(Graph g, int src, int dist) {
	// TODO
    if(dist == 0)
        return 1;
    Queue new = QueueNew();
    int visited[g->nV];
    int i;
    for(i=0;i<g->nV;i++)
        visited[i] = -1;
    visited[src] = src;
    QueueEnqueue(new,src);
    Vertex v;
    while(!QueueIsEmpty(new)){
        v = QueueDequeue(new);
        Vertex w;
        for(w=0;w<g->nV;w++){
            if(GraphIsAdjacent(g,v,w)&&visited[w]==-1){
                QueueEnqueue(new,w);
                visited[w] = v;
            }
        }
    }
    
    int num = 0;
    for(i=0;i<g->nV;i++){
        if(visited[i]!=-1){
            int start = visited[i];
            int dist_once = 1;
            while(start!=src){
                start = visited[start];
                dist_once ++;
            }
            if(dist_once<=dist)
                num++;
        }
    }
    QueueFree(new);
	return num;
}

