#include"../LinkList.h"

#define min(a,b) a >= b ? b : a

LinkList Merge(LinkList A,LinkList B){
    LNode *head = NULL,*p = A->next,*q = B->next,*next;

    free(B);

    while(p && q){
        if(p->val >= q->val){
            next = q->next;
            q->next = head;
            head = q;
            q = next;
        }
        else{
            next = p->next;
            p->next = head;
            head = p;
            p = next;
        }
    }

    while(p){
        next = p->next;
        p->next = head;
        head = p;
        p = next;
    }

    while(q){
        next = q->next;
        q->next = head;
        head = q;
        q = next;
    }

    A->next = head;

    return A;
}

LinkList CreateList(int arr[], int n)
{
    LinkList head = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;

    LNode *tail = head;

    for(int i = 0; i < n; i++){
        LNode *node = (LNode*)malloc(sizeof(LNode));

        node->val = arr[i];
        node->next = NULL;

        tail->next = node;
        tail = node;
    }

    return head;
}


void PrintList(LinkList L)
{
    LNode *p = L->next;

    while(p){
        printf("%d ", p->val);
        p = p->next;
    }

    printf("\n");
}


int main()
{
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 3, 4, 7, 10};

    LinkList A = CreateList(a, 5);
    LinkList B = CreateList(b, 5);

    printf("Before:\n");

    printf("A: ");
    PrintList(A);

    printf("B: ");
    PrintList(B);

    LinkList C = Merge(A, B);

    printf("\nAfter:\n");

    printf("C: ");
    PrintList(C);

    return 0;
}