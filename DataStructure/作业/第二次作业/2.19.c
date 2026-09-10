#include<stdio.h>

#define Elemtype int
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef struct LNode{
    Elemtype val;
    struct LNode* next;
}LNode,*LinkList;

Status del_range(LinkList head,Elemtype mink,Elemtype maxk){
    if(!(head) || !(head->next))
        return FALSE;

    LNode *p = head->next,*q,*ppre = head;
    while(p && p->val <= mink){
        ppre = p;
        p = p->next;
    }

    if(!p)
        return TRUE;

    q = p;
    while(q && q->val < maxk)
        q = q->next;

    ppre->next = q;
    while(p != q){
        LNode *tmp = p->next;
        free(p);
        p = tmp;
    }

    return TRUE;
}