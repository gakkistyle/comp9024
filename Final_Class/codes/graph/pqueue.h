//
// Created by Rui.Mu on 2019-02-02.
//

#ifndef COMP9024_PQUEUE_H
#define COMP9024_PQUEUE_H

typedef struct PQueueRep *PQueue;

PQueue newPQueue();               // set up empty queue
void  freePQueue(PQueue);         // remove unwanted queue
int   PQueueIsEmpty(PQueue);      // check whether queue is empty
void  joinPQueue(PQueue, int); // insert an int at end of queue
int   leavePQueue(PQueue);      // remove int from front of queue

#endif //COMP9024_PQUEUE_H
