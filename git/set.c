#include<stdio.h>
#include<stdlib.h>
#include "set.h"

struct set_tree_node{
        int number;
        int rank;
        SET *parent;
};

SET *create_set(int len){
        SET *set = malloc(sizeof(SET)*len);
        if(set == NULL){
                printf("it is malloc error \n");
                return NULL;
        }
        return set;
}
void make_set(SET *set, int number){
        set[number].number = number;
        set[number].rank = 0;
        set[number].parent = &set[number];
}
SET *find_set(SET *set, int number){
        SET *node = &set[number];
        if(node->parent!=node){
          node->parent=find_set(set, node->parent->number);  
        }
        return node->parent;
}
void union_set(SET *set, int x, int y){
        SET *nodex = find_set(set, x), *nodey = find_set(set, y);
        if(nodex->rank>nodey->rank){
                nodey->parent = nodex;
        }else{
                nodex->parent = nodey;
                if(nodex->rank==nodey->rank){
                        nodey->rank=nodey->rank+1;
                }
        }
}