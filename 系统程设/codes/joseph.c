#include<stdio.h>
#include<stdlib.h>
#define n 20
#define m 5

typedef struct node{
    int val;
    struct node *next;
}Lnode,*Linklist;

Lnode *gen_cycle_linklist(int *arr,int len){
    int i,num;
    Lnode *head,*tail,*p;
    head = (Lnode*)malloc(sizeof(Lnode));
    head->next = NULL;
    tail = NULL;
    for(i = 0; i < len; i++){
        num = arr[i];
        p = (Lnode*)malloc(sizeof(Lnode));
        p->val = num;
        p->next = NULL;
        if(!head->next)
            head->next = p;
        else
            tail->next = p;
        tail = p;
    }
    p->next = head->next;
    return head;
}

int fun(Linklist head){
    Lnode *p = head->next;
    int tmp = 1,res = n;
    while(res>1){
        while(tmp != m-1){
            p = p->next;
            tmp++;
        }
        tmp = 1;
        p->next = (p->next)->next;
        res--;
        p = p->next;
    }
    return p->val;
}

int main(){
    int arr[n];
    for(int i = 1; i <= n; i++)
        arr[i-1] = i;
    Linklist l = gen_cycle_linklist(arr,n);
    printf("%d\n",fun(l));
    return 0;
}
