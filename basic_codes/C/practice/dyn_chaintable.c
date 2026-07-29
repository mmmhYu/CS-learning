#include<stdio.h>
#include<stdlib.h>
struct dyn_chaintable
{
    int num;
    struct dyn_chaintable *next;
};



int main(){
    struct dyn_chaintable *head,*tail,*p;
    int stuno;
    head=NULL;
    tail=NULL;
    scanf("%d",&stuno);
    while(stuno!=0){
        p=(struct dyn_chaintable*)malloc(sizeof(struct dyn_chaintable));
        p->num=stuno;
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            tail->next=p;
        tail=p;
        scanf("%d",&stuno);
    }
    p=head;
    while(p!=NULL){
        printf("%d ",p->num);
        p=p->next;
    }
}
