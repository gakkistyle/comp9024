//
//  BST.h
//  code
//
//  Created by 郑淇文 on 2020/1/30.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdbool.h>

typedef int Item;

typedef struct Node *Tree;

Tree newTree2();
void freeTree2(Tree);
void showTree2(Tree);

bool TreeSearch2(Tree,Item);
int TreeHeight2(Tree);
int TreeNumNodes2(Tree);
Tree TreeInsert2(Tree,Item);
Tree TreeDelete2(Tree,Item);

Tree rotateRight(Tree);
Tree rotateLeft(Tree);
Tree insertAtRoot(Tree,Item);
Tree insertRandom(Tree,Item);
Tree insertAVL(Tree,Item);
Tree insertSplay(Tree,Item);
Tree partition(Tree,int);
Tree rebalance(Tree);
