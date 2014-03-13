/*
 * list.c
 *
 *  Created on: Mar 10, 2014
 *      Author: xmh
 */
#include<stdio.h>
#include"common.h"

void create_edge_list(EDGE *first, EDGE *edge_arr, int arrlen){
        EDGE *tmp = first;
        for(int i=0; i<arrlen; i++){
                tmp->next = create_edge(edge_arr[i].vertex_no, edge_arr[i].weight);
                if(tmp->next == NULL){
                        printf("create_edge_list error ! \n");
                        exit(0);
                }
                tmp=tmp->next;
        }
}

EDGE *get_edge_list(VERTEX *matrix, int vertex_no){
        return matrix[vertex_no];
}
