/* 
 * File:   heap.h
 * Author: xmh
 *
 * Created on 2014年3月30日, 下午3:11
 */

#ifndef HEAP_H
#define	HEAP_H

typedef enum heap_type HEAP_TYPE;
typedef struct heap HEAP;
typedef struct heap_node HEAP_NODE;

enum heap_type {MAX, MIN};

struct heap{
    HEAP_NODE **ele;
    int size;
};
struct heap_node{
        void *x;
        int id;
        int weight;
};

HEAP *create_heap(int size);
void insert_heap(HEAP *heap, HEAP_NODE *heap_node, HEAP_TYPE type);
void sort_heap(HEAP *heap, HEAP_TYPE type);
HEAP_NODE *extrem_heap(HEAP *heap);
HEAP_NODE *extract_heap(HEAP *heap, HEAP_TYPE type);
HEAP_NODE *create_node_heap(void *x, int weight, ...);
int update_heap(HEAP *heap, HEAP_NODE *heap_node, HEAP_TYPE type);

#endif	/* HEAP_H */