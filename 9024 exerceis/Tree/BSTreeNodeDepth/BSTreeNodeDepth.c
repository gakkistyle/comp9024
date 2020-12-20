
#include <stdlib.h>

#include "BSTree.h"
int mode = 0;

int BSTreeNodeDepth(BSTree t, int key) {
    if(mode==0){
        BSTree tc = t;
        while(tc!=NULL&&tc->value!=key){
            if(key>tc->value)
                tc=tc->right;
            else if(key<tc->value)
                tc = tc->left;
        }
        if(tc==NULL)
            return -1;
        else
            mode = 1;
    }
    if(key>t->value){
        return 1+BSTreeNodeDepth(t->right,key);
    }else if(key<t->value){
        return 1+BSTreeNodeDepth(t->left,key);
    }else{
        mode = 0;
        return 0;
    }
}

