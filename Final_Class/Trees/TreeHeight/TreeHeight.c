
#include <stdlib.h>

#include "tree.h"

int TreeHeight(Tree t) {
    if (t != NULL) {
        int right = TreeHeight(t->right);
        int left = TreeHeight(t->left);
        return right > left ? right + 1 : left + 1;
    }
    return -1;
}

