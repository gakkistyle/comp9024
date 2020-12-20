//
//  Linkedlist_s3.h
//  9024作业
//
//  Created by 郑淇文 on 2020/1/14.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#ifndef Linkedlist_s3_h
#define Linkedlist_s3_h


typedef struct node{
    char url[10];
    int count;
    struct node *next;
}node;

node *create_node(char *data,node *);
void append(node *head,char *data);
node *last(node *head);
//int data_in(node *data,char *arr[],int);
int url_in_list(node *data,char *url);

//node *deletenode(node *head,node *t);
//int token_in_list(node *head,char *);
void freelist(node*);
#endif /* Linkedlist_s3_h */
