//
//  Hamiltonian.c
//  code
//
//  Created by 郑淇文 on 2020/1/25.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "Graph.h"

#define NODES 10

bool visited_2[NODES];

bool hamiltionR(Graph g,Vertex v,Vertex dest,int d){
    Vertex w;
    if(v == dest){
        return (d == 0);
    }else{
        visited_2[v] = true;
        for (w=0;w<numOfVertices(g);w++){
            if (adjacent(g,v,w) && !visited_2[w]){
                if (hamiltionR(g, w, dest, d-1)){
                    return true;
                }
            }
        }
    }
    visited_2[v] = false;
    return false;
}

bool hasHamiltonianPath(Graph g,Vertex src,Vertex dest){
    Vertex v;
    int nV = numOfVertices(g);
    for(v=0;v<nV;v++)
        visited_2[v] = false;
    return hamiltionR(g,src,dest, nV-1);
}
//
//int main(){
//    Graph g = newGraph(NODES);
//    Edge e;
//    
//    e.v = 0;e.w = 1;insertEdge(g, e);
//    e.v = 0;e.w = 2;insertEdge(g, e);
//    e.v = 0;e.w = 5;insertEdge(g, e);
//    e.v = 1;e.w = 5;insertEdge(g, e);
//    e.v = 2;e.w = 3;insertEdge(g, e);
//    e.v = 3;e.w = 4;insertEdge(g, e);
//    e.v = 3;e.w = 5;insertEdge(g, e);
//    e.v = 3;e.w = 8;insertEdge(g, e);
//    e.v = 4;e.w = 5;insertEdge(g, e);
//    e.v = 4;e.w = 7;insertEdge(g, e);
//    e.v = 4;e.w = 8;insertEdge(g, e);
//    e.v = 5;e.w = 6;insertEdge(g, e);
//    e.v = 5;e.w = 7;insertEdge(g, e);
//    e.v = 7;e.w = 8;insertEdge(g, e);
//    e.v = 7;e.w = 9;insertEdge(g, e);
//    e.v = 8;e.w = 9;insertEdge(g, e);
//    printf("----------------\n");
//    showGraph(g);
//    
//    Vertex src,dest;
//    printf("\nEnter source node: ");
//    scanf("%d",&src);
//    printf("Enter destination node: ");
//    scanf("%d",&dest);
//    
//    printf("The graph has ");
//    if(hasHamiltonianPath(g, src, dest))
//        printf("a");
//    else
//        printf("no");
//    printf(" Hamiltonian path from %d to %d.\n",src,dest);
//    
//    freeGraph(g);
//    return 0;
//}
