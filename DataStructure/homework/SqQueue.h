#include <stdio.h>
#include <stdlib.h>

#ifndef qtype
    #define qtype int
#endif

#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define errV 114514
#define MAXQSIZE 100

typedef int Status;

typedef struct{
    qtype *base;
    int front, rear;
} SqQueue;


Status InitQueue(SqQueue *q)
{
    if(!(q->base = (qtype *)malloc(MAXQSIZE * sizeof(qtype))))
        return OVERFLOW;

    q->front = q->rear = 0;
    return OK;
}

Status DestroyQueue(SqQueue *q)
{
    if(!q->base)
        return ERROR;

    free(q->base);
    q->base = NULL;
    q->front = q->rear = 0;

    return OK;
}

Status ClearQueue(SqQueue *q)
{
    if(!q->base)
        return ERROR;

    q->front = q->rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue q){
    return q.front == q.rear;
}

Status QueueLenth(SqQueue q)
{
    return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}

Status GetHead(SqQueue q, qtype *e)
{
    if(q.front == q.rear)
        return ERROR;

    *e = q.base[q.front];
    return OK;
}

Status EnQueue(SqQueue *q, qtype e)
{
    // rear 再向前一步就碰到 front，说明队满
    if((q->rear + 1) % MAXQSIZE == q->front)
        return ERROR;

    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAXQSIZE;

    return OK;
}

Status DeQueue(SqQueue *q, qtype *e)
{
    if(q->front == q->rear)
        return ERROR;

    *e = q->base[q->front];
    q->front = (q->front + 1) % MAXQSIZE;

    return OK;
}