#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ha = headA,*hb;
    while(ha != NULL){
        hb = headB;
        while(hb != NULL){
            if(hb == ha)
                return hb;
            hb = hb->next;
        }
        ha = ha->next;
    }
    return NULL;
}*/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
    struct ListNode *ha = headA,*hb = headB;
    while(ha != hb){
        if(ha == NULL)
            ha = headB;
        else
            ha = ha->next;
        if(hb == NULL)
            hb = headA;
        else
            hb = hb->next;
    }
    if(ha == NULL && hb == NULL)
        return NULL;
    return ha;
}

struct ListNode* newNode(int val) {
    struct ListNode *n = malloc(sizeof(struct ListNode));
    n->val = val;
    n->next = NULL;
    return n;
}

// 打印链表（辅助看结构）
void printList(struct ListNode *h) {
    while(h) {
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}

int main() {
    // 构造公共相交部分：8 -> 9
    struct ListNode *c1 = newNode(8);
    struct ListNode *c2 = newNode(9);
    c1->next = c2;

    // 链表A：1 -> 2 -> 8 -> 9
    struct ListNode *a1 = newNode(1);
    struct ListNode *a2 = newNode(2);
    a1->next = a2;
    a2->next = c1;

    // 链表B：3 -> 5 -> 8 -> 9
    struct ListNode *b1 = newNode(3);
    struct ListNode *b2 = newNode(5);
    b1->next = b2;
    b2->next = c1;

    printf("链表A：");
    printList(a1);
    printf("链表B：");
    printList(b1);

    // 调用函数找交点
    struct ListNode *res = getIntersectionNode(a1, b1);
    if(res)
        printf("相交节点值 = %d\n", res->val);
    else
        printf("无交点\n");




    return 0;
}