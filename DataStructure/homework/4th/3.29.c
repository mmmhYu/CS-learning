#include<stdio.h>
#include<stdlib.h>

#define Elemtype int
#define MAXQSIZE 100

#define FALSE 0
#define TRUE 1

#define OK 1
#define ERROR 0

#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef struct{
    Elemtype *base;
    int front,rear;
    int tag;//初始化应置为0
}SqQueue;

Status EnQueue(SqQueue *q,Elemtype e){
    if(q->front == q->rear && q->tag){
        printf("Queue Full!");
        return ERROR;
    }

    q->base[q->rear++] = e;
    q->rear %= MAXQSIZE;
    q->tag = 1;
    return OK;
}

Status DeQueue(SqQueue *q,Elemtype *e){
    if(q->front == q->rear && !(q->tag)){
        printf("Queue Empty!");
        return ERROR;
    }

    *e = q->base[q->front++];
    q->front %= MAXQSIZE;
    q->tag = 0;
    return OK;
}