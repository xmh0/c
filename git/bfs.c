#include<stdio.h>
#include<stdlib.h>
#include"common.h"
#include"queue.h"
#include"list.h"

EDGE *bfs(VERTEX *matrix, int vertex_no, int vertex_count){
        enum colorset{WHITE, GRAY, BLACK} *color;
        color=malloc(sizeof(enum colorset)*vertex_count);
        int *d=malloc(sizeof(int)*vertex_count);
        EDGE **parent = malloc(sizeof(EDGE *)*vertex_count);
        for(int i=0;i<vertex_count;i++){
                color[i]=WHITE;
                d[i]=0;
                parent[i]=NULL;
        }
        QUEUE *queue=queue_create();
        enqueue(queue, create_edge(vertex_no, 0));
        
        EDGE *pedge, *edge; 
        while((pedge=dequeue(queue))){
                edge = get_edge_list(matrix, pedge->vertex_no);
                for(;edge;edge=edge->next){
                        if(color[edge->vertex_no]==WHITE){
                                color[edge->vertex_no]=GRAY;
                                d[edge->vertex_no]=d[pedge->vertex_no]+1;
                                enqueue(queue, edge);
                                parent[edge->vertex_no]=pedge;
                        }
                }
                color[pedge->vertex_no]=BLACK;
        }
        return parent;
}

void print_path(EDGE **parent, int s){
        printf("%d ", s);                
        while(parent[s]){
                printf("%d ", parent[s]->vertex_no);
                s=parent[s]->vertex_no; 
        }
}

void print_path_rec(EDGE **parent, int s){
        if(parent[s]){
                print_path_rec(parent, parent[s]->vertex_no);
                printf("%d ", s);
        }
}

