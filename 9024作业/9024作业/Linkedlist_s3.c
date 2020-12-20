//
//  Linkedlist_s3.c
//  9024作业
//
//  Created by 郑淇文 on 2020/1/14.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "Linkedlist_s3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node *create_node(char *data,node *next){
    node *n = malloc(sizeof(node));
    if(n == NULL){
        fprintf(stderr, "out of memory!\n");
        exit(1);
    }
    if(data[strlen(data)-1]=='\n')
    {
        data[strlen(data)-1] = 0;
    }
    
    strcpy(n->url, data);
    n->count = 1;
    n->next = next;
    return n;
}

node *last(node *head){
    if (head == NULL){
        return NULL;
    }
    node *n = head;
    while (n->next !=NULL){
        n = n->next;
    }
    return n;
}

int url_in_list(node *head,char *url){
    node *t = head;
    while(t != NULL){
        if (strcmp(t->url,url)==0)
            return t->count;
        t = t->next;
    }
    return 0;
}


void append(node *head,char *data){
    if(url_in_list(head, data)==0){
        node *n = create_node(data, NULL);
        if (head == NULL){
            return ;
        }
        else{
            last(head)->next = n;
        }
    }
    else{
        node *t = head;
        while(strcmp(t->url,data)!=0)
            t = t->next;
        t->count ++;
    }
}

void freelist(node *head){
    node *t = head->next;
    while (t!=NULL){
        node *old = t;
        t = t->next;
        free(old);
    }
    free(head);
}
