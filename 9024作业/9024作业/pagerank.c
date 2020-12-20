//
//  pagerank.c
//  9024作业
//
//  Created by 郑淇文 on 2020/1/21.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "PageRankGraph.h"
#include <math.h>

#define MAXSTRING 1000
#define URLmax 1000       //the max record of the collection.txt
#define urllength 20      //the max length of url

int main(int argc,char *argv[]){
    
    //if arguments number is not 4 , return
    if(argc!=4)
        return 1;
    
    char delim[2] = " ";
    char *token;
    char line[MAXSTRING] ;
    FILE *f;
    int i=0;
    char *URLs[URLmax];
    int urlnum = 0;
    int flag = 0;
    double d = atof(argv[1]);
    double diffPR = atof(argv[2]);
    int maxiteration = atoi(argv[3]);
    
    if ((f = fopen ("collection.txt", "r")) == NULL) {
       printf("Error!\n");
       return (0);
    }
    
    //Use the Two-dimensional array URLs to record every url of collection.txt.
    while(fgets(line, MAXSTRING, f) != NULL){
           token = strtok(line, delim);
           while(token != NULL){
               if (token[0] != '\n'){
                   if(token[strlen(token)-1]=='\n')
                       token[strlen(token)-1] = 0;
                   URLs[i] = malloc(20);
                   strcpy(URLs[i], token);
                   i ++;
                   urlnum ++;
               }
               token = strtok(NULL,delim);
           }
    }
    
    //build up the graph to record the directional relation between urls.And initialize pagerank.
    Graph g = newGraph(urlnum);
    UrlContent *urlcontent = malloc(urlnum*sizeof(UrlContent));
    for(i=0;i<urlnum;i++){
        strcpy(urlcontent[i].name,URLs[i]);
        urlcontent[i].degree = 0;
        urlcontent[i].pagerank = 1.0/urlnum;
    }
    fclose(f);
    
    
    //Go through every url file to record the out degrees and out url.Begin after "section-1"
    for(i = 0;i<urlnum;i++){
        char *once = malloc(urllength);
        strcpy(once, URLs[i]);
        char *filename = strcat(once,".txt");
        if((f = fopen (filename, "r"))!=NULL){
            while(fgets(line, MAXSTRING, f) != NULL){
                token = strtok(line, delim);
                while (token != NULL) {
                    if(strcmp(token,"#end")==0){
                        flag = 0;
                        break;
                    }
                    //delete the end symbols
                    if(token[strlen(token)-1]=='\n')
                        token[strlen(token)-1] = 0;
                    if(strlen(token))
                        if(token[strlen(token)-1]==';'||token[strlen(token)-1]=='.'
                        ||token[strlen(token)-1]==','||token[strlen(token)-1]=='?')
                           token[strlen(token)-1] = 0;
                    
                    if(flag && token[0] != '\n'&&token[0]!='\0'){
                        if(g->edges[i][findnum(urlcontent, token, urlnum)]==0&&findnum(urlcontent, token, urlnum)!=i)
                            urlcontent[i].degree++;
                        insertedge(g, i, findnum(urlcontent, token, urlnum));

                    }
                    //if we find "section-1" ,then the search and record begin.
                    if(strcmp(token,"Section-1")==0)
                        flag = 1;
                    token = strtok(NULL,delim);
                }

            }
        }
        free(once);
        fclose(f);
    }

    
    int iter = 0;
    double diff = diffPR;
    
    //use the array to record the previous pagerank.
    double PageRankSet[urlnum];
    //the algorithm to compute pagerank
    while(iter<maxiteration && diff>=diffPR){
        for(int j = 0;j<urlnum;j++){
            PageRankSet[j] = urlcontent[j].pagerank;
        }
        for(i = 0;i<urlnum;i++){
            double sum = 0.0;
            for(int k =0;k<urlnum;k++){
                if(g->edges[k][i]==1&&k!=i){
                    sum = sum + (double)PageRankSet[k]/urlcontent[k].degree;
                }
            }
            urlcontent[i].pagerank = (double)d*sum+(double)(1.0-d)/urlnum;
        }
        diff = 0;
        for(int j=0;j<urlnum;j++){
            diff = diff + fabs(urlcontent[j].pagerank-PageRankSet[j]);
        }
        iter ++;
    }
    
    //use bubble sort to rank the urls by the pagerank.
    UrlContent temp;
    for(i=0;i<urlnum-1;i++){
        for(int j=urlnum-1;j>i;j--){
            if(urlcontent[j-1].pagerank<urlcontent[j].pagerank){
                temp.degree=urlcontent[j-1].degree;
                strcpy(temp.name, urlcontent[j-1].name);
                temp.pagerank = urlcontent[j-1].pagerank;
                urlcontent[j-1].degree=urlcontent[j].degree;
                strcpy( urlcontent[j-1].name, urlcontent[j].name);
                urlcontent[j-1].pagerank=urlcontent[j].pagerank;
                urlcontent[j].degree=temp.degree;
                strcpy( urlcontent[j].name, temp.name);
                urlcontent[j].pagerank=temp.pagerank;
            }
        }
    }
    
    //write the records to the pagerankList.txt.
    f = fopen("pagerankList.txt", "w");
    for(i=0;i<urlnum;i++){
        fprintf(f,"%s, ",urlcontent[i].name);
        fprintf(f,"%d, ",urlcontent[i].degree);
        fprintf(f,"%.7f\n",urlcontent[i].pagerank);
    }
    fclose(f);
    
    //the free operation
    free(urlcontent);
    freegraph(g);
    for(i=0;i<urlnum;i++)
        free(URLs[i]);
}
