#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<memory.h>

#include"graph.h"
#include"list.h"
#include"set.h"
#include"min_heap.h"
#include"common.h"
#include"queue.h"

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
void test_kruskal();
void test_dijkstar();

struct testi{
        int i;
};
typedef struct testi t;
void test_header();

void test_sum(int num, ...){
        va_list ap;
        va_start(ap, 1);
        memset(ap, -1, sizeof(ap));
        int id = va_arg(ap, int);
        va_end(ap);
        
        printf("\n id:%d\n", id);
}
int main(){
        //adjlist();
        //adjlist_dfs();
        //test_set();
        
        //test_min_heap();
        //test_sum(1);
        //test_kruskal();
        //test_pointer();
        //test_memset();
        //printf("--------\n");
        //test_prim();
        test_dijkstar();
        return 0;
}
void test_header(){
        printf("it is head file.");
}
void test_memset(){
        int a[10];
        memset(a, NULL, sizeof(int)*10);
        printf("a[0]: %d", NULL);
}

void test_pointer(){
        GRAPH_EDGE edge[14] = {{0,1,4},{1,2,8},{2,3,7},{3,4,9},{4,5,10},{5,6,2},{6,7,1},{7,0,8},{7,1,11},{7,8,7},{8,2,2},{8,6,6}, {5,2,4}, {5,3,14}};
        struct testi *i0, i1, *i2;
        i1.i=10;
        i0=&i1;
        i2=i0;
        HEAP_NODE *n0=malloc(sizeof(HEAP_NODE));
        n0->x = &edge[1];
        GRAPH_EDGE *arr[14];
        GRAPH_EDGE *edge1 = n0->x;
        arr[0]=edge1;
        printf("arr[0], weight: %d",arr[0]->weight);
}

void print_short_path(int *path, int start, int end){
        printf("\n");
        while(start != end){
                printf("%d ", start);
                start = path[start];
        }
        printf("%d", end);
}
void test_dijkstar(){
        VERTEX *v = create_vertex_links(9);
        create_edge_list(v, 0, (EDGE []){{1, 10}, {4, 5}}, 2);
        create_edge_list(v, 1, (EDGE []){{2, 1}, {4, 2}},2);
        create_edge_list(v, 2, (EDGE []){{3, 4}}, 1);
        create_edge_list(v, 3, (EDGE []){{0, 7}, {2, 6}}, 2);
        create_edge_list(v, 4, (EDGE []){{1, 3}, {2, 9}, {3, 2}}, 3);
       
        int *path = dijkstar(v, 5, 0);
        print_short_path(path, 2, 0);
        print_short_path(path, 3, 0);
        print_short_path(path, 1, 0);
        print_short_path(path, 4, 0);
}
void test_prim(){
        VERTEX *v = create_vertex_links(9);
        create_edge_list(v, 0, (EDGE []){{1, 4}, {7, 8}}, 2);
        create_edge_list(v, 1, (EDGE []){{0, 4},{2, 8},{7, 11}},3);
        create_edge_list(v, 2, (EDGE []){{1, 8}, {3, 7}, {8, 2}, {5, 4}}, 4);
        create_edge_list(v, 3, (EDGE []){{2, 7}, {4, 9}, {5, 14}}, 3);
        create_edge_list(v, 4, (EDGE []){{3, 9}, {5, 10}, {3, 0}}, 3);
        create_edge_list(v, 5, (EDGE []){{6, 2}, {4, 10}, {2, 4}, {3, 14}}, 4);
        create_edge_list(v, 6, (EDGE []){{5, 2},{7, 1},{8, 6}}, 3);
        create_edge_list(v, 7, (EDGE []){{6, 1}, {8, 7}, {0, 8}}, 3);
        create_edge_list(v, 8, (EDGE []){{7, 7}, {6, 6}, {2, 2}}, 3);
        
        /*
        HEAP *heap=create_min_heap(9);
        
        HEAP_NODE *ele=malloc(sizeof(HEAP_NODE));
        ele->index=0;
        ele->x=NULL;
        insert_min_heap(heap, ele);
        
        ele = extract_min_heap(heap);
        printf("%d ", ele->index);
        
        ele=malloc(sizeof(HEAP_NODE));
        ele->index=8;
        ele->x=NULL;
        insert_min_heap(heap, ele);
        
        ele=malloc(sizeof(HEAP_NODE));
        ele->index=4;
        ele->x=NULL;
        insert_min_heap(heap, ele);
        
        HEAP_NODE *node = extract_min_heap(heap);
        printf("%d ", node->index);
        
        ele=malloc(sizeof(HEAP_NODE));
        ele->index=8;
        ele->x=NULL;
        insert_min_heap(heap, ele);
        
        ele=malloc(sizeof(HEAP_NODE));
        ele->index=11;
        ele->x=NULL;
        insert_min_heap(heap, ele);
        
        ele=malloc(sizeof(HEAP_NODE));
        ele->index=1;
        ele->x=NULL;
        insert_min_heap(heap, ele);
        
        ele=malloc(sizeof(HEAP_NODE));
        ele->index=7;
        ele->x=NULL;
        insert_min_heap(heap, ele);
        
        HEAP_NODE *node = extract_min_heap(heap);
        printf("%d ", node->index);        
        */
        
        int *parent = prim(v, 9, 0);
        for(int i=1; i<9; i++){
                printf("%d - %d, %d \n", i, parent[i], get_edge_weight(v, i, parent[i]));
        }
}

