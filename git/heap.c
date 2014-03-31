#include"stdio.h"
#include"stdlib.h"

#define swap(x,y) {__typeof__(x) _x=x; __typeof__(y) _y=y; x=_y; y=_x;}

int left(int i){
        return i<<1;
}
int right(int i){
        return (i<<1)+1;
}
void max_heapify(int *src, int i){
        int l = left(i), r=right(i), largest=i;
        if(l<=src[0]&&src[l]>src[largest]){
                swap(l, largest);
        }
        if(r<=src[0]&&src[r]>src[largest]){
                swap(r, largest);
        }
        if(i!=largest){
                swap(src[i], src[largest]);
                max_heapify(src, largest);
        }
}
int *create_max_heap(int size){
        int *src = malloc(sizeof(int)*(size+1));
        if(src == NULL){
                printf("init_max_heap malloc error");
        }
        return src;
}
void build_max_heap(int *src, int size){
        src[0] = size;
        for(int i=(size/2); i>0; i--){
                max_heapify(src, i);
        }
}
void sort_max_heap(int *src, int size){
        build_max_heap(src, size);
        for(int i=size; i>0; i--){
                src[0] = src[0] - 1;
                swap(src[1], src[i]);
                max_heapify(src, 1);
        }
}