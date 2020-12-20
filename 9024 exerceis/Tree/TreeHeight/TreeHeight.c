
#include <stdlib.h>

#include "tree.h"

int TreeHeight(Tree t) {
    if (t==NULL)
        return -1;
    int hl = TreeHeight(t->left);
    int hr = TreeHeight(t->right);
    if(hl>hr)
        return 1+hl;
    else
        return 1+hr;
}

