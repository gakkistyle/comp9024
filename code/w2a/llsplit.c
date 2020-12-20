//
//  llsplit.c
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


int count = 0;
NodeT *makeNode2(int value){
    NodeT *new = malloc(sizeof(NodeT));
    new->num = value;
    new->next = NULL;
    return new;
}

NodeT *joinLL2(NodeT *head,NodeT *new){
    NodeT *t = head;
    while (t->next!=NULL)
        t = t->next;
    t->next = new;
    count ++;
    return head;
}
void showLL2(NodeT *head){
    NodeT *t = head->next;
    NodeT *sec;
    int i;
    printf("Done.");
    if(t!=NULL){
        printf(" List is ");
        while(t!=NULL){
            printf("%d",t->num);
            if(t->next!=NULL)
                printf("->");
//            if(i == 1+(count/2))
//                sec=t;
            t = t->next;
//            i ++;
        }
        putchar('\n');
        printf("First part is ");
        sec = head->next;
        if(count%2==1){
            for(i = 0;i<1+(count/2);i++)
            {
                printf("%d",sec->num);
                if(i!=count/2)
                    printf("->");
                sec = sec->next;
            }
        }
        else{
            for(i = 0;i<(count/2);i++)
                {
                    printf("%d",sec->num);
                    if(i!=(count/2)-1)
                        printf("->");
                    sec = sec->next;
                }
            }
        
        if(count>1){
            putchar('\n');
            printf("Second part is ");
            while (sec!=NULL) {
                printf("%d",sec->num);
                if(sec->next!=NULL)
                    printf("->");
                sec = sec->next;
            }
        }
    }
    printf("\n");
}

void freeLL2(NodeT *head){
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
//        head = joinLL2(head, makeNode2(n));
//        printf("Enter an integer: ");
//    }
//    showLL2(head);
//    freeLL2(head);
//}
