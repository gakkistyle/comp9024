//
//  DLList.c
//  code
//
//  Created by 郑淇文 on 2020/1/11.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "DLList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct DLListNode{
    int  value;
    struct DLListNode *prev;
    struct DLListNode *next;
}DLListNode;

typedef struct DLListRep{
    int nitems;
    DLListNode *first;
    DLListNode *curr;
    DLListNode *last;
}DLListRep;

static DLListNode *newLListNode(int it)
{
    DLListNode *new;
    new = malloc(sizeof(DLListNode));
    assert(new != NULL);
    new -> value = it;
    new -> prev = new -> next = NULL;
    return new;
}

DLList newDLList()
{
    struct DLListRep *L;
    L = malloc(sizeof(struct DLListRep));
    assert(L!=NULL);
    L->nitems = 0;
    L->first = NULL;
    L->last = NULL;
    return L;
}

void freeDLList(DLList L)
{
    assert(L!= NULL);
    DLListNode *curr,*prev;
    curr = L->first;
    while (curr!=NULL){
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(L);
}

void showDLList(DLList L)
{
    assert(L!=NULL);
    DLListNode *curr;
    int count;
    for(curr=L->first;curr!=NULL;curr=curr->next){
        count ++;
        if(count>1){
            fprintf(stdout,", ");
        }
        fprintf(stdout,"%d",curr->value);
    }
    fprintf(stdout, "\n");
}

int DLListCurrent(DLList L)
{
    assert(L!=NULL); assert(L->curr!=NULL);
    return L->curr->value;
}

int DLListMove(DLList L, int n)
{
    assert(L!=NULL);
    if(L->curr == NULL)
        return 1;
    else if(n>0){
        while(n>0&&L->curr->next!=NULL){
            L->curr = L->curr->next;
            n--;
        }
    }
    else if(n<0){
        while (n<0&&L->curr->prev!=NULL) {
            L->curr = L->curr->prev;
            n++;
        }
    }
    return (L->curr == L->first||L->curr == L->last);
}

int DLListMoveTo(DLList L,int i)
{
    assert(L!=NULL); assert(i>0);
    L->curr = L->first;
    return DLListMove(L, i-1);
}

void DLListAfter(DLList L,int it)
{
    assert(L!=NULL);
    DLListNode *new = newLListNode(it);
    assert(new != NULL);
    if(L->first == NULL && L->last){
        L->curr = L->first = L->last = new;
    }
    else if(L->curr == L->last){
        new->prev = L->last;
        L->last->next = new;
        L->curr = L->last = new;
    }
    else{
        new->prev = L->curr;
        new->next = L->curr->next;
        L->curr->next->prev = new;
        L->curr->next = new;
    }
    L->curr = new;
    L->nitems++;
}

void DLListDelete(DLList L)
{
    assert(L!=NULL);
    DLListNode *old = L->curr;
    if (L->nitems==0||old == NULL){
        return;
    }
    else if (old == L->first && old == L->last){
        L->curr = L->first = L->last = NULL;
    }
    else if (old == L->first){
        old ->next->prev = NULL;
        L->curr = L->first = old->next;
    }
    else if (old == L->last){
        old -> prev->next = NULL;
        L->curr = L->last = old->prev;
    }
    else{
        old->prev->next = old->next;
        old->next->prev = old->prev;
        L->curr = old ->next;
    }
    free(old);
    L->nitems--;
}

int DLListLength(DLList L)
{
    return (L->nitems);
}
