#include<stdio.h>
#include<stdlib.h>
#include "set.h"

struct set_tree_node{
        int number;
        int rank;
        NODE *parent;
};

NODE *init_set(int len){
        NODE *set = malloc(sizeof(NODE)*len);
        if(set == NULL){
                printf("it is malloc error \n");
                return NULL;
        }
        return set;
}
void make_set(NODE *set, int number){
        set[number].number = number;
        set[number].rank = 0;
        set[number].parent = &set[number];
}
NODE *find_set(NODE *set, int number){
        NODE *node = &set[number];
        if(node->parent!=node){
          node->parent=find_set(set, node->parent->number);  
        }
        return node->parent;
}
void union_set(NODE *set, int x, int y){
        NODE *nodex = find_set(set, x), *nodey = find_set(set, y);
        if(nodex->rank>nodey->rank){
                nodey->parent = nodex;
        }else{
                nodex->parent = nodey;
                if(nodex->rank==nodey->rank){
                        nodey->rank=nodey->rank+1;
                }
        }
}