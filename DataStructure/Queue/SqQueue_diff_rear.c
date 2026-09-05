#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Max_Size 10

typedef struct{
    int arr[Max_Size];
    int front,rear;
}SqQueue;

SqQueue* init(){
    SqQueue *sq = malloc(sizeof(SqQueue));
    if(!sq){
        printf("fail!\n");
        return NULL;
    }
    sq->front = 0;
    sq->rear = -1;
    return sq;
}

//这里又忘记了传址才能置空
int destroy(SqQueue **sq){
    if(!sq || !*sq)
        return 0;
    SqQueue *psq = *sq;
    *sq = NULL;
    free(psq);
    return 1;
}

int is_full(SqQueue *sq){
    return (sq->rear+2)%Max_Size == sq->front;
}

int is_empty(SqQueue *sq){
    return (sq->rear+1)%Max_Size == sq->front;
}

int enqueue(int x,SqQueue *sq){
    if(is_full(sq)){
        printf("FULL!\n");
        return 0;
    }
    sq->rear = (sq->rear+1)%Max_Size;
    sq->arr[sq->rear] = x;
    return 1;
}

int dequeue(SqQueue *sq,int *val){
    if(is_empty(sq)){
        printf("EMPTY!\n");
        return 0;
    }
    *val = sq->arr[sq->front++];
    sq->front %= Max_Size;
    return 1;
}

