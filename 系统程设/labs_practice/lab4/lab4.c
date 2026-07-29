#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
}Lnode;

typedef struct LRU{
    int capacity;
    int num;
    Lnode *head;
    Lnode *tail;
}LRU;

int my_strcmp(char *a,char *b){
    int i = 0;
    while (*(a+i) != '\0' && *(b+i) != '\0' && *(a+i) == *(b+i)){
        i++;
    }
    return *(a+i)-*(b+i);
}

Lnode* LRUCache(int capacity,LRU* LRU_list){
    Lnode *head,*tail;
    head = (Lnode*)malloc(sizeof(Lnode));
    tail = (Lnode*)malloc(sizeof(Lnode));    
    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;
    LRU_list->capacity = capacity;
    LRU_list->head = head;
    LRU_list->num = 0;
    LRU_list->tail = tail;
    return head;
}

int get(int key,LRU* LRU_list){
    Lnode *p = LRU_list->head->next;
    while(p!=LRU_list->tail){
        if(p->key == key)
            break;
        p = p->next;
    }
    if(p == LRU_list->tail)
        return -1;

    Lnode *q = p->prev;
    q->next = p->next;
    (p->next)->prev = q;
    p->next = LRU_list->head->next;
    p->prev = LRU_list->head;
    (LRU_list->head->next)->prev = p;
    LRU_list->head->next = p;
    return p->value;
}

void put(int key, int value,LRU* LRU_list){
    Lnode *p = LRU_list->head->next;
    while(p != LRU_list->tail){
        if(p->key == key)
            break;
        p = p->next;
    }

    if(p == LRU_list->tail){
        p = (Lnode*)malloc(sizeof(Lnode));
        p->key = key;
        p->value = value;    
        if(LRU_list->num < LRU_list->capacity){ 
            LRU_list->num++; 
            p->prev = LRU_list->head;
            p->next = LRU_list->head->next;
            Lnode *q = LRU_list->head->next;
            LRU_list->head->next = p;
            q->prev = p;
        }
        else{
            Lnode *last = LRU_list->tail->prev;
            Lnode *q = last->prev;
            q->next = LRU_list->tail;
            free(last);
            LRU_list->tail->prev = q;
            p->next = LRU_list->head->next;
            p->prev = LRU_list->head;
            LRU_list->head->next->prev = p;
            LRU_list->head->next = p;
        }
    }
    else{
        p->value = value;
        Lnode *q = p->prev;
        q->next = p->next;
        (p->next)->prev = q;
        p->next = LRU_list->head->next;
        p->prev = LRU_list->head;
        LRU_list->head->next->prev = p;
        LRU_list->head->next = p;
    }
    p = LRU_list->head->next;
}

int main(){
    LRU *LRU_list = malloc(sizeof(LRU));
    Lnode *head;
    int capacity,n,k=0;
    char op[10];
    scanf("%d %d",&capacity,&n);
    int *output = (int*)malloc(sizeof(int)*n);
    head = LRUCache(capacity,LRU_list);
    for(int i=0;i<n;i++){
        scanf("%s",op);
        if (!my_strcmp(op,"get")){
            int key;
            scanf("%d",&key);
            output[k++] = get(key,LRU_list);
            continue;
        }
        if (!my_strcmp(op,"put")){
            int key,value;
            scanf("%d %d",&key,&value);
            put(key,value,LRU_list);
            continue;
        }
    }
    for(int i = 0; i < k; i++){
        printf("%d ",output[i]);
    }
    return 0;
}