//
//  KMP.c
//  code
//
//  Created by 郑淇文 on 2020/2/2.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_PATTERN_LENGTH 20
#define TEXT_FORMAT_STRING "%1023s"
#define PATTERN_FORMAT_STRING "%19s"

int *failureFunction(char *pattern){
    int m = strlen(pattern);
    int *F = malloc(m*sizeof(int));
    assert(F!=NULL);
    
    F[0] = 0;
    int i=1;
    int j=0;
    
    while(i<m){
        if(pattern[i]==pattern[j]){
            F[i++] = ++j;
        }else if(j>0){
            j = F[j-1];
        }else{
            F[i++]=0;
        }
    }
    return F;
}

int kmp(char *text,char *pattern,int *F){
    int n = strlen(text);
    int m = strlen(pattern);
    int i = 0;
    int j = 0;
    while(i<n){
        if(text[i] == pattern[j]){
            if(j == m-1){
                return i-j;
            }else{
                i++;
                j++;
            }
        }else if(j>0){
            j = F[j-1];
        }else{
            i ++;
        }
    }
    return -1;
}

//int main(){
//    char T[MAX_TEXT_LENGTH];
//    char P[MAX_PATTERN_LENGTH];
//    
//    printf("Enter text: ");
//    scanf(TEXT_FORMAT_STRING,T);
//    printf("Enter pattern: ");
//    scanf(PATTERN_FORMAT_STRING,P);
//    
//    int *F = failureFunction(P);
//    int match = kmp(T,P,F);
//    free(F);
//    if(match>-1)
//        printf("\nMatch found at position %d\n",match);
//    else
//        printf("\nNo match.\n");
//}
