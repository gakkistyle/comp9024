
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"




int numReachable(Graph g, Vertex  src) {
	// TODO
    int num = 0;
    Graph copy = GraphCopy(g);
    Vertex i,j,k;
    for(k=0;k<GraphNumVertices(g);k++){
    for(i=0;i<GraphNumVertices(g);i++){
        for(j=0;j<GraphNumVertices(g);j++)
            if(GraphIsAdjacent(copy,src,i)&&GraphIsAdjacent(copy,i,j))
                GraphAddEdge(copy,src,j);
    }
    }
    for(j=0;j<GraphNumVertices(g);j++)
        if(GraphIsAdjacent(copy,src,j))
            num++;
    if(GraphIsAdjacent(copy,src,src))
        num++;
	return num;
}

