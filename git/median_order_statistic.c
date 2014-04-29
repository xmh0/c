#include<stdio.h>

int partition(int *src, int start, int end){
        int i=start-1, exchange;
        for(int j=start; j<=end; j++){
                if(src[end]>=src[j]){
                        i++;
                        exchange = src[j];
                        src[j] = src[i];
                        src[i] = exchange;
                 }
        }
        if(i < end){
                exchange = src[end];
                src[end] = src[i+1];
                src[i+1] = exchange;
        }
        return i;
}

int median_select(int *src, int start, int end, int index){
        if(start == end){
                return src[start];
        }
        int ret = partition(src, start, end);
        if(ret == index){
                return src[ret];
        }
        if(ret<index){
               return median_select(src, ret+1, end, index);
        }else{
               return median_select(src, start, ret-1, index);
        }
}

/*
int partitiond(int *src, int start, int end)(
        int i=0;
        return 0;
)
 * */