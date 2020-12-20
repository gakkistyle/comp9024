//
//  IntStack.c
//  code
//
//  Created by 郑淇文 on 2020/1/8.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "IntStack.h"
#include<assert.h>

typedef struct{
    int item[MAXITEMS];
    int top;
}IntStack;

static IntStack IntStackObject;

void StackInit2()
{
    IntStackObject.top = -1;
}

int StackIsEmpty2()
{
    return (IntStackObject.top < 0);
}

void StackPush2(int n)
{
    assert(IntStackObject.top<MAXITEMS-1);
    IntStackObject.top ++ ;
    int i = IntStackObject.top;
    IntStackObject.item[i] = n;
}

int StackPop2()
{
    assert(IntStackObject.top>-1);
    int i = IntStackObject.top;
    int n = IntStackObject.item[i];
    IntStackObject.top -- ;
    return n;
}
