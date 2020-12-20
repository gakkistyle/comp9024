//
//  Trie.c
//  code
//
//  Created by 郑淇文 on 2020/2/3.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "Trie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
#define FIRST_CHAR 'a'
#define NO_ITEM 0

typedef struct Node{
    bool finish;
    Item data;
    Trie child[ALPHABET_SIZE];
}Node;

Trie newTrie(){
    return NULL;
}

void freeTrie(Trie t){
    if(t!=NULL){
        int c;
        for(c=0;c<ALPHABET_SIZE;c++)
            freeTrie(t->child[c]);
        free(t);
    }
}

Node *newNode4(){
    Trie new = malloc(sizeof(Node));
    assert(new != NULL);
    new->finish = false;
    new->data = NO_ITEM;
    int c;
    for(c=0;c<ALPHABET_SIZE;c++)
        new->child[c] = NULL;
    return new;
}

Trie TrieInsert(Trie t,Key k,Item it){
    if (t==NULL)
        t = newNode4();
    
    if(k[0]=='\0'){
        t->finish = true;
        t->data = it;
    }else{
        int i = k[0] - FIRST_CHAR;
        t->child[i] = TrieInsert(t->child[i],k+1,it);
    }
    return t;
}

static bool newline;

void showTrieR(Trie t,int depth){
    int i,d;
    if(t!=NULL){
        for(i=0;i<ALPHABET_SIZE;i++){
            if(t->child[i]!=NULL){
                if(newline){
                    for(d=0;d<depth;d++)
                        putchar('-');
                    newline = false;
                }
                printf("%c",(char)i+FIRST_CHAR);
                if(t->child[i]->finish){
                    printf(" %d\n",t->child[i]->data);
                    newline = true;
                }
                showTrieR(t->child[i],depth+1);
            }
        }
    }
}

void showTrie(Trie t){
    newline = false;
    showTrieR(t,0);
}
