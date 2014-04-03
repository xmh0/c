/* 
 * File:   bfs.h
 * Author: xmh
 *
 * Created on 2014年3月14日, 上午1:29
 */
#include"common.h"

#ifndef GRAPH_H
#define	GRAPH_H

EDGE *bfs(VERTEX *matrix, int vertex_no, int vertex_count);
EDGE *dfs(VERTEX *matrix, int vertex_count);

#endif	/* BFS_H */