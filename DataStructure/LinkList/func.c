#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode
{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;

//初始化(无头结点)
int Init(LinkList *head){
    *head = NULL;//有头结点则无需传址 head->next = NULL;
    return 1;
}

//无头结点 插入第i个
int Insert_without_head(LinkList L,int k,int e){
    Lnode *p,*s;
    int i = 0;
    s=L;
    p = (Lnode*)malloc(sizeof(Lnode));
    p->data = e;
    while(s!=NULL && i<k-1){
        s=s->next;
        i++;
    }
    if(s == NULL)
        return 0;
    p->next = s->next;
    s->next = p;
    return 1;
}
//注：传址的情形是为了头插（无头结点，需要修改L的值） (抛开i==1的情形 传LinkList L便可)
//这里有头结点 不需要修改地址值 只需要传值

//在指定结点前添加
int Insert_at(Lnode *p,int e){
    Lnode *s;
    s = (Lnode*)malloc(sizeof(Lnode));
    s->data = p->data;
    s->next = p->next;
    p->data = e;
    p->next = s;
    return 1;
}

//无头结点 删除第i个
int Delete_without_head(LinkList *L,int k,int *e){
    Lnode *s=*L,*p;
    int i=0;
    while(s!=NULL && i<k-1){
        s=s->next;
        i++;
    }
    if(s==NULL || s->next==NULL)
        return 0;
    p = s->next;
    *e = p->data;
    s->next = p->next;
    free(p);
    return 1;
}

//在指定位置删除
int Delete_at(Lnode *p,int *e){
    Lnode *s;
    s = p->next;
    if(p == NULL)
        return 0;
    if(s == NULL){
        p = NULL;
        return 1;
    }
    *e = p->data;
    p->data = p->next->data;
    p->next = p->next->next;
    free(s);
    return 1;
}

//有头结点头插
int Head_Insert(LinkList L){
    L->next = NULL;
    Lnode *p,*r = L;
    int a;
    scanf("%d",&a);
    while(a != 0){//以0结束为例
        p = (Lnode*)malloc(sizeof(Lnode));
        p->data = a;
        r->next = p;
        r=p;
        scanf("%d",&a);
    }
    r->next = NULL;
    //遍历测试
    Lnode *q=L->next;
    while(q!=NULL){
        printf("%d ",q->data);
        q = q->next;
    }
    return 1;
}

//有结点尾插
int Tail_Insert(LinkList L){
    L->next = NULL;
    Lnode *p;
    int a;
    scanf("%d",&a);
    while(a != 0){//以0结束为例
        p = (Lnode*)malloc(sizeof(Lnode));
        p->data = a; 
        p->next = L->next;
        L->next = p;
        scanf("%d",&a);
    }
    //遍历测试
    Lnode *q=L->next;
    while(q!=NULL){
        printf("%d ",q->data);
        q = q->next;
    }
    return 1;
}

//无结点尾插
int Tail_Insert_without(LinkList *L){
//注：需要不断重新定位L，也就是说改变L本身 要传址
    (*L)->next = NULL;
    Lnode *p;
    int a;
    scanf("%d",&a);
    while(a != 0){//以0结束为例
        p = (Lnode*)malloc(sizeof(Lnode));
        p->data = a; 
        p->next = *L;
        *L = p;
        scanf("%d",&a);
    }
    //遍历测试
    Lnode *q=*L;
    while(q!=NULL){
        printf("%d ",q->data);
        q = q->next;
    }
    return 1;
}

//测试主函数
int main(){
    Lnode *head = (Lnode*)malloc(sizeof(Lnode));
    Tail_Insert(head);
}