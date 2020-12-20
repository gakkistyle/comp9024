#include "Stack.h"
#include <assert.h>
#include<stdio.h>
typedef struct{
    char item[MAXITEMS];
    int top;
}stackRep;

static stackRep stackObject;

void StackInit_(){
    stackObject.top = -1;
}

int StackIsEmpty_(){
    return (stackObject.top<0);
}

void StackPush_(char ch){
    assert(stackObject.top<MAXITEMS-1);
    stackObject.top++;
    int i = stackObject.top;
    stackObject.item[i] = ch;
}

char StackPop_(){
    assert(stackObject.top > -1);
    int i = stackObject.top;
    char ch = stackObject.item[i];
    stackObject.top--;
    return ch;

}


