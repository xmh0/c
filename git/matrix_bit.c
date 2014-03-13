/*
 * matrix_bit.c
 *
 *  Created on: Mar 10, 2014
 *      Author: xmh
 */

#include<stdio.h>

#include "common.h"
#include "matrix_bit.h"

#define CHARLEN (sizeof(char)*8)

int get_matrix_len(int len){
        return (len + CHARLEN -1)/CHARLEN;
}
VERTEX *create_matrix_bit(int vcount){
        VERTEX *vertics = create_vertex_links(vcount);
        for(int i=0; i<vcount; i++){
                int len = get_matrix_len(i+1);
                vertics[i].matrix = malloc(sizeof(char)*(len + 1));
                if(vertics[i].matrix == NULL){
                        printf("malloc error.");
                }
                vertics[i].matrix[0]='1';
                vertics[i].matrix[len] = '\0';
        }
        return vertics;
}

void set_edge_bit(int vertex_no, VERTEX *vertex, EDGE *edges, int edges_count){
        for(int i=0; i< edges_count; i++){
                int edge_no = edges[i].vertex_no;
                if( edge_no < vertex_no){
                        int tmp=edge_no;
                        edge_no=vertex_no;
                        vertex_no=tmp;
                }
                vertex[edge_no].matrix[vertex_no/8] |= 1<<(vertex_no%8);
        }
}

int ishas_edge(VERTEX *v, int i, int j){
        if(i<j){
                int tmp = i;
                i=j;
                j=tmp;
        }
        if((v[i].matrix[j/8]>>(j%8))&1){
                return 1;
        }else{
                return 0;
        }
}

/*
void test_adjacency_matrix(){
        VERTEX *v = create_matrix(5);
        set_matrix(0, v, (EDGE []){{1, 0}, {4, 0}}, 2);
        set_matrix(1, v, (EDGE []){{0, 0},{2, 0},{3, 0},{4, 0}}, 4);
        set_matrix(2, v, (EDGE []){{1, 0}, {3, 0}}, 2);
        set_matrix(3, v, (EDGE []){{1, 0}, {2, 0}, {4, 0}}, 3);
        set_matrix(4, v, (EDGE []){{0, 0}, {1, 0}, {3, 0}}, 3);

        test_get_bit(v, 0, 1);
}
*/

