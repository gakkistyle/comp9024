//
//  RBTree.c
//  code
//
//  Created by 郑淇文 on 2020/1/31.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "RBTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define PRINT_COLOR_RED "\x1B[31m"
#define PRINT_COLOR_RESET "\x1B[0m"

#define data(tree) ((tree)->data)
#define left(tree) ((tree)->left)
#define right(tree) ((tree)->right)
#define color(tree) ((tree)->color)
#define isRed(tree) ((tree)!=NULL && (tree)->color == RED)

typedef enum {RED,BLACK} Colr;

typedef struct Node{
    int  data;
    Colr color;
    Tree left,right;
}Node;

Tree newTree3(){
    return NULL;
}

Tree newNode3(Item it){
    Tree new = malloc(sizeof(Node));
    assert(new!=NULL);
    data(new) = it;
    color(new) = RED;
    left(new) = right(new) = NULL;
    return new;
}

Tree rotateRight2(Tree);
Tree rotateLeft2(Tree);

Tree TreeInsert3(Tree t,Item it){
    printf("Not yet implemented.\n");
    printf("Returning a fixed tree instead:\n");
    
    Tree testTree = newNode3(2);
    color(testTree) = BLACK;
    left(testTree) = newNode3(1);
    right(testTree) = newNode3(3);
    return testTree;
}


bool TreeSearch3(Tree t,Item it){
    if(t==NULL)
        return false;
    else if(it<data(t))
        return TreeSearch3(left(t),it);
    else if(it>data(t))
        return TreeSearch3(right(t),it);
    else
        return true;
}

Tree rotateRight2(Tree n1){
    if(n1==NULL||left(n1) == NULL)
        return n1;
    Tree n2 = left(n1);
    left(n1) = right(n2);
    right(n2) = n1;
    return n2;
}

Tree rotateleft2(Tree n2){
    if(n2==NULL||right(n2) == NULL)
        return n2;
    Tree n1 = right(n2);
    right(n2) = left(n1);
    left(n1) = n2;
    return n1;
}

void freeTree3(Tree t){
    if(t!=NULL){
        freeTree3(left(t));
        freeTree3(right(t));
        free(t);
    }
}

void showTreeR3(Tree t,int depth){
    if(t!=NULL){
        showTreeR3(right(t),depth+1);
        int i;
        for(i=0;i<depth;i++)
            putchar('\t');
        if(isRed(t))
            printf("%s%d%s\n",PRINT_COLOR_RED,data(t),PRINT_COLOR_RESET);
        else
            printf("%d\n",data(t));
        showTreeR3(left(t),depth+1);
    }
}

void showTree3(Tree t){
    showTreeR3(t,0);
}
