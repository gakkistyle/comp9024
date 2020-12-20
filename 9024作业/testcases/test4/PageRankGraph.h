//
//  PageRankGraph.h
//  9024作业
//
//  Created by 郑淇文 on 2020/1/21.
//  Copyright © 2020 郑淇文. All rights reserved.
//


#include <stdio.h>

typedef struct URLcontent{
    char name[10];
    int degree;
    double pagerank;
}UrlContent;


typedef struct URLGraph{
    int **edges;
    int nV;
}URLGraph;

typedef struct URLGraph *Graph;

Graph newGraph(int);

int findnum(struct URLcontent[],char *,int);

void insertedge(Graph g,int src,int dest);

void freegraph(Graph g);
