
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int furthestReachable(Graph g, int src) {
	// TODO
    int i;
    int mode=0;
    for(i=0;i<g->nV;i++)
        if(g->edges[src][i]!=0){
            mode = 1;
            break;
        }
    if(mode==0)
        return src;
    Queue new = QueueNew();
    QueueEnqueue(new,src);
    int visited[g->nV];
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
    
    int maxindex = src;
    int maxdis = 0;
    for(i=0;i<g->nV;i++){
        if(visited[i]!=-1&&i!=src){
            int start = visited[i];
            int dis=1;
            while(start!=src){
                start = visited[start];
                dis ++;
            }
            if(dis>=maxdis){
                maxdis = dis;
                maxindex = i;
            }
        }
    }
    QueueFree(new);
    return maxindex;
    
}

