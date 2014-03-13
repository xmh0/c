/*
 * common.h
 *
 *  Created on: Mar 10, 2014
 *      Author: xmh
 */

#ifndef COMMON_H_
#define COMMON_H_

struct vertex{
        int number;
        char *matrix;
};
struct edge{
        int vertex_no;
        int weight;
        struct edge *next;
};

typedef struct edge EDGE;
typedef struct vertex VERTEX;

extern VERTEX *create_vertex_links(int vcount);
extern EDGE *create_edge(int vertex_no, int weight);

#endif /* COMMON_H_ */
