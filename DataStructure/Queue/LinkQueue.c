#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *prev;
    struct node *next;
}Lnode,*Linklist;

typedef struct{
    //int cnt;
    Lnode *head;
    Lnode *tail;
}LinkQueue;

LinkQueue* init(){
    
}