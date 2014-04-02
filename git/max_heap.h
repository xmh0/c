/* 
 * File:   max_heap.h
 * Author: xmh
 *
 * Created on 2014年4月2日, 上午8:26
 */
#include"heap.h"

#ifndef MAX_HEAP_H
#define	MAX_HEAP_H

HEAP *create_max_heap(int size);
void insert_max_heap(HEAP *heap, HEAP_NODE *heap_node);
void sort_max_heap(HEAP *heap);
HEAP_NODE *maximum(HEAP *heap);
HEAP_NODE *extract_max_heap(HEAP *heap);

#endif	/* MAX_HEAP_H */

