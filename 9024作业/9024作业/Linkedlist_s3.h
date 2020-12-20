//
//  Linkedlist_s3.h
//  9024作业
//
//  Created by 郑淇文 on 2020/1/14.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#ifndef Linkedlist_s3_h
#define Linkedlist_s3_h

#define urllength 20
typedef struct node{
    char url[urllength];
    int count;
    struct node *next;
}node;

node *create_node(char *data,node *);

//append the url to the list,if it already int the list,its count plus 1,if no create a new node.
void append(node *head,char *data);

//find the last node of the list
node *last(node *head);

//check if a url name in the list
int url_in_list(node *head,char *url);

//free the list
void freelist(node*);
#endif /* Linkedlist_s3_h */
