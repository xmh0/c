/*
 * queue.c
 *
 *  Created on: Mar 9, 2014
 *      Author: xmh
 */
#include<stdio.h>
#include"queue.h"

typedef struct queue_ele ELE;

QUEUE *queue_create(){
        QUEUE *queue = malloc(sizeof(QUEUE));
        queue->tail=NULL;
        queue->front=NULL;
        return queue;
}
int enqueue(QUEUE *queue, void *x){
        ELE *ele = malloc(sizeof(ELE));
        if(ele == NULL){
                return 1;
        }
        ele->x=x;
        ele->link=NULL;
        if(queue->front == NULL){
                queue->front=ele;
        }
        if(queue->tail!=NULL){
                queue->tail->link=ele;
        }
        queue->tail=ele;
        return 0;
}
void *dequeue(QUEUE *queue){
        ELE *ele = queue->front;
        void *ret = queue->front->x;
        queue->front = queue->front->link;
        free(ele);
        return ret;
}

int queue_free(QUEUE *queue){
        ELE *ele;
        for(ele=queue->front; ele; ele=ele->link){
                free(ele->x);
                free(ele);
        }
        free(queue);
}


