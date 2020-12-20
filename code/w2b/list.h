//
//  list.h
//  code
//
//  Created by 郑淇文 on 2020/1/16.
//  Copyright © 2020 郑淇文. All rights reserved.
//
#include <stdbool.h>
typedef struct Node *List;

List insertLL(List,int);
List deleteLL(List,int);
bool inLL(List,int);
void freeLL1(List);
void showLL1(List);
