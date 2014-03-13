/*
 * matrix_bit.h
 *
 *  Created on: Mar 10, 2014
 *      Author: xmh
 */

#ifndef MATRIX_BIT_H_
#define MATRIX_BIT_H_

extern VERTEX *create_matrix_bit(int vcount);
extern void set_edge_bit(int vertex_no, VERTEX *vertex, EDGE *edges, int edges_count);
extern int ishas_edge(VERTEX *v, int i, int j);

#endif /* MATRIX_BIT_H_ */
