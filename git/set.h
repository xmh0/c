/* 
 * File:   set.h
 * Author: xmh
 *
 * Created on 2014年3月27日, 下午8:55
 */

#ifndef SET_H
#define	SET_H

typedef struct set_tree_node SET;

SET *create_set(int len);
void make_set(SET *set, int number);
SET *find_set(SET *set, int number);
void union_set(SET *set, int x, int y);

#endif	/* SET_H */

