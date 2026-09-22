#include<stdio.h>
#include<stdlib.h>

#define MAXQSIZE 100

#define FALSE 0
#define TRUE 1

#define OK 1
#define ERROR 0

#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

//双端非循环队列
typedef struct{
    char *base;
    int front,rear;
}SqQueue;

Status IsPalindrome(char *str){
    SqQueue q;

    if(!(q.base = (char*)malloc(MAXQSIZE*sizeof(char)))){
        printf("Malloc Fail!");
        return ERROR;
    }
    q.front = q.rear = 0;

    //默认不会出现字符串中无@以及str = NULL的情形
    while(*str != '@')
        Enqueue(&q,*(str++));

    q.rear--;
    while(q.front < q.rear)
        if(q.base[q.front++] != q.base[q.rear--]){
            free(q.base);
            return FALSE;
        }
            
    free(q.base);
    return TRUE;
}
