//
//  main.c
//  9024作业
//
//  Created by 郑淇文 on 2020/1/11.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist_s3.h"
#define MAXSTRING 1000

int argv_in_set(char *ar,char **set,int n){
    int i;
    for(i=0;i<n;i++){
        if(strcmp(ar,set[i])==0)
            return 1;
    }
    return 0;
}

int main(int argc,char *argv[]) {
    char delim[2] = " ";
    char delim2[3] = ", ";
    char *token;
    char line[MAXSTRING] ;
    FILE *f;
    int count_argc = 1;
//    if ((f = fopen ("/Users/zhengqiwen/Desktop/9024作业/9024作业/invertedIndex.txt", "r")) == NULL) {
//       printf("Error!\n");
//        return (0);}
//    int j =0 ;
//    char *a[1000];
//    while(fgets(line, MAXSTRING, f) != NULL){
//        token = strtok(line, delim);
//        while (token != NULL){
//            if (token[0]!='\n'){
//                a[j] = malloc(10);
//                strcpy(a[j] ,token);
//                printf("%s\n",a[j]);
//                j++;
//            }
//            token = strtok(NULL, delim);
//        }
//    }
//    a[j] = malloc(10);
//    a[j] = "stop";
//    printf("%s\n",a[1]);
////
//
    if ((f = fopen ("invertedIndex.txt", "r")) == NULL) {
       printf("Error!\n");
       return (0);
    }
    fclose(f);
    node *head = create_node("1", NULL);
//    int flag = 0;
//    while(count_argc!=argc&&flag==0)
//    {
//        f = fopen ("invertedIndex.txt", "r");
//        while(fgets(line, MAXSTRING, f) != NULL)  {
//              token = strtok(line, delim);
//              if (strcmp(token,argv[count_argc])==0){
//                  flag = 1;
//                  token = strtok(NULL, delim);
//                  while( token != NULL ) {
//                      if(token[0]!='\n'&&token[0]!='\0')
//                      {
//                          append(head,token);
//                      }
//                      token = strtok(NULL, delim);
//                  }
//                  break;
//              }
//        }
//        count_argc ++;
//    }
//        node *l = head->next;
//        while(l!=NULL){
//            printf("%s\n",l->url);
//            l = l->next;
//        }
    char *Wordset[100];
    int wordindex = 0;
    while(count_argc!=argc){
        f = fopen ("invertedIndex.txt", "r");
        while(fgets(line, MAXSTRING, f) != NULL){
            token = strtok(line, delim);
            if (strcmp(token,argv[count_argc])==0&&argv_in_set(argv[count_argc],Wordset,wordindex)==0){
                Wordset[wordindex] = malloc(30);
                strcpy(Wordset[wordindex],argv[count_argc]);
                wordindex++;
                token = strtok(NULL, delim);
                while( token != NULL){
                    if(token[0]!='\n'&&token[0]!='\0'){
                        if(token[strlen(token)-1]=='\n')
                           token[strlen(token)-1] = 0;
                        append(head,token);
                    }
                    token = strtok(NULL, delim);
                }
            }
        }
        count_argc++;
        fclose(f);
    }
    
    if ((f = fopen ("pagerankList.txt", "r")) == NULL) {
       printf("Error!\n");
       return (0);
    }
    fclose(f);
    int i = argc-1;
    int count = 0;
    while(i!=0){
        f = fopen ("pagerankList.txt", "r");
        while(fgets(line, MAXSTRING, f) != NULL){
            token = strtok(line, delim2);
            if(url_in_list(head,token)==i&&count<30){
                printf("%s\n",token);
                count++;
            }
        }
        fclose(f);
        i--;
    }
    freelist(head);
    for(i=0;i<wordindex;i++)
        free(Wordset[wordindex]);
  
    
//    while (count_argc != argc){
//        f = fopen ("invertedIndex.txt", "r");
//        while(fgets(line, MAXSTRING, f) != NULL)  {
//            token = strtok(line, delim);
//            if (strcmp(token,argv[count_argc])==0){
//                int i = 0;
//                char *urls[100];
//                while(token != NULL){
//                    if (token[0] != '\n'&&token[0]!='\0'){
//                        if(token[strlen(token)-1]=='\n')
//                            token[strlen(token)-1] = 0;
//                        urls[i] = malloc(10);
//                        strcpy(urls[i], token);
//                        i ++;
//                    }
//                    token = strtok(NULL, delim);
//                }
//                node *t = head->next;
//                while(t!=NULL){
//                    if(data_in(t,urls,i)==0)
//                        t = deletenode(head, t);
//                    //printf("%s\n",t->url);
//                    t = t->next;
//                }
////                for(i=0;i<100;i++)
////                    free(urls[i]);
//                break;
//            }
//        }
//        count_argc++;
//    }
//    node *l = head->next;
//    while(l!=NULL){
//        printf("%s\n",l->url);
//        l = l->next;
//    }
//    FILE *f2;
//    if ((f2 = fopen ("pagerankList.txt", "r")) == NULL) {
//       printf("Error!\n");
//       return (0);
//    }
//
//    while(fgets(line, MAXSTRING, f2) != NULL){
//        token = strtok(line, delim2);
//        if (token_in_list(head,token)==1){
//
//            printf("%s\n",token);
//        }
//       // printf("%s\n",token);
//    }
//    freelist(head);
    
 //   fclose(f);
       
    return 0;
    }

