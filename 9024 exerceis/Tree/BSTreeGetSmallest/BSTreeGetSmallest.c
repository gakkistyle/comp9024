
#include "BSTree.h"

#include <stdlib.h>

BSTree MINT(BSTree t1,BSTree t2){
    if (t1->value>t2->value)
        return t2;
    else
        return t1;
}

BSTree BSTreeGetSmallest(BSTree t) {
	// TODO
    if (t==NULL)
        return NULL;
    if(t->left!=NULL && t->right!=NULL){
        BSTree tem = MINT(BSTreeGetSmallest(t->left),BSTreeGetSmallest(t->right));
        return MINT(t,tem);
    }else if(t->left!=NULL && t->right==NULL){
        return MINT(t,BSTreeGetSmallest(t->left));
    }else if(t->left==NULL && t->right!=NULL){
        return MINT(t,BSTreeGetSmallest(t->right));
    }else{
        return t;
    }
}

