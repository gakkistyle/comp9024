//
//  demo.c
//  code
//
//  Created by 郑淇文 on 2020/1/15.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include "Graph.h"
#define MAXNODES 100


int visited[MAXNODES];

int reachable(Graph g, int nV, int v){
    visited[v] = 1;
    int total = 0;
    
    for (int w=0;w<nV;w++){
        if(adjacent(g, v, w)&&visited[w] == -1){
            total =total + reachable(g, nV, w);
        }
    }
    total = total + 1;
    return total;
}


//int main(){
//    int nV = 10;
//    Graph g = newGraph(nV);
//
//    Edge e;
//    e.v = 0; e.w = 1; insertEdge(g, e);
//    e.v = 2; e.w = 1; insertEdge(g, e);
//    e.v = 3; e.w = 0; insertEdge(g, e);
//    e.v = 4; e.w = 2; insertEdge(g, e);
//    e.v = 5; e.w = 3; insertEdge(g, e);
//   // e.v = 5; e.w = 6; insertEdge(g, e);
//    e.v = 6; e.w = 7; insertEdge(g, e);
//    e.v = 7; e.w = 8; insertEdge(g, e);
//    e.v = 8; e.w = 9; insertEdge(g, e);
//
//    showGraph(g);
//
//    for (int i = 0;i<nV;i++){
//        visited[i] = -1;
//    }
//    visited[0] = 1;
//    
//    int nodes = reachable(g,10,0);
//    
//    printf("nodes is %d \n",nodes);
//    printf("1\n");
//    return 0;
//}
