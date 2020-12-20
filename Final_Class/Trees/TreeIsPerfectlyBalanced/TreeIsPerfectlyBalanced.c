
#include <stdlib.h>

#include "tree.h"
#include <math.h>

int TreeNodes(Tree t) {
    if (t != NULL) {
        int right = TreeNodes(t->right);
        int left = TreeNodes(t->left);
        return 1 + left + right;
    }
    return 0;
}

bool TreeIsPerfectlyBalanced(Tree t) {
	// TODO
	if (t == NULL) {
	    return true;
	}

	return TreeIsPerfectlyBalanced(t->left)
	&& TreeIsPerfectlyBalanced(t->right)
	&& (abs(TreeNodes(t->left) - TreeNodes(t->right)) <=1);
}

