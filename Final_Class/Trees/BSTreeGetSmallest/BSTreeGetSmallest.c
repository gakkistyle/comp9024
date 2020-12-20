
#include "BSTree.h"

#include <stdlib.h>

BSTree BSTreeGetSmallest(BSTree t) {
    // TODO
    if (t != NULL) {
        return (t->left != NULL) ? BSTreeGetSmallest(t->left) : t;
    }
    return NULL;
}

