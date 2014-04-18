#include<stdarg.h>

#include"stdio.h"
#include"stdlib.h"
#include"heap.h"

#define swap(x,y) {__typeof__(x) _x=x; __typeof__(y) _y=y; x=_y; y=_x;}

static int left(int i){
        return (i<<1)+1;
}
static int right(int i){
        return (i<<1)+2;
}
static int parent(int i){
        return (i%2)?(i/2):((i/2)-1);
}

static void heapify(HEAP *heap, int i, HEAP_TYPE type){
        int l = left(i), r=right(i), largest=i;
        if(l<(heap->size)){
                if(type==MAX&&(heap->ele[l]->weight)>(heap->ele[largest]->weight)){
                        swap(l, largest);
                }
                if(type==MIN&&(heap->ele[l]->weight)<(heap->ele[largest]->weight)){
                        swap(l, largest);
                }
        }
        if(r<(heap->size)){
                if(type==MAX&&(heap->ele[r]->weight)>(heap->ele[largest]->weight)){
                        swap(r, largest);
                }
                if(type==MIN&&(heap->ele[r]->weight)<(heap->ele[largest]->weight)){
                        swap(r, largest);
                }
        }
        if(i!=largest){
                swap(heap->ele[i], heap->ele[largest]);
                heapify(heap, largest, type);
        }
}
static void increase_heap(HEAP *heap, int index,  HEAP_TYPE type){
        if(type==MAX){
                while(index>0&&(heap->ele[index]->weight)>(heap->ele[parent(index)]->weight)){
                        swap(heap->ele[index], heap->ele[parent(index)]);
                        index = parent(index);
                }
        }
        if(type==MIN){
                while(index>0&&(heap->ele[index]->weight)<(heap->ele[parent(index)]->weight)){
                        swap(heap->ele[index], heap->ele[parent(index)]);
                        index = parent(index);
                }
        }
}
void insert_heap(HEAP *heap, HEAP_NODE *heap_node, HEAP_TYPE type){
        int index = heap->size;
        heap->ele[heap->size++] = heap_node;
        increase_heap(heap, index, type);
}
int update_heap(HEAP *heap, HEAP_NODE *heap_node, HEAP_TYPE type){
        int i = heap->size;
        while(i--){
                if(heap->ele[i]->id == heap_node->id){
                        int weight = heap->ele[i]->weight; 
                        heap->ele[i] = heap_node;
                        if(type == MIN){
                                if(weight > heap_node->weight){
                                        increase_heap(heap, i, MIN);
                                }else{
                                        heapify(heap, i, MIN);
                                }
                        }
                        if(type == MAX){
                                if(weight < heap_node->weight){
                                        increase_heap(heap, i, MAX);
                                }else{
                                        heapify(heap, i, MAX);
                                }
                        }
                        return 0;
                }
        }
        return 1;
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
HEAP_NODE *create_node_heap(void *x, int weight, ...){
        va_list ap;
        va_start(ap, 1);
        int id = va_arg(ap, int);
        va_end(ap);
        
        HEAP_NODE *node = malloc(sizeof(HEAP_NODE));
        node->x=x;
        node->id=id;
        node->weight=weight;
        return node;
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