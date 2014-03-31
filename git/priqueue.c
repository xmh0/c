#include"stdio.h"
#include"stdlib.h"
#include"heap.h"

/*
typedef struct priqueue PRIQUEUE;
typedef struct priqueue_node PRIQUEUE_NODE;
struct priqueue_node{
        void *x;
        int index;
};
struct priqueue{
        PRIQUEUE_NODE *node;
};
void *create_priqueue(int size){
        PRIQUEUE *queue = malloc(sizeof(PRIQUEUE_NODE)*size);
        if(queue==NULL){
                printf("create_priqueue malloc error");
        }
        return queue;
}
void insert(PRIQUEUE *queue, PRIQUEUE_NODE *x){
        max_heapify(queue, x);
}
void *maximum(PRIQUEUE *queue){
        void *ret = queue
}
*/