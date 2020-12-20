//
//  RBTree.h
//  code
//
//  Created by 郑淇文 on 2020/1/31.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include<stdbool.h>

typedef int Item;

typedef struct Node *Tree;

Tree newTree3();
void freeTree3(Tree);
void showTree3(Tree);

bool TreeSearch3(Tree,Item);
Tree TreeInsert3(Tree,Item);
