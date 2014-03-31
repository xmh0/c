/* 
 * File:   heap.h
 * Author: xmh
 *
 * Created on 2014年3月30日, 下午3:11
 */

#ifndef HEAP_H
#define	HEAP_H

void max_heapify(int *src, int i);
int *create_max_heap(int size);
void build_max_heap(int *src, int size);
void sort_max_heap(int *src, int size);

#endif	/* HEAP_H */

