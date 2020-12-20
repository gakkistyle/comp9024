//
//  PageRankGraph.h
//  9024作业
//
//  Created by 郑淇文 on 2020/1/21.
//  Copyright © 2020 郑淇文. All rights reserved.
//


#include <stdio.h>
#define urllength 20

//the structure to record the url's name,out degree and pagerank.
typedef struct URLcontent{
    char name[urllength];
    int degree;
    double pagerank;
}UrlContent;

//the graph to record the out urls of every url
typedef struct URLGraph{
    int **edges;
    int nV;
}URLGraph;

typedef struct URLGraph *Graph;

//create a new graph with n vertices
Graph newGraph(int);

//find the index of a specified url in the urlcontent
int findnum(struct URLcontent[],char *,int);

//insert the new edge to the graph
void insertedge(Graph g,int src,int dest);

//free the graph
void freegraph(Graph g);
