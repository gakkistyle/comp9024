
#include <stdlib.h>

#include "BSTree.h"
int getsize(BSTree t){
    if(t==NULL)
        return 0;
    return 1+getsize(t->left)+getsize(t->right);
}

int i =0;

void get_values(BSTree t,int valueset[]){
    if(t==NULL)
        return ;
    valueset[i] = t->value;
    i++;
    get_values(t->left,valueset);
    get_values(t->right,valueset);
    
}

void insertionSort(int *array, int arraySize) {
    for (int i = 1; i < arraySize; i++) {
        int temp = array[i];
        while (i > 0 && array[i - 1] > temp) {
            array[i] = array[i - 1];
            i--;
        }
        array[i] =
        temp;
    }
}

int BSTreeGetKth(BSTree t, int k) {
	// TODO
    int size = getsize(t);
    int valueset[size];
    i=0;
    get_values(t,valueset);
    insertionSort(valueset,size);
	return valueset[k];
}

