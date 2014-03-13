/*
 * matrix.h
 *
 *  Created on: Mar 10, 2014
 *      Author: xmh
 */

#ifndef MATRIX_H_
#define MATRIX_H_

extern int **create_matrix_weight(int vertex_count);
extern void set_edge_weight(int **matrix, int v, int w, int weight);
extern int get_edge_weight(int **matrix, int v, int w);

#endif /* MATRIX_H_ */
