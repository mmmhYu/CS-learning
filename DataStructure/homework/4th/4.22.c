#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAXQSIZE 100

#define FALSE 0
#define TRUE 1

#define OK 1
#define ERROR 0

#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

#define BUFF_SIZE 4

typedef struct StrNode{
    char *buff;
    struct StrNode *next;
}StrNode,*StrList;

void CreateMyList(char *str,StrNode **head,StrNode **tail){
    *head = (StrNode*)malloc(sizeof(StrNode));
    (*head)->buff = NULL;
    (*head)->next = NULL;

    *tail = *head;

    int len = strlen(str);
    int idx = 0;

    while(idx < len){
        StrNode *node = (StrNode*)malloc(sizeof(StrNode));
        node->buff = (char*)malloc(BUFF_SIZE * sizeof(char));
        node->next = NULL;

        for(int i = 0; i < BUFF_SIZE; i++){
            if(idx < len)
                node->buff[i] = str[idx++];
            else
                node->buff[i] = '#';
        }

        (*tail)->next = node;
        *tail = node;
    }
}

Status insertBuff(StrList sl,char c,char *str){
    StrNode *p = sl->next,*pre = sl;
    int i;
    while(p){
        for(i = 0; i < BUFF_SIZE; i++)
            if(p->buff[i] == c)
                break;

        if(i == BUFF_SIZE){
            pre = p;
            p = p->next;
        }
        else
            break;
        
    }

    StrNode *head,*tail;

    CreateMyList(str,&head,&tail);

    if(!p)
        pre->next = head->next;
    else{
        StrNode *p1 = (StrNode*)malloc(sizeof(StrNode)),
                *p2 = (StrNode*)malloc(sizeof(StrNode));
        p1->buff = (char*)malloc(BUFF_SIZE*sizeof(char));
        p2->buff = (char*)malloc(BUFF_SIZE*sizeof(char));
        for(int m = 0; m <= i; m++){
            p1->buff[m] = p->buff[m];
            p2->buff[m] = '#';
        }
        for(int m = i+1; m < BUFF_SIZE; m++){
            p2->buff[m] = p->buff[m];
            p1->buff[m] = '#';
        }

        p1->next = head->next;
        pre->next = p1;
        tail->next = p2;
        p2->next = p->next;
    }

    free(p);
    return OK;
}

// 打印块链串，遇到 # 跳过
void PrintStr(StrList sl){
    StrNode *p = sl->next;

    while(p){
        for(int i = 0; i < BUFF_SIZE; i++){
            if(p->buff[i] != '#')
                putchar(p->buff[i]);
        }
        p = p->next;
    }

    putchar('\n');
}


// 创建一个块
StrNode *CreateNode(const char *str){
    StrNode *node = (StrNode*)malloc(sizeof(StrNode));
    node->buff = (char*)malloc(BUFF_SIZE * sizeof(char));
    node->next = NULL;

    int len = strlen(str);

    for(int i = 0; i < BUFF_SIZE; i++){
        if(i < len)
            node->buff[i] = str[i];
        else
            node->buff[i] = '#';
    }

    return node;
}


// 释放整个块链串
void FreeStr(StrList sl){
    StrNode *p = sl;

    while(p){
        StrNode *next = p->next;
        free(p->buff);
        free(p);
        p = next;
    }
}


int main(){
    StrList head;
    StrNode *tail;

    CreateMyList("abcdefghijklmn", &head, &tail);

    printf("Before: ");
    PrintStr(head);

    insertBuff(head, 'c', "XYZ");

    printf("After : ");
    PrintStr(head);

    FreeStr(head);
    return 0;
}