#include<stdio.h>
#include<stdlib.h>

#define Elemtype int
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define errV 114514
typedef int Status;

typedef struct{
    Elemtype *base;
    Elemtype *top;
    int size;
}SqStack;

SqStack InitStack(int size){
    SqStack s;
    if(!(s.base = (Elemtype*)malloc(size*sizeof(Elemtype))))
        exit(OVERFLOW);

    s.top = s.base;
    s.size = size;

    return s;
}

//Status FreeStack(SqStack *s){}

Status ClearStack(SqStack *s){
    if(!s)
        return ERROR;

    free(s->base);
    s->top = s->base = NULL;

    //s->top = s->base;
    return OK;
}

Status StackEmpty(SqStack s){
    return s.base == s.top;
}

size_t StackLen(SqStack s){
    return s.top - s.base;
}

Elemtype GetTop(SqStack s){
    if(!StackEmpty(s))
        return *(s.top-1);
    else
        return ERROR;
}

Status Push(SqStack* s,Elemtype e){
    if(StackLen(*s) == s->size){
        s->base = (Elemtype*)realloc(s->base,s->size*2*sizeof(Elemtype));
        s->top = s->base + s->size;
        s->size *= 2;
    }

    *(s->top++) = e;

    return OK;
}

Status Pop(SqStack* s){
    if(StackEmpty(*s))
        return ERROR;

    s->top--;
    return OK;
}

void visit(SqStack s,size_t idx){
    printf("%d ",*(s.base+idx));
}

void StackTrav(SqStack s,void (*visit)(SqStack,size_t)){
    for(size_t i = 0; i < StackLen(s); i++)
        visit(s,i);
}
