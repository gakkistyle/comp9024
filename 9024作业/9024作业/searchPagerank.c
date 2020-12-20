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
#define Wordmax 40          //the max length of a word
#define ArgumentMax 100     //the max arguments input

//check if the  duplicated argv
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
    if ((f = fopen ("invertedIndex.txt", "r")) == NULL) {
       printf("Error!\n");
       return (0);
    }
    fclose(f);
    node *head = create_node("1", NULL);
    
    //uset the wordset to record the not duplicated arguments input
    char *Wordset[ArgumentMax];
    int wordindex = 0;
    while(count_argc!=argc){
        f = fopen ("invertedIndex.txt", "r");
        while(fgets(line, MAXSTRING, f) != NULL){
            token = strtok(line, delim);
            
            //if the token match the argument word and the word is not in wordset
            if (strcmp(token,argv[count_argc])==0&&argv_in_set(argv[count_argc],Wordset,wordindex)==0){
                Wordset[wordindex] = malloc(Wordmax);
                strcpy(Wordset[wordindex],argv[count_argc]);
                wordindex++;
                token = strtok(NULL, delim);
                while( token != NULL){
                    if(token[0]!='\n'&&token[0]!='\0'){
                        if(token[strlen(token)-1]=='\n')
                           token[strlen(token)-1] = 0;
                        
                        //append the token to the list
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
    
    //Within the url of same count,rank them by the pagerank.
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
    
    //the free operation
    freelist(head);
    for(i=0;i<wordindex;i++)
        free(Wordset[i]);

    return 0;
    }

