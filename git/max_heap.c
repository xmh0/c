#include"heap.h"

HEAP *create_max_heap(int size){
        return create_heap(size);
}
void insert_max_heap(HEAP *heap, HEAP_NODE *heap_node){
        insert_heap(heap, heap_node, MAX);
}
void sort_max_heap(HEAP *heap){
        sort_heap(heap, MAX);
}
HEAP_NODE *maximum(HEAP *heap){
        return extrem_heap(heap);
}
HEAP_NODE *extract_max_heap(HEAP *heap){
        return extract_heap(heap, MAX);
}
int update_max_heap(HEAP *heap, HEAP_NODE *heap_node){
        return update_heap(heap, heap_node, MAX);
}
