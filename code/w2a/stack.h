//
//  stack.h
//  code
//
//  Created by 郑淇文 on 2020/1/11.
//  Copyright © 2020 郑淇文. All rights reserved.
//

typedef struct StackRep *stack;

stack newStack();
void dropStack(stack);
int StackIsEmpty(stack);
void StackPush(stack,int);
int StackPop(stack);
