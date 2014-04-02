#include<stdio.h>
#include<stdlib.h>

#include"common.h"
#include"list.h"
#include"graph.h"
#include"queue.h"
#include"set.h"

#include"heap.h"
#define swap(x,y) {__typeof__(x) _x=x; __typeof__(y) _y=y; x=_y; y=_x;}

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
void test_heap();
struct testi{
        int i;
};
typedef struct testi t;

int main(){
        //adjlist();
        //adjlist_dfs();
        //test_set();
        test_heap();
        return 0;
}

void test_heap(){
        HEAP *heap = create_max_heap(5);
        
        HEAP_NODE *t1,*t2,*t3,*t4,*t5;
        
        t1=malloc(sizeof(HEAP_NODE));
        t2=malloc(sizeof(HEAP_NODE));
        t3=malloc(sizeof(HEAP_NODE));
        t4=malloc(sizeof(HEAP_NODE));
        t5=malloc(sizeof(HEAP_NODE));
        
        t1->index=5;
        t2->index=3;
        t3->index=2;
        t4->index=1;
        t5->index=4;
        
        insert_max_heap(heap, t1);
        insert_max_heap(heap, t2);
        insert_max_heap(heap, t3);
        insert_max_heap(heap, t4);
        insert_max_heap(heap, t5);
      
        /*
        sort_max_heap(heap);
        for(int i=0; i<5;i++){
                printf("%d ", heap->ele[i]->index);
        }
        return;
        */
        
        HEAP_NODE *node = maximum(heap);
        printf("maximum: %d ", node->index);
     
        node = extract_max_heap(heap);
        printf("\nextract: %d ", node->index);
        
        node = extract_max_heap(heap);
        printf("extract: %d ", node->index);
        
        node = extract_max_heap(heap);
        printf("extract: %d ", node->index);
        
        node = extract_max_heap(heap);
        printf("extract: %d ", node->index);
        
        node = extract_max_heap(heap);
        printf("extract: %d ", node->index);
        
        //insert(heap, &t5);
               
        //sort_max_heap(heap);
            
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

