//
// Created by Rui.Mu on 2019-02-02.
//
#include <stdlib.h>
#include <assert.h>
#include "pqueue.h"

typedef struct pNode {
    int data;
    struct pNode *next;
} NodeP;

typedef struct PQueueRep {
    int   length;
    NodeP *head;
    NodeP *tail;
} PQueueRep;

// set up empty queue
PQueue newPQueue() {
    PQueue Q = malloc(sizeof(PQueueRep));
    Q->length = 0;
    Q->head = NULL;
    Q->tail = NULL;
    return Q;
}

// remove unwanted queue
void freePQueue(PQueue Q) {
    NodeP *curr = Q->head;
    while (curr != NULL) {
        NodeP *temp = curr->next;
        free(curr);
        curr = temp;
    }
    free(Q);
}

// check whether queue is empty
int PQueueIsEmpty(PQueue Q) {
    return (Q->length == 0);
}

// insert an int at end of queue
void joinPQueue(PQueue Q, int v) {
    NodeP *new = malloc(sizeof(NodeP));
    assert(new != NULL);
    new->data = v;
    new->next = NULL;
    if (Q->tail != NULL) {
        Q->tail->next = new;
        Q->tail = new;
    } else {
        Q->head = new;
        Q->tail = new;
    }
    Q->length++;
}

// remove int from front of queue
int leavePQueue(PQueue Q) {
    assert(Q->length > 0);
    NodeP *p = Q->head;
    Q->head = Q->head->next;
    if (Q->head == NULL) {
        Q->tail = NULL;
    }
    Q->length--;
    int d = p->data;
    free(p);
    return d;
}

