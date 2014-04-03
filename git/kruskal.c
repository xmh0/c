#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"queue.h"
#include"list.h"
#include"set.h"
#include"min_heap.h"

typedef struct graph_edge GRAPH_EDGE;

GRAPH_EDGE *kruskal(HEAP *heap, int vertex_count){
        int index=0;
        GRAPH_EDGE arr[vertex_count];
        SET *set = create_set(vertex_count);
        for(int i=0;i<vertex_count;i++){
                make_set(set, i);
        }
        while(heap->size){
                HEAP_NODE *node = extract_min_heap(heap);
                GRAPH_EDGE *edge = node->x;
                if(find_set(set, edge->u)!=find_set(set, edge->v)){
                        arr[index++] = *edge;
                        union_set(set, edge->u, edge->v);
                }
        }
        return arr; 
}

