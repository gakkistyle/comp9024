//
// Created by YUJiehu on 2019-02-02.
//

#ifndef COMP9024_GRAPH_H
#define COMP9024_GRAPH_H

#include <stdbool.h>

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge {
    Vertex v;
    Vertex w;
    int weight;
} Edge;

Graph newGraph(int);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
bool  adjacent(Graph, Vertex, Vertex);

void insertEdge1(Graph g, Vertex, Vertex);
        void  showGraph(Graph);
void  freeGraph(Graph);

/**
 * degree number of vertex
 * @return number degree of vertex
 */
int degree(Graph, Vertex);

#endif //COMP9024_GRAPH_H
