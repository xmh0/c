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
void heapify(HEAP *src, int i, HEAP_TYPE type){
        int l = left(i), r=right(i), largest=i;
        if(l<(src->size)){
                if(type==MAX&&(src->ele[l]->index)>(src->ele[largest]->index)){
                        swap(l, largest);
                }
                if(type==MIN&&(src->ele[l]->index)<(src->ele[largest]->index)){
                        swap(l, largest);
                }
        }
        if(r<(src->size)){
                if(type==MAX&&(src->ele[r]->index)>(src->ele[largest]->index)){
                        swap(r, largest);
                }
                if(type==MIN&&(src->ele[r]->index)<(src->ele[largest]->index)){
                        swap(r, largest);
                }
        }
        if(i!=largest){
                swap(src->ele[i], src->ele[largest]);
                heapify(src, largest, type);
        }
}
void insert_heap(HEAP *heap, HEAP_NODE *heap_node, HEAP_TYPE type){
        int index = heap->size; 
        heap->ele[heap->size++] = heap_node;
        if(type==MAX){
                while(index>0&&(heap->ele[index]->index)>(heap->ele[parent(index)]->index)){
                        swap(heap->ele[index], heap->ele[parent(index)]);
                        index = parent(index);
                }
        }
        if(type==MIN){
                while(index>0&&type==MIN&&(heap->ele[index]->index)<(heap->ele[parent(index)]->index)){
                        swap(heap->ele[index], heap->ele[parent(index)]);
                        index = parent(index);
                }
        }
        
}
HEAP *create_heap(int size){
        HEAP *heap=malloc(sizeof(HEAP));
        heap->ele = malloc(sizeof(HEAP_NODE*)*size);
        if(heap->ele == NULL){
                printf("create_max_heap malloc error \n");
        }
        heap->size = 0;
        return heap;
}
void build_heap(HEAP *heap, HEAP_TYPE type){
        for(int i=(heap->size/2)-1; i>=0; i--){
                heapify(heap, i, type);
        }
}
HEAP_NODE *extrem_heap(HEAP *heap){
        return heap->ele[0];
}
HEAP_NODE *extract_heap(HEAP *heap, HEAP_TYPE type){
        HEAP_NODE *node=NULL;
        if(heap->size<1){
                printf(" extract max heap error, heap size if invalid");
                return node;
        }
        node = heap->ele[0];
        heap->size=heap->size--;
        heap->ele[0]=heap->ele[heap->size];
        heapify(heap, 0, type);
        return node;
}
void sort_heap(HEAP *heap, HEAP_TYPE type){
        //build_max_heap(src);
        for(int i=heap->size-1; i>=0; i--){
                heap->size = heap->size - 1;
                swap(heap->ele[0], heap->ele[i]);
                heapify(heap, 0, type);
        }
}