#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}stacknode,*linkstack;

linkstack init(){
    linkstack stack_head = malloc(sizeof(stacknode));
    if(!stack_head){
        printf("nullptr!\n");
        return NULL;
    }
    stack_head->next = NULL;
    return stack_head;
}

int destroy(linkstack* ls){
    if(!ls || !(*ls))
        return 0;
    while((*ls)->next){
        linkstack tmp = (*ls)->next->next;
        free((*ls)->next);
        (*ls)->next = tmp;
    }  
    free(*ls);
    *ls = NULL;
    return 1;
}

int push(int val, linkstack ls){
    if(!ls)
        return 0;
    stacknode *p = malloc(sizeof(stacknode));

    if(!p){
        printf("malloc fail\n");
        return -1;
    }

    p->val = val;
    p->next = ls->next;
    ls->next = p;
    return 1;
}

int is_empty(linkstack ls){
    if(!ls){
        printf("nullptr!\n");
        return 0;
    }
    if(!ls->next){
        printf("EMPTY!\n");
        return 1;
    }
    return 0;
}

int pop(linkstack ls,int *val){
    if(is_empty(ls))
        return 0;
    stacknode *p = ls->next;
    *val = p->val;
    ls->next = p->next;
    free(p);
    return 1;
}