/*
 * common.h
 *
 *  Created on: Mar 10, 2014
 *      Author: xmh
 */

#ifndef COMMON_H_
#define COMMON_H_


typedef struct edge EDGE;
typedef struct vertex VERTEX;

struct edge{
        int vertex_no;
        int weight;
        EDGE *next;
};
struct vertex{
        int number;
        char *matrix;
        EDGE *edge;
};

extern VERTEX *create_vertex_links(int vcount);
extern EDGE *create_edge(int vertex_no, int weight);
extern void print_path(EDGE **parent, int s);
extern void print_path_rec(EDGE **parent, int s);

#endif /* COMMON_H_ */
