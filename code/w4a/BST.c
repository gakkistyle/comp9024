//
//  BST.c
//  code
//
//  Created by 郑淇文 on 2020/1/30.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define RANDOM_ROOT_INSERT (rand() % 10<4)

#define data(tree)  ((tree)->data)
#define left(tree)  ((tree)->left)
#define right(tree) ((tree)->right)

typedef struct Node{
    int  data;
    Tree left,right;
}Node;

Tree newNode2(Item it){
    Tree new = malloc(sizeof(Node));
    assert(new!=NULL);
    data(new) = it;
    left(new) = right(new) = NULL;
    return new;
}

Tree newTree2(){
    return NULL;
}

void freeTree2(Tree t){
    if(t != NULL){
        freeTree2(left(t));
        freeTree2(right(t));
        free(t);
    }
}
int TreeHeight2(Tree t){
    if(t==NULL){
        return -1;
    }
    else{
        int lheight = 1 + TreeHeight2(left(t));
        int rheight = 1 + TreeHeight2(right(t));
        if(lheight>rheight)
            return lheight;
        else
            return rheight;
    }
}

int TreeNumNodes2(Tree t){
    if (t == NULL)
        return 0;
    else
        return 1 + TreeNumNodes2(left(t)) + TreeNumNodes2(right(t));
}

bool TreeSearch2(Tree t,Item it){
    if (t==NULL)
        return false;
    else if (it<data(t))
        return TreeSearch2(left(t),it);
    else if (it>data(t))
        return TreeSearch2(right(t),it);
    else
        return true;
}

Tree TreeInsert2(Tree t,Item it){
    if(t==NULL)
        t = newNode2(it);
    else if(it<data(t))
        left(t) = TreeInsert2(left(t),it);
    else if(it>data(t))
        right(t) = TreeInsert2(right(t),it);
    return t;
}

 
Tree joinTrees2(Tree t1,Tree t2){
    if(t1 == NULL)
        return t2;
    else if (t2 == NULL)
        return t1;
    else{
        Tree curr = t2;
        Tree parent = NULL;
        while(left(curr)!=NULL){
            parent = curr;
            curr = left(curr);
        }
        if(parent != NULL){
            left(parent) = right(curr);
            right(curr) = t2;
        }
        left(curr) = t1;
        return curr;
    }
}

Tree TreeDelete2(Tree t,Item it){
    if(t!=NULL){
        if(it<data(t))
            left(t) = TreeDelete2(left(t),it);
        else if(it>data(t))
            right(t) = TreeDelete2(right(t),it);
        else{
            Tree new;
            if (left(t)==NULL && right(t)==NULL)
                new = NULL;
            else if(left(t)==NULL)
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

Tree rotateRight(Tree n1){
    if (n1==NULL||left(n1)==NULL)
        return n1;
    Tree n2 = left(n1);
    left(n1) = right(n2);
    right(n2) = n1;
    return n2;
}

Tree rotateLeft(Tree n2){
    if(n2 == NULL||right(n2) == NULL)
        return n2;
    Tree n1 = right(n2);
    right(n2) = left(n1);
    left(n1) = n2;
    return n1;
}

Tree insertAtRoot(Tree t,Item it){
    return t;
}

Tree insertRandom(Tree t,Item it){
    if (t==NULL)
        t = newNode2(it);
    if (RANDOM_ROOT_INSERT)
        return insertAtRoot(t, it);
    else
        return TreeInsert2(t,it);
}

Tree insertAVL(Tree t,Item it){
    if (t==NULL)
        return newNode2(it);
    if (it == data(t))
        return t;
    
    if(it<data(t))
        left(t) = insertAVL(left(t),it);
    else
        right(t) = insertAVL(right(t),it);
    
    int hL = TreeHeight2(left(t));
    int hR = TreeHeight2(right(t));
    if ((hL-hR)>1){
        if(it>data(left(t)))
            left(t) = rotateLeft(left(t));
        t = rotateRight(t);
    }else if ((hR-hL)>1){
        if (it<data(right(t)))
            right(t) = rotateRight(right(t));
        t = rotateLeft(t);
    }
    return t;
}

Tree insertSplay(Tree t,Item it){
    if (t==NULL)
        return newNode2(it);
    if (it == data(t))
        return t;
    
    if(it<data(t)){
        if (left(t)==NULL)
            left(t) = newNode2(it);
        else if(it<data(left(t))){
            left(left(t)) = insertSplay(left(left(t)),it);
            t = rotateRight(t);
        }
        else if(it > data(left(t))){
            right(left(t)) = insertSplay(right(left(t)),it);
            left(t) = rotateLeft(left(t));
        }
        return rotateRight(t);
    }
    else{
        if (right(t)==NULL)
            right(t) = newNode2(it);
        else if(it<data(right(t))){
            left(right(t)) = insertSplay(left(right(t)),it);
            right(t) = rotateRight(right(t));
        }
        else if(it>data(right(t))){
            right(right(t)) = insertSplay(right(right(t)),it);
            t = rotateLeft(t);
        }
        return rotateLeft(t);
    }
}

Tree partition(Tree t,int i){
    if(t!=NULL){
        assert(0<=i&&i<TreeNumNodes2(t));
        int m = TreeNumNodes2(left(t));
        if (i<m){
            left(t) = partition(left(t),i);
            t = rotateRight(t);
        }else if (i>m){
            right(t) = partition(right(t),i-m-1);
            t = rotateLeft(t);
        }
    }
    return t;
}

Tree rebalance(Tree t){
    int n = TreeNumNodes2(t);
    if(n>=3){
        t = partition(t,n/2);
        left(t) = rebalance(left(t));
        right(t) = rebalance(right(t));
    }
    return t;
}

void showTreeR2(Tree t,int depth){
    if (t!=NULL){
        showTreeR2(right(t),depth+1);
        int i;
        for(i=0;i<depth;i++)
            putchar('\t');
        printf("%d\n",data(t));
        showTreeR2(left(t),depth+1);
    }
}

void showTree2(Tree t){
    showTreeR(t,0);
}
