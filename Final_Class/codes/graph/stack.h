//
// Created by Rui.Mu on 2019-02-02.
//

#ifndef COMP9024_STACK_H
#define COMP9024_STACK_H

typedef struct StackRep *stack;

stack newStack();             // set up empty stack
void  dropStack(stack);       // remove unwanted stack
int   StackIsEmpty(stack);    // check whether stack is empty
void  StackPush(stack, int);  // insert an int on top of stack
int   StackPop(stack);        // remove int from top of stack

#endif //COMP9024_STACK_H
