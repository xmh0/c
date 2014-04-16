#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#include"graph.h"
#include"queue.h"
#include"list.h"
#include"set.h"
#include"min_heap.h"
#include"common.h"

GRAPH_EDGE *kruskal(HEAP *heap, int vertex_count){
        int index=0;
        GRAPH_EDGE **arr = malloc(sizeof(GRAPH_EDGE *)*vertex_count);
        SET *set = create_set(vertex_count);
        for(int i=0;i<vertex_count;i++){
                make_set(set, i);
        }
        while(heap->size){
                HEAP_NODE *node = extract_min_heap(heap);
                GRAPH_EDGE *edge = node->x;
                if(find_set(set, edge->u)!=find_set(set, edge->v)){
                        arr[index++] = edge;
                        union_set(set, edge->u, edge->v);
                }
        }
        return arr; 
}

int *prim(VERTEX *graph, int vertex_count, int root){
        int vertics_sizeof = vertex_count * sizeof(int);
        int queue_num = vertex_count, *parent=malloc(vertics_sizeof), vertics[vertex_count], key[vertex_count];
        memset(parent, -1, vertics_sizeof);
        memset(vertics, 0, vertics_sizeof);
        memset(key, 100, vertics_sizeof);
        
        HEAP *heap=create_min_heap(vertex_count);
        HEAP_NODE *ele=malloc(sizeof(HEAP_NODE));
        int *vertex_no = malloc(sizeof(int));
        *vertex_no = root;
        ele->x=vertex_no;
        ele->index = 0;
        vertics[0]=1;
        insert_min_heap(heap, ele);
        while(queue_num){
                HEAP_NODE *node = extract_min_heap(heap);
                queue_num--;
                int *index = node->x;
                vertics[*index]=1;
                EDGE *edge = get_edge_list(graph, *index);
                for(;edge;edge=edge->next){
                        int weight = get_edge_weight(graph, *index, edge->vertex_no);
                        if(vertics[edge->vertex_no]==0 && weight < key[edge->vertex_no]){
                                parent[edge->vertex_no] = *index;
                                ele=malloc(sizeof(HEAP_NODE));
                                vertex_no = malloc(sizeof(int));
                                *vertex_no = edge->vertex_no;
                                ele->x=vertex_no;
                                ele->index = weight;
                                key[edge->vertex_no] = weight;
                                insert_min_heap(heap, ele);
                        }
                }
        }
        return parent;
}