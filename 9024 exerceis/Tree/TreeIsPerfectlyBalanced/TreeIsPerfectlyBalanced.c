
#include <stdlib.h>

#include "tree.h"

int computesize(Tree t){
    if(t==NULL)
        return 0;
    return 1+computesize(t->left)+computesize(t->right);
}

bool TreeIsPerfectlyBalanced(Tree t) {
	// TODO
    if(t==NULL)
        return true;
    int sizel = computesize(t->left);
    int sizer = computesize(t->right);
    int gap;
    if(sizel>sizer)
        gap = sizel-sizer;
    else
        gap = sizer-sizel;
    if(gap<2&&TreeIsPerfectlyBalanced(t->left)&&TreeIsPerfectlyBalanced(t->right))
        return true;
	return false;
}

