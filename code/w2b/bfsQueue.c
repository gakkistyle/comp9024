//
//  bfsQueue.c
//  code
//
//  Created by 郑淇文 on 2020/1/16.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "Graph.h"

#define MAX_NODES 1000

int Visited[MAX_NODES];

bool findPathBFS(Graph g,Vertex src,Vertex dest){
    Vertex v;
    int nV = numOfVertices(g);
    for (v=0;v<nV;v++)
        Visited[v] = -1;
    
    queue Q = newQueue();
    QueueEnqueue(Q, src);
    Visited[src] = src;
    while (!QueueIsEmpty(Q)) {
        v = QueueDequeue(Q);
        if (v == dest)
            return true;
        else{
            Vertex w;
            for (w=0;w<nV;w++){
                if(adjacent(g, v, w)&&Visited[w] == -1){
                    QueueEnqueue(Q, w);
                    Visited[w] = v;
                }
            }
        }
    }
    return false;
}

//int main(){
//    Graph g = newGraph(10);
//    
//    Edge e;
//    e.v = 0; e.w = 1; insertEdge(g, e);
//    e.v = 0; e.w = 2; insertEdge(g, e);
//    e.v = 0; e.w = 5; insertEdge(g, e);
//    e.v = 1; e.w = 5; insertEdge(g, e);
//    e.v = 2; e.w = 3; insertEdge(g, e);
//    e.v = 3; e.w = 4; insertEdge(g, e);
//    e.v = 3; e.w = 5; insertEdge(g, e);
//    e.v = 3; e.w = 8; insertEdge(g, e);
//    e.v = 4; e.w = 5; insertEdge(g, e);
//    e.v = 4; e.w = 7; insertEdge(g, e);
//    e.v = 4; e.w = 8; insertEdge(g, e);
//    e.v = 5; e.w = 6; insertEdge(g, e);
//    e.v = 7; e.w = 8; insertEdge(g, e);
//    e.v = 7; e.w = 9; insertEdge(g, e);
//    e.v = 8; e.w = 9; insertEdge(g, e);
//    
//    int src = 1; int dest = 6;
//    if (findPathBFS(g, src, dest)){
//        Vertex v = dest;
//        while(v != src){
//            printf("%d - ",v);
//            v = visited[v];
//        }
//        printf("%d\n",src);
//    }
//    return 0;
//}
