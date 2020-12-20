//
//  llbuild.c
//  code
//
//  Created by 郑淇文 on 2020/1/19.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT{
    int num;
    struct NodeT *next;
}NodeT;

NodeT *makeNode(int value){
    NodeT *new = malloc(sizeof(NodeT));
    new->num = value;
    new->next = NULL;
    return new;
}

NodeT *joinLL(NodeT *head,NodeT *new){
    NodeT *t = head;
    while (t->next!=NULL)
        t = t->next;
    t->next = new;
    return head;
}
void showLL(NodeT *head){
    NodeT *t = head->next;
    printf("Done.");
    if(t!=NULL)
        printf(" List is ");
    while(t!=NULL){
        printf("%d",t->num);
        if(t->next!=NULL)
            printf("->");
        t = t->next;
    }
    printf("\n");
}

void freeLL(NodeT *head){
    NodeT *t = head->next;
    while(t!=NULL){
        NodeT *curr = t;
        t = t->next;
        free(curr);
    }
    free(head);
}

//int main(){
//    printf("Enter an integer: ");
//    int n;
//    NodeT *head = malloc(sizeof(NodeT));
//    head->num = 0;
//    head->next = NULL;
//    while (scanf("%d",&n)) {
//        head = joinLL(head, makeNode(n));
//        printf("Enter an integer: ");
//    }
//    showLL(head);
//    freeLL(head);
//}
