//
//  linkedlist.c
//  code
//
//  Created by 郑淇文 on 2020/1/9.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "linkedlist.h"
#include<stdlib.h>
#include<stdio.h>
//typedef struct {
//    int data;
//    struct Node* next;
//}Node;
//typedef Node* Link;
Link Turn(int arr[],int n)
{
    int i;
    Link link = malloc((n+1)*sizeof(Node));
    for (i=0;i<n+1;i++)
        link[i].next = &(link[i+1]);
    link[n].next = NULL;
    Link t = link->next;
    for(i=0;i<n;i++)
    {
//        printf("11");
        t->data = arr[i];
        t = t->next;
    }
    return link;
}

void insertOrderedLL(Link link,int num,int n)
{
    int i;
    Link new = malloc(sizeof(Node));
    new -> data = num;
    new -> next = NULL;
    Link nextone = link->next;
    if(link->next == NULL || nextone->data>new->data)
    {
        new -> next = link->next;
        link ->next = new;
    }
    else{
        Link t = link->next;
        for(i=0;i<n;i++)
        {
            Link nextone = t->next;
            
            if((t->data<new->data&&t->next == NULL)||
              ( t->data<new->data&&nextone->data>new->data)){
                new->next = t->next;
                t->next = new;
                break;
            }
            t = t->next;
        }
    }
}

void printlinkedlist(Link link){
    Link t = link->next;
    while( t !=NULL){
        printf("%d ",t ->data);
        t= t->next;
    }
    printf("\n");
}

void SplitList(Link l){
    Link slow = l->next;
    Link fast = slow->next;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    Link l2 = slow->next;
    slow->next = NULL;
    printf("First half: ");
    printlinkedlist(l);
    printf("Second half: ");
    while( l2 !=NULL){
        printf("%d ",l2 ->data);
        l2= l2->next;
    }
    printf("\n");
    
    
}
