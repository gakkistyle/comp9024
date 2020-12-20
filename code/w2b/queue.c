//
//  queue.c
//  code
//
//  Created by 郑淇文 on 2020/1/16.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "queue.h"
#include <assert.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NodeT;

typedef struct QueueRep{
    int length;
    NodeT *head;
    NodeT *tail;
}QueueRep;

queue newQueue(){
    queue Q = malloc(sizeof(QueueRep));
    Q->length = 0;
    Q->head = NULL;
    Q->tail = NULL;
    return Q;
}

void dropQueue(queue Q){
    NodeT *curr = Q->head;
    while (curr != NULL){
        NodeT *temp = curr -> next;
        free(curr);
        curr = temp;
    }
}

int queueIsEmpty(queue Q){
    return (Q->length == 0);
}

void queueEnqueue(queue Q,int v){
    NodeT *new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->data = v;
    new->next = NULL;
    if (Q->tail != NULL){
        Q->tail->next = new;
        Q->tail = new;
    }
    else{
        Q->head = new;
        Q->tail = new;
    }
    Q->length++;
}

int queueDequeue(queue Q){
    assert(Q->length > 0);
    NodeT *p = Q->head;
    Q->head = Q->head->next;
    if(Q->head == NULL){
        Q->tail = NULL;
    }
    Q->length--;
    int d = p->data;
    free(p);
    return d;
}
