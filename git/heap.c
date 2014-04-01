#include"stdio.h"
#include"stdlib.h"
#include"heap.h"

#define swap(x,y) {__typeof__(x) _x=x; __typeof__(y) _y=y; x=_y; y=_x;}

int left(int i){
        return (i<<1)+1;
}
int right(int i){
        return (i<<1)+2;
}
int parent(int i){
        return (i>>1)?(i>>1)-1:0;
}
void max_heapify(HEAP *src, int i){
        int l = left(i), r=right(i), largest=i;
        if(l<(src->size)&&(src->ele[l]->index)>(src->ele[largest]->index)){
                swap(l, largest);
        }
        if(r<(src->size)&&(src->ele[r]->index)>(src->ele[largest]->index)){
                swap(r, largest);
        }
        if(i!=largest){
                swap(src->ele[i], src->ele[largest]);
                max_heapify(src, largest);
        }
}
void insert_max_heap(HEAP *heap, HEAP_NODE *heap_node){
        int index = heap->size; 
        heap->ele[heap->size++] = heap_node;
        while(index>0 && (heap->ele[index]->index)>(heap->ele[parent(index)]->index)){
                swap(heap->ele[index], heap->ele[parent(index)]);
                index = parent(index);
        }
}
HEAP *create_max_heap(int size){
        HEAP *src=malloc(sizeof(HEAP));
        src->ele = malloc(sizeof(HEAP_NODE*)*size);
        if(src->ele == NULL){
                printf("create_max_heap malloc error \n");
        }
        src->size = 0;
        return src;
}
void build_max_heap(HEAP *src){
        for(int i=(src->size/2)-1; i>0; i--){
                max_heapify(src, i);
        }
}
HEAP_NODE *maximum(HEAP *heap){
        return heap->ele[0];
}
HEAP_NODE *extract_max_heap(HEAP *heap){
        HEAP_NODE *node=NULL;
        if(heap->size<1){
                printf(" extract max heap error, heap size if invalid");
                return node;
        }
        node = heap->ele[0];
        heap->size=heap->size--;
        heap->ele[0]=heap->ele[heap->size];
        max_heapify(heap, 0);
        return node;
}
void sort_max_heap(HEAP *src){
        build_max_heap(src);
        for(int i=src->size; i>0; i--){
                src->size = src->size - 1;
                swap(src->ele[0], src->ele[i]);
                max_heapify(src, 0);
        }
}