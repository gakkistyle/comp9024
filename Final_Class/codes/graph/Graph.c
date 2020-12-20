//
// Created by Rui.Mu on 2019-02-02.
//
// Graph ADT
// Adjacency Matrix Representation ... COMP9024 17s2
#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct GraphRep {
    int **edges;   // adjacency matrix
    int nV;      // #vertices
    int nE;      // #edges
} GraphRep;

Graph newGraph(int V) {
    assert(V >= 0);
    int i;

    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;

    // allocate memory for each row
    g->edges = malloc(V * sizeof(int *));
    assert(g->edges != NULL);
    // allocate memory for each column and initialise with 0
    for (i = 0; i < V; i++) {
        g->edges[i] = calloc(V, sizeof(int));
        assert(g->edges[i] != NULL);
    }

    return g;
}

// check if vertex is valid in a graph
bool validV(Graph g, Vertex v) {
    return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));

    if (!g->edges[e.v][e.w]) {  // edge e not in graph
        g->edges[e.v][e.w] = 1;
        g->nE++;
    }
}

void insertEdge1(Graph g, Vertex v, Vertex w){
    assert(g != NULL && validV(g, v) && validV(g, w));

    if (!g->edges[v][w]) {  // edge e not in graph
        g->edges[v][w] = 1;
        g->nE++;
    }
}

void removeEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));

    if (g->edges[e.v][e.w]) {   // edge e in graph
        g->edges[e.v][e.w] = 0;
        g->nE--;
    }
}

bool adjacent(Graph g, Vertex v, Vertex w) {
    assert(g != NULL && validV(g, v) && validV(g, w));

    return (g->edges[v][w] != 0);
}

void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
        for (j = 0; j < g->nV; j++)
            if (g->edges[i][j])
                printf("Edge %d - %d\n", i, j);
}

void freeGraph(Graph g) {
    assert(g != NULL);

    int i;
    for (i = 0; i < g->nV; i++)
        free(g->edges[i]);
    free(g->edges);
    free(g);
}

/**
 * get degree number of vertex in graph
 * @param graph
 * @param vertex
 * @return
 */
int degree(Graph graph, Vertex vertex) {
    int deg = 0;
    Vertex w;
    for (w = 0; w < graph->nV; w++)
        if (adjacent(graph, vertex, w))
            deg++;
    return deg;
}

