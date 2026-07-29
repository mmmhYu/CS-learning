/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 #include<stdio.h>
 #include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p,*q,*r,*t;
    int len=0;
    p = head;
    while(p!=NULL){
        len++;
        p = p->next;
    }
    if(len<=1)
        return head;
    p = head;
    q = head->next;
    r = q;
    len/=2;
    if(len == 1){
        p->next = q->next;
        q->next = p;
        return r;
    }
    for(int i=0;i<len-1;i++){
        p->next = q->next;
        q->next = p;
        if(i!=0)
            t->next = q;
        t = p;
        p = p->next;
        q = p->next;
    }
    p->next = q->next;
    q->next = p;
    t->next = q;
    return r;
}

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// ==================== 辅助函数：打印链表 ====================
void printList(struct ListNode* head) {
    struct ListNode* p = head;
    while(p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

// ==================== 主函数：测试 ====================
int main() {
    // 创建链表 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("原链表：");
    printList(head);

    // 调用交换函数
    struct ListNode* newHead = swapPairs(head);

    printf("交换后：");
    printList(newHead);

    return 0;
}