//
// Created by YUJiehu on 2019-02-02.
//

#ifndef COMP9024_LIST_H
#define COMP9024_LIST_H

// Linked list interface ... COMP9024 17s2
#include <stdbool.h>

typedef struct Node {
    int         v;
    struct Node *next;
} Node;


typedef struct Node *List;

List insertLL(List, int);
List deleteLL(List, int);
bool inLL(List, int);
void freeLL(List);
void showLL(List);

#endif //COMP9024_LIST_H
