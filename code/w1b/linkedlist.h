//
//  linkedlist.h
//  code
//
//  Created by 郑淇文 on 2020/1/9.
//  Copyright © 2020 郑淇文. All rights reserved.
//
typedef struct Node{
    int data;
    struct Node *next;
}Node;
typedef Node* Link;

Link Turn(int[] ,int );
void insertOrderedLL(Link ,int ,int );
void printlinkedlist(Link);
void SplitList(Link);
