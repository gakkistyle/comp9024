//
//  queue.h
//  code
//
//  Created by 郑淇文 on 2020/1/16.
//  Copyright © 2020 郑淇文. All rights reserved.
//

typedef struct QueueRep *queue;

queue newQueue();
void dropQueue(queue);
int queueIsEmpty(queue);
void queueEnqueue(queue,int);
int queueDequeue(queue);
