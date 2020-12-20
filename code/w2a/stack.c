//
//  stack.c
//  code
//
//  Created by 郑淇文 on 2020/1/11.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "stack.h"
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    int data;
    struct node *next;
}NodeT;

typedef struct StackRep{
    int   height;
    NodeT *top;
}StackRep;

stack newStack(){
    stack S = malloc(sizeof(StackRep));
    S -> height = 0;
    S -> top = NULL;
    return S;
}

void dropStack(stack S){
    NodeT *curr = S -> top;
    while (curr != NULL){
        NodeT *temp = curr -> next;
        free(curr);
        curr = temp;
    }
    free(S);
}

int StackIsEmpty(stack S){
    return (S->height == 0);
}

void StackPush(stack S,int v){
    NodeT *new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new -> data = v;
    new -> next = S -> top;
    S -> top = new;
    S -> height ++;
}

int StackPop(stack S){
    assert(S->height>0);
    NodeT *head = S->top;
    S->top = S->top->next;
    S->height -- ;
    int d = head->data;
    free(head);
    return d;
}
