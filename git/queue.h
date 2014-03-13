/*
 * queue.h
 *
 *  Created on: Mar 8, 2014
 *      Author: xmh
 */

#ifndef QUEUE_H_
#define QUEUE_H_

struct queue{
        struct queue_ele{
                void *x;
                struct queue_ele *link;
        };
        struct queue_ele *front, *tail;
};

typedef struct queue QUEUE;

extern QUEUE *queue_create();
extern int enqueue(QUEUE *queue, void *ele);
extern void *dequeue(QUEUE *queue);
extern int queue_free();

#endif /* QUEUE_H_ */

