#include<stdio.h>
#include<stdlib.h>

#define my_size 10

typedef struct{
    int arr[my_size];
    int head;
    int tail;
    int cnt;
}SqQueue;

SqQueue* init(){
    SqQueue* sq = malloc(sizeof(SqQueue));
    sq->cnt = 0;
    sq->cnt = sq->tail = 0;
    return sq;
}

int destroy(SqQueue **sq){
    if(!sq || !(*sq)){
        printf("nullptr!\n");
        return 0;
    }

    free(*sq);
    *sq = NULL;
    return 1;
}

int is_full(SqQueue *sq){
    if(!sq){
        printf("nullptr!\n");
        return -1;
    }

    if(sq->cnt == my_size){
        printf("FULL!\n");
        return 1;
    }
    
    return 0;
}

int is_full(SqQueue *sq){
    if(!sq){
        printf("nullptr!\n");
        return -1;
    }

    if(sq->cnt == 0){
        printf("EMPTY!\n");
        return 1;
    }
    
    return 0;
}

int enqueue(int val, SqQueue *sq){
    if(is_full(sq))
        return 0;
    sq->arr[sq->tail] = val;
    sq->tail = (++(sq->tail))%my_size;
    sq->cnt++;
    return 1;
}

int dequeue(int *val, SqQueue *sq){
    if(is_empty(sq))
        return 0;
    *val = sq->arr[sq->head];
    sq->head = (++(sq->head))%my_size;
    sq->cnt--;
    return 1;
}
//问题主要有：
//取余数写成整除
//更好的方法不需要cnt计数：看tail有没有追上head
//数学上：tail+1是不是和head mod my_size同余

