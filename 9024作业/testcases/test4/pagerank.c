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
#define MAXSTRING 1000
#include <math.h>
int main(int argc,char *argv[]){
    if(argc!=4)
        return 1;
    
    char delim[2] = " ";
    char *token;
    char line[MAXSTRING] ;
    FILE *f;
    int i=0;
    char *URLs[100];
    int urlnum = 0;
    int flag = 0;
    double d = atof(argv[1]);
    double diffPR = atof(argv[2]);
    int maxiteration = atoi(argv[3]);
    
    if ((f = fopen ("collection.txt", "r")) == NULL) {
       printf("Error!\n");
       return (0);
    }
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
    Graph g = newGraph(urlnum);
    UrlContent *urlcontent = malloc(urlnum*sizeof(UrlContent));
    for(i=0;i<urlnum;i++){
        strcpy(urlcontent[i].name,URLs[i]);
        urlcontent[i].degree = 0;
        urlcontent[i].pagerank = 1.0/urlnum;
    }
//    printf("%d\n",urlnum);
//    printf("%s\n",urlcontent[3].name);

    for(i = 0;i<urlnum;i++){
        char *once = malloc(20);
        strcpy(once, URLs[i]);
        char *filename = strcat(once,".txt");
        if((f = fopen (filename, "r"))!=NULL){
      //      printf("%s\n",filename);
            while(fgets(line, MAXSTRING, f) != NULL){
                token = strtok(line, delim);
                while (token != NULL) {
                    if(strcmp(token,"#end")==0){
                        flag = 0;
                        break;
                    }
                    if(token[strlen(token)-1]=='\n'||token[strlen(token)-1]=='.'
                       ||token[strlen(token)-1]==','||token[strlen(token)-1]=='?'
                       ||token[strlen(token)-1]==';')
                        token[strlen(token)-1] = 0;
                    if(token[strlen(token)-1]==';'||token[strlen(token)-1]=='.'
                       ||token[strlen(token)-1]==','||token[strlen(token)-1]=='?')
                        token[strlen(token)-1] = 0;
                    if(flag && token[0] != '\n'&&token[0]!='\0'){
                        if(g->edges[i][findnum(urlcontent, token, urlnum)]==0)
                            urlcontent[i].degree++;
                        insertedge(g, i, findnum(urlcontent, token, urlnum));
                     //   printf("%s\n",token);

                    }
                    if(strcmp(token,"Section-1")==0)
                        flag = 1;
                    token = strtok(NULL,delim);
                }
//                if(strcmp(token,"#end")==0)
//                    break;
            }
        }
        free(once);
    }
//    for(int j = 0;j<urlnum;j++){
//        for(int k =0;k<urlnum;k++)
//            printf("%d ",g->edges[j][k]);
//        printf("\n");
//    }
    
    int iter = 0;
    double diff = diffPR;
    
    double PageRankSet[urlnum];
    
    while(iter<maxiteration && diff>=diffPR){
        for(int j = 0;j<urlnum;j++){
            PageRankSet[j] = urlcontent[j].pagerank;
        }
        for(i = 0;i<urlnum;i++){
            double sum = 0.0;
            for(int k =0;k<urlnum;k++){
                if(g->edges[k][i]==1&&k!=i){
                    sum = sum + (double)PageRankSet[k]/urlcontent[k].degree;
                 //   printf("%lf ",sum);
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
    
//    for(int j=0;j<urlnum;j++){
//        printf("%d   ",urlcontent[j].degree);
//        printf("%.7f\n",urlcontent[j].pagerank);
//    }

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
    f = fopen("pagerankList.txt", "w");
    for(i=0;i<urlnum;i++){
        fprintf(f,"%s, ",urlcontent[i].name);
        fprintf(f,"%d, ",urlcontent[i].degree);
        fprintf(f,"%.7f\n",urlcontent[i].pagerank);
    }
    fclose(f);
    free(urlcontent);
    freegraph(g);
    free(URLs);
}
