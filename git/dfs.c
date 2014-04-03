#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
#include "list.h"

int time=0;
int *d,*f;
enum colorset{WHITE, GRAY, BLACK} *color;
EDGE **parent;

void dfs_visit(EDGE *edge, VERTEX *matrix){
        d[edge->vertex_no] = ++time;
        color[edge->vertex_no]=GRAY;
        EDGE *tedge = get_edge_list(matrix, edge->vertex_no);
        for(;tedge;tedge=tedge->next){
                if(color[tedge->vertex_no]==WHITE){
                        parent[tedge->vertex_no]=edge;
                        dfs_visit(tedge, matrix);
                }
        }
        f[edge->vertex_no] = ++time;
        color[edge->vertex_no]=BLACK;
}

EDGE *dfs(VERTEX *matrix, int vertex_count){
        color = malloc(sizeof(enum colorset)*vertex_count);
        d = malloc(sizeof(int)*vertex_count);
        f=malloc(sizeof(int)*vertex_count);
        parent = malloc(sizeof(EDGE *)*vertex_count);
        for(int i=0;i<vertex_count;i++){
                int index = matrix[i].edge->vertex_no;
                color[index]=WHITE;
                parent[index]=NULL;
        }
        for(int i=0;i<vertex_count;i++){
                EDGE *edge = create_edge(i, 0);
                dfs_visit(edge, matrix);
        }
        return parent;
}