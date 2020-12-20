//
// Created by Rui.Mu on 2019-02-02.
//

#ifndef COMP9024_QUEUE_H
#define COMP9024_QUEUE_H

typedef struct QueueRep *queue;

queue newQueue();               // set up empty queue
void  dropQueue(queue);         // remove unwanted queue
int   QueueIsEmpty(queue);      // check whether queue is empty
void  QueueEnqueue(queue, int); // insert an int at end of queue
int   QueueDequeue(queue);      // remove int from front of queue

#endif //COMP9024_QUEUE_H
