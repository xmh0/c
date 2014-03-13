#include<stdio.h>
#include<stdlib.h>
#include"common.h"
#include"queue.h"
#include"list.h"

EDGE *bfs(EDGE *matrix, int vertex_no, int vertex_count){
        enum colorset{WHITE, GRAY, BLACK} *color;
        color=malloc(sizeof(enum colorset)*vertex_count);
        int *d=malloc(sizeof(int)*vertex_count);
        EDGE **parent = malloc(sizeof(EDGE *)*vertex_count);
        for(int i=0;i<vertex_count;i++){
                color[i]=WHITE;
                d[i]=0;
        }
        
        queue *matrix=queue_create();
        enqueue(matrix, get_edge_list(vertex_no));
        
        EDGE *pedge;
        while((pedge=dequeue(matrix))){
                edge = get_edge_list(pedge->vertex_no);
                for(;edge;edge=edge->next){
                        if(color[edge->vertex_no]==WHITE){
                                color[edge->vertex_no]=GRAY;
                                d[edge->vertex_no]=d[pedge->vertex_no]+1;
                                enqueue(matrix, edge->vertex_no);
                                parent[edge->vertex_no]=pedge;
                        }
                }
                color[pedge->vertex_no]=BLACK;
        }
        return parent;
}

void print_path(EDGE **parent, int s){
        while(parent[s]){
                printf("%d", parent[s]->vertex_no);
                s=parent[s]->vertex_no; 
        }
}

void print_path_rec(EDGE **parent, int s){
        if(parent[s]){
                print_path_rec(parent, parent[s]->vertex_no);
                printf("%d", parent[s]->vertex_no);
        }
}

