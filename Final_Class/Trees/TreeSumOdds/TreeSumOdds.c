
#include <stdlib.h>

#include "tree.h"

//     100
//    50     45
int TreeSumOdds(Tree t) {

    if(t == NULL) {
        return  0;
    }else {
        int left = TreeSumOdds(t->left);
        int right = TreeSumOdds(t->right);
        if ((t->value % 2) == 1) {
            return t->value + left + right;
        } else {
            return left + right;
        }
    }
}

