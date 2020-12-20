
//
//  inverted.c
//  9024作业
//
//  Created by 郑淇文 on 2020/1/16.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "Wordlist.h"

#define MAXSTRING 1000
#define Wordmax 30
int main(){
    char delim[2] = " ";
    char delim2[3] = ", ";
    char *token;
    char line[MAXSTRING] ;
    FILE *f;
    char *URLs[100];
    int i=0;
    int urlnum = 0;
    int flag = 0;
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
//    for(i = 0 ; i<urlnum;i++){
//        printf("%s\n",URLs[i]);
//    }
    wordNode *head = InitwordNode();
    
    for(i = 0;i<urlnum;i++){
        char *once = malloc(20);
        strcpy(once, URLs[i]);
        char *filename = strcat(once,".txt");
        if((f = fopen (filename, "r"))!=NULL){
      //      printf("%s\n",filename);
            while(fgets(line, MAXSTRING, f) != NULL){
                token = strtok(line, delim);
                while (token != NULL) {
                    if(token[0]=='#'){
                        flag = 0;
                    }
                    if(token[strlen(token)-1]=='\n'||token[strlen(token)-1]=='.'
                       ||token[strlen(token)-1]==','||token[strlen(token)-1]=='?'
                       ||token[strlen(token)-1]==';')
                        token[strlen(token)-1] = 0;
                    if(token[strlen(token)-1]==';'||token[strlen(token)-1]=='.'
                       ||token[strlen(token)-1]==','||token[strlen(token)-1]=='?')
                        token[strlen(token)-1] = 0;
                    if(flag && token[0] != '\n'&&token[0]!='\0'){
                        int j;
                        for(j=0;j<strlen(token);j++){
                            token[j] =  tolower(token[j]);
                        }
                     //   printf("%s\n",token);
                        InsertWordNode(head, token, URLs[i]);
                    }
                    if(strcmp(token,"Section-2")==0)
                        flag = 1;
                    token = strtok(NULL,delim);
                }
            }
        }
        free(once);
    }
    
    f = fopen("invertedIndex.txt", "w");
    wordNode *t = head->next;
    while(t!=NULL){
        fprintf(f,"%s ",t->word);
        urlNode *u = t->urlcontains->next;
        while(u->next!=NULL){
            fprintf(f,"%s ",u->url);
            u = u->next;
        }
        fprintf(f,"%s",u->url);
        t = t->next;
        if(t!=NULL)
            fprintf(f,"\n");
    }
    fclose(f);
    freewordlist(head);
    
}
