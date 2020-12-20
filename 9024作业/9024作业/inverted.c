
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
#define Wordmax 40      //the max length of a word
#define URLmax 1000     //the max record of the collection.txt
#define urllength 20    //the max length of url
int main(){
    char delim[2] = " ";
    char *token;
    char line[MAXSTRING] ;
    FILE *f;
    char *URLs[URLmax];
    int i=0;
    int urlnum = 0;
    int flag = 0;
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
                URLs[i] = malloc(urllength);
                strcpy(URLs[i], token);
                i ++;
                urlnum ++;
            }
            token = strtok(NULL,delim);
        }
    }
    
    wordNode *head = InitwordNode();
    fclose(f);
    
    //open every url file to record words after "section-2".Add the new word to the right place.
    //If the word already in the list,add the url to the right place of the word.
    for(i = 0;i<urlnum;i++){
        char *once = malloc(urllength);
        strcpy(once, URLs[i]);
        char *filename = strcat(once,".txt");
        if((f = fopen (filename, "r"))!=NULL){
            while(fgets(line, MAXSTRING, f) != NULL){
                token = strtok(line, delim);
                while (token != NULL) {
                    if(token[0]=='#'){
                        flag = 0;
                    }
                    
                    //delete the end symbols
                    if(token[strlen(token)-1]=='\n')
                        token[strlen(token)-1] = 0;
                    if(strlen(token))
                        if(token[strlen(token)-1]==';'||token[strlen(token)-1]=='.'
                        ||token[strlen(token)-1]==','||token[strlen(token)-1]=='?')
                           token[strlen(token)-1] = 0;
                    
                    if(flag && token[0] != '\n'&&token[0]!='\0'){
                        int j;
                        for(j=0;j<strlen(token);j++){
                            token[j] =  tolower(token[j]);
                        }
                        InsertWordNode(head, token, URLs[i]);
                    }
                    
                    //if we find "section-2" ,then the search and record begin.
                    if(strcmp(token,"Section-2")==0)
                        flag = 1;
                    token = strtok(NULL,delim);
                }
            }
        }
        fclose(f);
        free(once);
       
    }
    
    //write the records to the invertedIndex.txt.
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
        fprintf(f,"\n");
    }
    fclose(f);
    freewordlist(head);
    for(i=0;i<urlnum;i++)
         free(URLs[i]);
    
    
}
