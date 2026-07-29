#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 10

typedef struct{
    int data[MaxSize];
    int top;
}SqStack;

bool Init(SqStack *S){
    S->top = -1;
    for(int i=0;i<10;i++)
        S->data[i] = 0;
    return true;
}

bool Judge_Empty(SqStack S){
    if(S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack *S,int a){
    if(S->top < MaxSize-1){
        S->data[++S->top] = a;
        return true;
    }
    else
        return false;
}