//
//  WGraph.h
//  code
//
//  Created by 郑淇文 on 2020/1/25.
//  Copyright © 2020 郑淇文. All rights reserved.
//

typedef struct GraphRep *Graph;

typedef int Vertex;

typedef struct Edge{
    Vertex v;
    Vertex w;
    int  weight;
}Edge;

Graph newGraph2(int);
int numOfVertices2(Graph);
void insertEdge2(Graph,Edge);
void removeEdge2(Graph,Edge);
int adjacent2(Graph,Vertex,Vertex);
void showGraph2(Graph);
void freeGraph2(Graph);
