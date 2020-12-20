//
//  BSTree.h
//  code
//
//  Created by 郑淇文 on 2020/1/29.
//  Copyright © 2020 郑淇文. All rights reserved.
//


#include <stdbool.h>

typedef int Item;

typedef struct Node *Tree;

Tree newTree();
void freeTree(Tree);
void showTree(Tree);

bool TreeSearch(Tree,Item);
int TreeHeight(Tree);
int TreeNumNode(Tree);
Tree TreeInsert(Tree,Item);
Tree TreeDelete(Tree,Item);
