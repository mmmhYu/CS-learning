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

int equal(Elemtype a,Elemtype b){
    return a == b;
}

typedef struct LNode{
    Elemtype val;
    struct LNode* next;
}LNode,*LinkList;

LinkList InitList(){
    LNode *head = malloc(sizeof(LNode));
    if(!head)
        return NULL;

    head->next = NULL;

    return head;
}

Status FreeList(LinkList* L){
    if((!L) || (!(*L)))
        return ERROR;

    LNode *p = (*L)->next;
    free(*L);
    *L = NULL;


    while(p){
        LNode *tmp = p->next;
        free(p);
        p = tmp;
    }

    return OK;
}

Status ListEmpty(LinkList L){
    if(!L)
        return ERROR;

    return !(L->next);
}

int ListLen(LinkList L){
    int i = 0;
    if(!L)
        return ERROR;

    LNode *p = L->next;
    while(p){
        i++;
        p = p->next;
    }
    return i;
}

Elemtype GetElem(LinkList L, int k){
    if(!L || k <= 0)
        return errV;

    int i = 0;
    LNode *p = L;

    while(p && i < k){
        i++;
        p = p->next;
    }
        
    if(!p)
        return errV;
    else
        return p->val;
}

Status InsertElem(LinkList L, int k, Elemtype e){
    if(!L || k <= 0)
        return ERROR;

    LNode *p = L;
    int i = 0;

    while(p && i < k-1){
        i++;
        p = p->next;
    }

    if(!p)
        return ERROR;

    LNode *node = malloc(sizeof(LNode));
    if(!node)   
        return ERROR;

    node->val = e;
    node->next = p->next;
    p->next = node;

    return OK;
}

Status ListDelete(LinkList L,int k){
    if(!L || k <= 0)
        return ERROR;

    LNode *p = L;
    int i = 0;

    while(p && i < k-1){
        p = p->next;
        i++;
    }

    LNode *q = p->next;
    p->next = q->next;
    free(q);

    return OK;
}

int LocateElem(LinkList L,Elemtype e,int (*equal)(Elemtype,Elemtype)){
    if(!L)
        return -1;

    LNode *p = L->next;
    int i = 1;

    while(p && !equal(p->val,e)){
        p = p->next;
        i++;
    }

    return p ? i : 0;
}

Elemtype PrevElem(LinkList L,Elemtype e){
    if((!L) || (!L->next) || L->next->val == e)
        return errV;

    LNode *p = L->next,*pre = L;
    while(p && p->val != e){
        pre = p;
        p = p->next;
    }

    return p ? pre->val : errV;
}

Elemtype NextElem(LinkList L,Elemtype e){
    if((!L) || (!L->next))
        return errV;

    LNode *p = L->next;
    while(p && p->val != e)
        p = p->next;

    return p && p->next ? p->next->val : errV;
}

void print_List(LinkList L){
    if(!L)
        return;

    LNode *p = L->next;

    while(p){
        printf("%d ",p->val);
        p = p->next;
    }
    
}
