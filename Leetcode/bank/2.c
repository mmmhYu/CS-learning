#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int i,j,carry=0,k,temp;
    struct ListNode *p,*q,*head=NULL,*tail=NULL,*add;
    p=l1;
    while(p!=NULL){
        i++;
        p=p->next;
    }
    p=l2;
    while(p!=NULL){
        j++;
        p=p->next;
    }

    if(i>j){
        for(k=1;k<=j;k++){
            add=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp=l1->val+l2->val;
            add->val=temp%10+carry;
            add->next=NULL;
            carry=temp/10;
            if(head==NULL)
                head=add;
            else
                tail->next=add;
            tail=add;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            add=(struct ListNode*)malloc(sizeof(struct ListNode));
            add->val=l1->val;
            add->next=NULL;
            l1=l1->next;
            tail->next=add;
            tail=add;
        }
    }
    if(i<=j){
        for(k=1;k<=i;k++){
            add=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp=l1->val+l2->val;
            add->val=temp%10+carry;
            add->next=NULL;
            carry=temp/10;
            if(head==NULL)
                head=add;
            else
                tail->next=add;
            tail=add;
            l1=l1->next;
            l2=l2->next;
        }
        while(l2!=NULL){
            add=(struct ListNode*)malloc(sizeof(struct ListNode));
            add->val=l2->val;
            add->next=NULL;
            l2=l2->next;
            tail->next=add;
            tail=add;
        }
    }
    if(carry>0){
        add=(struct ListNode*)malloc(sizeof(struct ListNode));
        add->val=1;
        add->next=NULL;
        tail->next=add;
        tail=add;
    }
    return head;
}