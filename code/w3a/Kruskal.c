//
//  Kruskal.c
//  code
//
//  Created by 郑淇文 on 2020/1/27.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "WGraph.h"

#define MAX_NODES 1000
bool visited3[MAX_NODES];

bool dfsCycleCheck(Graph g,Vertex v,Vertex u){
    visited3[v] = true;
    Vertex w;
    for(w=0;w<numOfVertices2(g);w++){
        if(adjacent2(g,v,w)||adjacent2(g,w,v)){
            if(!visited3[w])
                return dfsCycleCheck(g,w,v);
            else if (w!=u)
                return true;
        }
    }
    return false;
}

Graph kruskal(Graph g,Edge sortedEdges[],int nE){
    int nV = numOfVertices2(g);
    Graph mst = newGraph2(nV);
    
    int n = 0;
    int i;
    for(i=0;i<nE && n<nV-1;i++){
        Edge e = sortedEdges[i];
        insertEdge2(mst, e);
        n++;
        Vertex v;
        for(v=0;v<nV;v++)
            visited3[v] = false;
        if(dfsCycleCheck(mst,e.v,e.v)){
            removeEdge2(mst,e);
            n--;
        }
    }
    return mst;
}

//int main(){
//    Graph g = newGraph2(5);
//    
//    Edge edges[8];
//    edges[0].v = 2;edges[0].w = 3;edges[0].weight = 1;
//    edges[1].v = 0;edges[1].w = 2;edges[1].weight = 2;
//    edges[2].v = 0;edges[2].w = 1;edges[2].weight = 3;
//    edges[3].v = 1;edges[3].w = 2;edges[3].weight = 4;
//    edges[4].v = 2;edges[4].w = 4;edges[4].weight = 5;
//    edges[5].v = 1;edges[5].w = 4;edges[5].weight = 6;
//    edges[6].v = 3;edges[6].w = 4;edges[6].weight = 7;
//    edges[7].v = 0;edges[7].w = 3;edges[7].weight = 8;
//    
//    int i,nE = 8;
//    for(i=0;i<nE;i++)
//        insertEdge2(g, edges[i]);
//    showGraph2(g);
//    
//    Graph mst = kruskal(g,edges,nE);
//    showGraph2(mst);
//    freeGraph2(mst);
//    freeGraph2(g);
//    
//    return 0;
//}
