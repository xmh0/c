
#include"heap.h"

HEAP *create_min_heap(int size){
        return create_heap(size);
}
void insert_min_heap(HEAP *heap, HEAP_NODE *heap_node){
        insert_heap(heap, heap_node, MIN);
}
void sort_min_heap(HEAP *heap){
        sort_heap(heap, MIN);
}
HEAP_NODE *minimum(HEAP *heap){
        return extrem_heap(heap);
}
HEAP_NODE *extract_min_heap(HEAP *heap){
        return extract_heap(heap, MIN);
}
int update_min_heap(HEAP *heap, HEAP_NODE *heap_node){
        return update_heap(heap, heap_node, MIN);
}

