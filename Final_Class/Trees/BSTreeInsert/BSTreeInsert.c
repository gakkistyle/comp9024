
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

BSTree BSTreeInsert(BSTree t, int val) {
    // TODO
    if (t == NULL) {
        t = malloc(sizeof(*t));
        if (t == NULL) {
            fprintf(stderr, "Insufficient memory!\n");
            exit(EXIT_FAILURE);
        }
        t->value = val;
        t->left = NULL;
        t->right = NULL;

    }else {
        if (val < t->value) {
            t->left = BSTreeInsert(t->left, val);
        } else {
            t->right = BSTreeInsert(t->right, val);
        }
    }
    return t;
}

