//
//  BSTree.c
//  code
//
//  Created by 郑淇文 on 2020/1/29.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define data(tree) ((tree)->data)
#define left(tree) ((tree)->left)
#define right(tree) ((tree)->right)

typedef struct Node{
    int  data;
    Tree left,right;
}Node;

Tree newNode(Item it){
    Tree new = malloc(sizeof(Node));
    assert(new != NULL);
    data(new) = it;
    left(new) = right(new) = NULL;
    return new;
}

Tree newTree(){
    return NULL;
}

void freeTree(Tree t){
    if(t!=NULL){
        freeTree(left(t));
        freeTree(right(t));
        free(t);
    }
}
void showTreeR(Tree t,int depth){
    if(t!=NULL){
        showTreeR(right(t),depth+1);
        int i;
        for (i=0;i<depth;i++)
            putchar('\t');
        printf("%d\n",data(t));
        showTreeR(left(t),depth+1);
    }
}

void showTree(Tree t){
    showTreeR(t,0);
}

int maxHeight(int a,int b){
    if (a>b)
        return a;
    else
        return b;
}
int TreeHeight(Tree t){
    if(t == NULL)
        return -1;
    else
        return 1 + maxHeight(TreeHeight(left(t)),TreeHeight(right(t)));
    
}

int TreeNumNode(Tree t){
    if(t == NULL)
        return 0;
    else
        return 1+TreeNumNode(left(t)) + TreeNumNode(right(t));
}

bool TreeSearch(Tree t,Item it){
    if(t==NULL)
        return false;
    else if (it<data(t))
        return TreeSearch(left(t),it);
    else if (it>data(t))
        return TreeSearch(right(t),it);
    else
        return true;
}

Tree TreeInsert(Tree t,Item it){
    if(t==NULL)
        t = newNode(it);
    else if(it<data(t))
        left(t) = TreeInsert(left(t),it);
    else if(it>data(t))
        right(t) = TreeInsert(right(t),it);
    return t;
}

Tree joinTrees(Tree t1,Tree t2){
    if(t1 == NULL)
        return t2;
    else if(t2==NULL)
        return t1;
    else{
        Tree curr = t2;
        Tree parent = NULL;
        while(left(curr)!=NULL){
            parent = curr;
            curr = left(curr);
        }
        if(parent!=NULL){
            left(parent) = right(curr);
            right(curr) = t2;
        }
        left(curr) = t1;
        return curr;
    }
}

Tree TreeDelete(Tree t,Item it){
    if(t!=NULL){
        if(it<data(t))
            left(t) = TreeDelete(left(t),it);
        if(it>data(t))
            right(t) = TreeDelete(right(t),it);
        else{
            Tree new;
            if (left(t) == NULL && right(t) == NULL)
                new = NULL;
            else if(left(t) == NULL)
                new = right(t);
            else if(right(t) == NULL)
                new = left(t);
            else
                new = joinTrees(left(t),right(t));
            free(t);
            t = new;
        }
    }
    return t;
}
