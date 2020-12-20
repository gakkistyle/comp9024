//
//  PageRankGraph.c
//  9024作业
//
//  Created by 郑淇文 on 2020/1/21.
//  Copyright © 2020 郑淇文. All rights reserved.
//
#include <assert.h>
#include "PageRankGraph.h"
#include <stdlib.h>
#include <string.h>
Graph newGraph(int n){
    assert(n>=0);
    int i;
    Graph g = malloc(sizeof(URLGraph));
    assert(g!=NULL);
    g->nV = n;
    
    g->edges = malloc(n*sizeof(int *));
    assert(g->edges!=NULL);
    for(i=0;i<n;i++){
        g->edges[i] = calloc(n, sizeof(int));
        assert(g->edges[i]!=NULL);
    }
    return g;
}

int findnum(struct URLcontent urlcontent[],char *url,int urlnum){
    int i;
    for(i=0;i<urlnum;i++)
        if(strcmp(urlcontent[i].name,url)==0)
            return i;
    return -1;
}

void insertedge(Graph g,int src,int dest){
    if(!g->edges[src][dest]){
        g->edges[src][dest] = 1;
    }
}

void freegraph(Graph g){
    int i;
    for(i=0;i<g->nV;i++)
        free(g->edges[i]);
    free(g->edges);
    free(g);
}
