#include<stdio.h>
//定义链表
struct link_list
{
    int num;
    struct link_list *next;
};
int main(){
    struct link_list a,b,c,*head=&a,*p=head;
    int i=1;
    a.num=1001;
    b.num=1002;
    c.num=1003;
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    while(p!=NULL){
        printf("第%d次结果为%d\n",i,p->num);
        p=p->next;
        i++;
    }
}