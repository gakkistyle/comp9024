//
//  IntQueue.c
//  code
//
//  Created by 郑淇文 on 2020/1/8.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "IntQueue.h"
#include <assert.h>

typedef struct{
    int item[MAXITEMS];
    int top;
    int bottom;
    int number;
}IntQueue;

static IntQueue IntQueueObject;

void QueueInit()
{
    IntQueueObject.top = -1;
    IntQueueObject.bottom = -1;
    IntQueueObject.number = 0;
}

int QueueIsEmpty()
{
    return (IntQueueObject.number == 0);
}

void QueueEnqueue(int n)
{
    assert(IntQueueObject.number<MAXITEMS);
    IntQueueObject.top = (IntQueueObject.top + 1)%MAXITEMS;
    int i = IntQueueObject.top;
    IntQueueObject.item[i] = n;
    IntQueueObject.number ++;
}

int QueueDequeue()
{
    assert(IntQueueObject.number>0);
    IntQueueObject.bottom = (IntQueueObject.bottom+1)%MAXITEMS;
    int i = IntQueueObject.bottom;
    int n = IntQueueObject.item[i];
    IntQueueObject.number --;
    return n;
}
