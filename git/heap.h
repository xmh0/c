/* 
 * File:   heap.h
 * Author: xmh
 *
 * Created on 2014年3月30日, 下午3:11
 */

#ifndef HEAP_H
#define	HEAP_H

typedef struct heap HEAP;
typedef struct heap_node HEAP_NODE;

struct heap{
    HEAP_NODE **ele;
    int size;
};
struct heap_node{
        void *x;
        int index;
};

HEAP *create_max_heap(int size);
void insert_max_heap(HEAP *heap, HEAP_NODE *heap_node);
void sort_max_heap(HEAP *heap);
HEAP_NODE *maximum(HEAP *heap);
HEAP_NODE *extract_max_heap(HEAP *heap);

#endif	/* HEAP_H */

