#include"../LinkList.h"

//有头结点的写法
LinkList DeleteCommon(LinkList A,LinkList B,LinkList C){
    LNode *pre = A,*a = A->next,*b = B->next,*c = C->next;

    while(a && b && c){
        while(b && c && (b->val != c->val)){
            if(b->val < c->val)
                b = b->next;
            else
                c = c->next;
        }

        if((!b) || (!c))
            return A;
        else{
            int val = b->val;
            b = b->next;
            c = c->next;

            while(a && a->val < val){
                pre = a;
                a = a->next;
            }
                
            if(!a)
                return A;
            else if(a->val > val)
                continue;
            else{
                pre->next = a->next;
                free(a);
                a = pre->next;
            }
        }
    }

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
    LinkList A = InitList();
    LinkList B = InitList();
    LinkList C = InitList();

    // A: 1 -> 10
    InsertElem(A, 1, 1);
    InsertElem(A, 2, 10);

    // B: 5 -> 10
    InsertElem(B, 1, 5);
    InsertElem(B, 2, 10);

    // C: 5 -> 10
    InsertElem(C, 1, 5);
    InsertElem(C, 2, 10);

    printf("Before:\n");

    printf("A: ");
    print_List(A);
    printf("\n");

    printf("B: ");
    print_List(B);
    printf("\n");

    printf("C: ");
    print_List(C);
    printf("\n");

    DeleteCommon(A, B, C);

    printf("\nAfter:\n");

    printf("A: ");
    print_List(A);
    printf("\n");

    return 0;
}