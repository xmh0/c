/* 
 * File:   bfs.h
 * Author: xmh
 *
 * Created on 2014年3月14日, 上午1:29
 */
#include"common.h"
#include"min_heap.h"

#ifndef GRAPH_H
#define	GRAPH_H

EDGE *bfs(VERTEX *matrix, int vertex_no, int vertex_count);
EDGE *dfs(VERTEX *matrix, int vertex_count);

GRAPH_EDGE *kruskal(HEAP *heap, int vertex_count);
int *prim(VERTEX *graph, int vertex_count, int root);

#endif	/* BFS_H */