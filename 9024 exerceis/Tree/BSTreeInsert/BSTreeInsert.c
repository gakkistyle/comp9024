
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

BSTree insert(BSTree t,BSTree node){
    if(t == NULL)
        t = node;
    else if(node->value>t->value)
        t->right = insert(t->right,node);
    else if(node->value<t->value)
        t->left = insert(t->left,node);
    return t;
        
}

BSTree BSTreeInsert(BSTree t, int val) {
	// TODO
    BSTree new = malloc(sizeof(*new));
    new ->value = val;
    new ->left = NULL;
    new ->right = NULL;
    t = insert(t,new);
	return t;
}

