//
//  Graph.h
//  code
//
//  Created by 郑淇文 on 2020/1/14.
//  Copyright © 2020 郑淇文. All rights reserved.
//
#include <stdbool.h>

typedef struct GraphRep *Graph;

typedef int Vertex;

typedef struct Edge{
    Vertex v;
    Vertex w;
}Edge;

Graph newGraph(int);
int numOfVertices(Graph);
void insertEdge(Graph,Edge);
void removeEdge(Graph,Edge);
bool adjacent(Graph,Vertex,Vertex);
void showGraph(Graph);
void freeGraph(Graph);
