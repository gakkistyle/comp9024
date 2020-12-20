
#include <stdlib.h>

#include "BSTree.h"

int BSTreeNodeDepthCheck(BSTree t, int key, int depth) {
    if (t == NULL) {
        return -1;
    }
    if (t->value == key) {
        return depth + 1;
    }

    int left = BSTreeNodeDepthCheck(t->left, key, depth + 1);
    int right = BSTreeNodeDepthCheck(t->right, key, depth + 1);

    return (left > -1) ? left : right;
}

int BSTreeNodeDepth(BSTree t, int key) {
    return BSTreeNodeDepthCheck(t, key, -1);
}