void test_kruskal(){
        GRAPH_EDGE edge[14] = {{0,1,4},{1,2,8},{2,3,7},{3,4,9},{4,5,10},{5,6,2},{6,7,1},{7,0,8},{7,1,11},{7,8,7},{8,2,2},{8,6,6}, {5,2,4}, {5,3,14}};
        //edge[0] = {0,1,4};
        //printf("u: %d, v:%d, weight: %d", edge[0].u, edge[0].v, edge[0].weight);
        //printf("%d, %d, %d",edge[0].u, edge[0].v, edge[0].weight);
        HEAP *heap=create_min_heap(14);
        HEAP_NODE *n0=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n1=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n2=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n3=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n4=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n5=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n6=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n7=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n8=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n9=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n10=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n11=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n12=malloc(sizeof(HEAP_NODE));
        HEAP_NODE *n13=malloc(sizeof(HEAP_NODE));
        
        n0->x = &edge[0];
        n0->weight = edge[0].weight;
        insert_min_heap(heap, n0);

        n1->x=&edge[1];
        n1->weight=edge[1].weight;
        insert_min_heap(heap, n1);

        n2->x = &edge[2];
        n2->weight=edge[2].weight;
        insert_min_heap(heap, n2);

        n3->x= &edge[3];
        n3->weight=edge[3].weight;
        insert_min_heap(heap, n3);

        n4->x=&edge[4];
        n4->weight=edge[4].weight;
        insert_min_heap(heap, n4);

        n5->x=&edge[5];
        n5->weight=edge[5].weight;
        insert_min_heap(heap, n5);

        n6->x = &edge[6];
        n6->weight=edge[6].weight;
        insert_min_heap(heap, n6);

        n7->x = &edge[7];
        n7->weight=edge[7].weight;
        insert_min_heap(heap, n7);

        n8->x=&edge[8];
        n8->weight=edge[8].weight;
        insert_min_heap(heap, n8);

        n9->x=&edge[9];
        n9->weight=edge[9].weight;
        insert_min_heap(heap, n9);

        n10->x = &edge[10];
        n10->weight=edge[10].weight;
        insert_min_heap(heap, n10);

        n11->x=&edge[11];
        n11->weight=edge[11].weight;
        insert_min_heap(heap, n11);

        n12->x=&edge[12];
        n12->weight=edge[12].weight;
        insert_min_heap(heap, n12);

        n13->x=&edge[13];
        n13->weight=edge[13].weight;
        insert_min_heap(heap, n13);

        GRAPH_EDGE **mini_span_tree = kruskal(heap, 14);
        for(int i=0;i<8;i++){
                printf("%d - %d, %d \n", mini_span_tree[i]->u, mini_span_tree[i]->v, mini_span_tree[i]->weight);
        }
}

void test_min_heap(){
        HEAP *heap = create_min_heap(5);
        
        HEAP_NODE *t1,*t2,*t3,*t4,*t5;
        
        t1=create_node_heap(heap, 5, 0);
        t2=create_node_heap(heap, 3, 1);
        t3=create_node_heap(heap, 2, 2);
        t4=create_node_heap(heap, 1, 3);
        t5=create_node_heap(heap, 4, 4);
        
        insert_min_heap(heap, t1);
        insert_min_heap(heap, t2);
        insert_min_heap(heap, t3);
        insert_min_heap(heap, t4);
        insert_min_heap(heap, t5);
        
        HEAP_NODE *t6 = create_node_heap(heap, 0, 10);
        int ret = update_min_heap(heap, t6);
        printf("\nret:%d\n", ret);
        
        /*
        sort_max_heap(heap);
        for(int i=0; i<5;i++){
                printf("%d ", heap->ele[i]->index);
        }
        return;
        */
        
        HEAP_NODE *node = minimum(heap);
        printf("maximum: %d ", node->weight);
     
        node = extract_min_heap(heap);
        printf("\nextract: %d ", node->weight);
        
        node = extract_min_heap(heap);
        printf("extract: %d ", node->weight);
        
        node = extract_min_heap(heap);
        printf("extract: %d ", node->weight);
        
        node = extract_min_heap(heap);
        printf("extract: %d ", node->weight);
        
        node = extract_min_heap(heap);
        printf("extract: %d ", node->weight);
        
        //insert(heap, &t5);
               
        //sort_max_heap(heap);
            
}


void test_heap(){
        HEAP *heap = create_max_heap(5);
        
        HEAP_NODE *t1,*t2,*t3,*t4,*t5;
        
        t1=malloc(sizeof(HEAP_NODE));
        t2=malloc(sizeof(HEAP_NODE));
        t3=malloc(sizeof(HEAP_NODE));
        t4=malloc(sizeof(HEAP_NODE));
        t5=malloc(sizeof(HEAP_NODE));
        
        t1->weight=5;
        t2->weight=3;
        t3->weight=2;
        t4->weight=1;
        t5->weight=4;
        
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
        printf("maximum: %d ", node->weight);
     
        node = extract_max_heap(heap);
        printf("\nextract: %d ", node->weight);
        
        node = extract_max_heap(heap);
        printf("extract: %d ", node->weight);
        
        node = extract_max_heap(heap);
        printf("extract: %d ", node->weight);
        
        node = extract_max_heap(heap);
        printf("extract: %d ", node->weight);
        
        node = extract_max_heap(heap);
        printf("extract: %d ", node->weight);
        
        //insert(heap, &t5);
               
        //sort_max_heap(heap);
            
}

void test_set(){
        SET *set = create_set(10);
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
        printf("weight: %d \n", edges_list[0]->next->next.weight);
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
        printf("weight: %d \n", edges_list[0]->next->next.weight);
        */
}

