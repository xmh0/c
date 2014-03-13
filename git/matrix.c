/*
 * matrix.c
 *
 *  Created on: Mar 10, 2014
 *      Author: xmh
 */
#include<stdio.h>
#include"common.h"

int **create_matrix_weight(int vertex_count){
        int **matrix = malloc(sizeof(int)*(vertex_count*vertex_count));
        if(matrix == NULL){
                printf("create matrix error ");
                exit(0);
        }
        return matrix;
}

void set_edge_weight(int **matrix, int v, int w, int weight){
        (matrix+v)[w]=weight;
}

int get_edge_weight(int **matrix, int v, int w){
       return (matrix+v)[w];
}

/*
void test_matrix_w(){
        int **test = create_matrix_w(5);
        set_matrix_w(test, 0, 1, 1);
        set_matrix_w(test, 0, 4, 1);
        int ret = get_matrix_w(test, 0, 4);
        printf("%d", ret);
}
*/

