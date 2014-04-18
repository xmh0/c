/* 
 * File:   min_heap.h
 * Author: xmh
 *
 * Created on 2014年4月2日, 下午6:17
 */
#include"heap.h"

#ifndef MIN_HEAP_H
#define	MIN_HEAP_H

HEAP *create_min_heap(int size);
void insert_min_heap(HEAP *heap, HEAP_NODE *heap_node);
void sort_min_heap(HEAP *heap);
HEAP_NODE *minimum(HEAP *heap);
HEAP_NODE *extract_min_heap(HEAP *heap);
int update_min_heap(HEAP *heap, HEAP_NODE *heap_node);

#endif	/* MIN_HEAP_H */

