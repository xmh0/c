#include<stdio.h>
#include<stdlib.h>

#include"common.h"
#include"list.h"
#include"graph.h"
#include"queue.h"
#include"set.h"

//void test_adjacency_matrix(){
        //VERTEX *v = create_matrix(5);
        /*
        set_matrix(0, v, (EDGE []){{1, 0}, {4, 0}}, 2);
        set_matrix(1, v, (EDGE []){{0, 0},{2, 0},{3, 0},{4, 0}}, 4);
        set_matrix(2, v, (EDGE []){{1, 0}, {3, 0}}, 2);
        set_matrix(3, v, (EDGE []){{1, 0}, {2, 0}, {4, 0}}, 3);
        set_matrix(4, v, (EDGE []){{0, 0}, {1, 0}, {3, 0}}, 3);
*/
        //test_get_bit(v, 0, 1);
//}


/*
void test_w(){
        int p[2][2]={{1,2}, {3,4}};
        //int *p1[2]={{1,2}, {3,4}};
        int **p1;
        p1=p;
        printf("%d", (p1+1)[0]);
}
*/

void adjlist_bfs();
void adjlist_dfs();

int main(){
        //adjlist();
        //adjlist_dfs();
        test_set();
        printf(" \n main end \n");
        return 0;
}

void test_set(){
        NODE *set = init_set(10);
        for(int i=0;i<10;i++){
                make_set(set, i);
        }
        union_set(set, 0, 1);
        union_set(set, 1, 2);
        if(find_set(set, 3)==find_set(set, 2)){
                printf(" 1 and 2 is belong to the same set \n");
        }else{
                printf(" not contained \n");
        }
}

void adjlist_bfs(){
        VERTEX *v = create_vertex_links(5);
        create_edge_list(v, 0, (EDGE []){{1, 0}, {4, 0}}, 2);
        create_edge_list(v, 1, (EDGE []){{0, 0},{2, 0},{3, 0},{4, 0}}, 4);
        create_edge_list(v, 2, (EDGE []){{1, 0}, {3, 0}}, 2);
        create_edge_list(v, 3, (EDGE []){{1, 0}, {2, 0}, {4, 0}}, 3);
        create_edge_list(v, 4, (EDGE []){{0, 0}, {1, 0}, {3, 0}}, 3);
        
        EDGE *parent = bfs(v, 0, 5);
        printf(" bfs: ");
        print_path_rec(parent, 3);
        printf("\n");
        print_path(parent, 3);
        
        /*
        printf("no: %d \n", edges_list[0]->next->next->vertex_no);
        printf("weight: %d \n", edges_list[0]->next->next->weight);
        */
}

void adjlist_dfs(){
        VERTEX *v = create_vertex_links(5);
        create_edge_list(v, 0, (EDGE []){{1, 0}, {4, 0}}, 2);
        create_edge_list(v, 1, (EDGE []){{0, 0},{2, 0},{3, 0},{4, 0}}, 4);
        create_edge_list(v, 2, (EDGE []){{1, 0}, {3, 0}}, 2);
        create_edge_list(v, 3, (EDGE []){{1, 0}, {2, 0}, {4, 0}}, 3);
        create_edge_list(v, 4, (EDGE []){{0, 0}, {1, 0}, {3, 0}}, 3);
        
        EDGE *parent = dfs(v, 5);
        printf(" dfs: \n");
        print_path_rec(parent, 3);
        printf("\n");
        print_path(parent, 3);
        
        /*
        printf("no: %d \n", edges_list[0]->next->next->vertex_no);
        printf("weight: %d \n", edges_list[0]->next->next->weight);
        */
}

