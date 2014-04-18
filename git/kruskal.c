#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#include"graph.h"
#include"queue.h"
#include"list.h"
#include"set.h"
#include"min_heap.h"
#include"common.h"

GRAPH_EDGE **kruskal(HEAP *heap, int vertex_count){
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
        int *parent=malloc(vertics_sizeof), vertics[vertex_count], key[vertex_count];
        memset(parent, -1, vertics_sizeof);
        memset(vertics, 0, vertics_sizeof);
        memset(key, 100, vertics_sizeof);
        
        HEAP *heap=create_min_heap(vertex_count);
        HEAP_NODE *ele=malloc(sizeof(HEAP_NODE));
        int *vertex_no = malloc(sizeof(int));
        *vertex_no = root;
        ele->x=vertex_no;
        ele->weight = 0;
        insert_min_heap(heap, ele);
        while(heap->size){
                HEAP_NODE *node = extract_min_heap(heap);
                int *x = node->x;
                if(vertics[*x]==1){
                        continue;
                }
                vertics[*x]=1;
                EDGE *edge = get_edge_list(graph, *x);
                for(;edge;edge=edge->next){
                        int weight = get_edge_weight(graph, *x, edge->vertex_no);
                        if(vertics[edge->vertex_no]==0 && weight < key[edge->vertex_no]){
                                parent[edge->vertex_no] = *x;
                                ele=malloc(sizeof(HEAP_NODE));
                                vertex_no = malloc(sizeof(int));
                                *vertex_no = edge->vertex_no;
                                ele->x=vertex_no;
                                ele->weight = weight;
                                key[edge->vertex_no] = weight;
                                insert_min_heap(heap, ele);
                        }
                }
        }
        return parent;
}

int *dijkstar(VERTEX *graph, int vertex_count, int root){
        int size_count = sizeof(int)*vertex_count;
        int *parent = malloc(size_count);
        int d[vertex_count];
        memset(parent,-1,size_count);
        memset(d,0,size_count);
        
        HEAP *heap=create_min_heap(vertex_count);
        HEAP_NODE *ele=malloc(sizeof(HEAP_NODE));
        int *vertex_no = malloc(sizeof(int));
        *vertex_no = root;
        ele->x=vertex_no;
        ele->weight = 0;
        insert_min_heap(heap, ele);
        
        while(heap->size){
                HEAP_NODE *node = extract_min_heap(heap);
                int *x = node->x;
                EDGE *edge = get_edge_list(graph, *x);
                for(;edge;edge=edge->next){
                        int weight = get_edge_weight(graph, *x, edge->vertex_no);
                        if(d[edge->vertex_no] > d[*x] + weight){
                                d[edge->vertex_no] = d[*x] + weight;
                                *vertex_no = edge->vertex_no;
                                ele->x=vertex_no;
                                ele->weight = d[edge->vertex_no];
                                insert_min_heap(heap, ele);
                        }
                }
        }
}