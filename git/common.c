/*
 * common.c
 *
 *  Created on: Mar 10, 2014
 *  Author: xmh
 */

#include<stdlib.h>
#include<stdio.h>
#include"common.h"
#include"list.h"

VERTEX *create_vertex_links(int vcount){
        VERTEX *vertics = malloc(sizeof(VERTEX)*vcount);
        for(int i=0; i<vcount; i++){
                vertics[i].number=0;
                vertics[i].matrix=NULL;
                vertics[i].edge=NULL;
        }
        return vertics;
}

EDGE *create_edge(int vertex_no, int weight){
        EDGE *edge = malloc(sizeof(EDGE));
        if(edge==NULL){
                printf("create edge error !");
                exit(0);
        }
        edge->vertex_no=vertex_no;
        edge->weight = weight;
        edge->next=NULL;
        return edge;
}

int get_edge_weight(VERTEX *vertics, int u, int v){
        EDGE *edge = get_edge_list(vertics, u);
        for(; edge; edge=edge->next){
                if(edge->vertex_no == v){
                        return edge->weight;
                }
        }
        return -1;
}

void print_path(EDGE **parent, int s){
        printf("%d ", s);                
        while(parent[s]){
                printf("%d ", parent[s]->vertex_no);
                s=parent[s]->vertex_no; 
        }
}

void print_path_rec(EDGE **parent, int s){
        if(parent[s]==NULL){
                printf("%d ", s);
                return;
        }
        print_path_rec(parent, parent[s]->vertex_no);
        printf("%d ", s);
}