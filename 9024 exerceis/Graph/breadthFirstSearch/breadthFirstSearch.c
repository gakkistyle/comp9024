
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src) {
	// TODO
    Queue new = QueueNew();
    QueueEnqueue(new,src);
    int visted[g->nV];
    int i;
    Vertex v;
    for(i=0;i<g->nV;i++)
        visted[i] = -1;
    visted[src] = src;
    while(!QueueIsEmpty(new)){
        v = QueueDequeue(new);
        printf("%d ",v);
        Vertex w;
        for(w=0;w<g->nV;w++){
            if(GraphIsAdjacent(g,v,w)&&visted[w]==-1){
                visted[w] = v;
                QueueEnqueue(new,w);
            }
        }
        
    }
    return ;
    
}

