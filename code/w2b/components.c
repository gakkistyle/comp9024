//
//  components.c
//  code
//
//  Created by 郑淇文 on 2020/1/16.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

#define NODES 8

int componentOf[NODES];

void dfsComponents(Graph g,int v, int id){
    componentOf[v] = id;
    Vertex w;
    for (w=0;w<numOfVertices(g);w++)
        if (adjacent(g, v, w) && componentOf[w] == -1)
            dfsComponents(g, w, id);
}

int components(Graph g){
    Vertex v;
    int nV = numOfVertices(g);
    for(v=0;v<nV;v++)
        componentOf[v]=-1;
    int compID = 0;
    
    for(v=0;v<nV;v++){
        if(componentOf[v]==-1){
            dfsComponents(g, v, compID);
            compID++;
        }
    }
    return compID;
}

//int main(){
//    Graph g = newGraph(NODES);
//    Edge e;
//    
//    e.v = 0;e.w = 2;insertEdge(g, e);
//    e.v = 1;e.w = 2;insertEdge(g, e);
//    e.v = 3;e.w = 4;insertEdge(g, e);
//    e.v = 5;e.w = 6;insertEdge(g, e);
//    e.v = 5;e.w = 7;insertEdge(g, e);
//    e.v = 6;e.w = 7;insertEdge(g, e);
//    printf("---------------------\n");
//    showGraph(g);
//    
//    int i, c = components(g);
//    printf("Number of connected components: %d\n",c);
//    for(i = 0;i<c;i++){
//        printf("Component %d:\n",i+1);
//        Vertex v;
//        for(v=0;v<NODES;v++)
//            if(componentOf[v]==i)
//                printf("%d\n",v);
//    }
//    
//    e.v = 0;e.w = 1;insertEdge(g, e);
//    e.v = 2;e.w = 3;insertEdge(g, e);
//    printf("---------------------\n");
//    showGraph(g);
//    
//    c = components(g);
//    printf("Number of connected components: %d\n",components(g));
//    for(i=0;i<c;i++){
//        printf("Component %d:\n",i+1);
//        Vertex v;
//        for(v=0;v<NODES;v++)
//            if(componentOf[v]==i)
//                printf("%d\n",v);
//    }
//    
//    freeGraph(g);
//    return 0;
//}
