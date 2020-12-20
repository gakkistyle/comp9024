//
//  WGraph.c
//  code
//
//  Created by 郑淇文 on 2020/1/25.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "WGraph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct GraphRep{
    int **edges;
    int nV;
    int nE;
}GraphRep;

Graph newGraph2(int V){
    assert(V>=0);
    int i;
    
    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;
    
    g->edges = malloc(V*sizeof(int *));
    assert(g->edges!=NULL);
    for(i=0;i<V;i++){
        g->edges[i] = calloc(V, sizeof(int));
        assert(g->edges[i]!=NULL);
    }
    return g;
}

int numOfVertices2(Graph g){
    return g->nV;
}

int validV2(Graph g,Vertex v){
    return (g!=NULL && v>=0 &&v<g->nV);
}

void insertEdge2(Graph g,Edge e){
    assert(g!=NULL && validV2(g,e.v)&&validV2(g,e.w));
    
    if(g->edges[e.v][e.w]==0){
        g->edges[e.v][e.w] = e.weight;
        g->nE++;
    }
}

void removeEdge2(Graph g,Edge e){
    assert(g!=NULL && validV2(g,e.v)&&validV2(g,e.w));
    
    if(g->edges[e.v][e.w]!=0){
        g->edges[e.v][e.w] = 0;
        g->nE--;
    }
}

int adjacent2(Graph g,Vertex v,Vertex w){
    assert(g!=NULL && validV2(g,v) && validV2(g,w));
    return g->edges[v][w];
}

void showGraph2(Graph g){
    assert(g!=NULL);
    int i,j;
    
    printf("Number of vertices: %d\n",g->nV);
    printf("Number of edges: %d\n",g->nE);
    for(i=0;i<g->nV;i++)
        for(j=0;j<g->nV;j++)
            if(g->edges!=0)
                printf("Edge %d - %d: %d\n",i,j,g->edges[i][j]);
}

void freeGraph2(Graph g){
    assert(g!=NULL);
    
    int i;
    for(i = 0 ;i<g->nV;i++)
        free(g->edges[i]);
    free(g->edges);
    free(g);
}
