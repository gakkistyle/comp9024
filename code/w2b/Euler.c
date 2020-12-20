//
//  Euler.c
//  code
//
//  Created by 郑淇文 on 2020/1/19.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "Graph.h"

int degree(Graph g,Vertex v){
    int deg = 0;
    Vertex w;
    for (w = 0;w<numOfVertices(g);w++)
        if (adjacent(g, v, w))
            deg ++;
    return deg;
}

bool hasEulerPath(Graph g,Vertex v,Vertex w){
    if (v!=w){
        if(degree(g,v)%2==0||degree(g,w)%2 == 0)
            return false;
    }else if(degree(g,v)%2!=0){
        return false;
    }
    Vertex x;
    for (x=0;x<numOfVertices(g);x++)
        if(x!=v && x!=w && degree(g,x)%2!=0)
            return false;
    return true;
}

//int main(){
//    Graph g = newGraph(6);
//    Edge e;
//
//    e.v = 0;e.w = 1; insertEdge(g, e);
//    e.v = 0;e.w = 2; insertEdge(g, e);
//    e.v = 1;e.w = 3; insertEdge(g, e);
//    e.v = 2;e.w = 3; insertEdge(g, e);
//    e.v = 2;e.w = 4; insertEdge(g, e);
//    e.v = 4;e.w = 5; insertEdge(g, e);
//    printf("--------------------\n");
//    showGraph(g);
//
//    Vertex src, dest;
//    printf("\nEnter source node: ");
//    scanf("%d",&src);
//    printf("Enter destination node: ");
//    scanf("%d",&dest);
//
//    printf("The graph has ");
//    if (hasEulerPath(g, src, dest))
//        printf("an");
//    else
//        printf("no");
//    printf(" Euler path from %d to %d.\n",src,dest);
//
//    freeGraph(g);
//    return 0;
//}
