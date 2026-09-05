#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast,*slow;
    fast = slow = head;
    if(!fast || !fast->next)
        return NULL;
    fast = fast->next->next;
    slow = slow->next;
    while(fast && fast->next && fast!=slow){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(!fast || !fast->next)
        return NULL;
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

int main()
{
    // 创建节点
    struct ListNode *node1 = malloc(sizeof(struct ListNode));
    struct ListNode *node2 = malloc(sizeof(struct ListNode));
    struct ListNode *node3 = malloc(sizeof(struct ListNode));
    struct ListNode *node4 = malloc(sizeof(struct ListNode));
    struct ListNode *node5 = malloc(sizeof(struct ListNode));

    node1->val = 3;
    node2->val = 2;
    node3->val = 0;
    node4->val = -4;
    node5->val = 5;

    // 构造环：
    // 3 -> 2 -> 0 -> -4
    //      ↑       ↓
    //      ---------
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    node5->next = NULL; // 未使用

    struct ListNode *res = detectCycle(node1);

    if(res)
        printf("Cycle starts at node value: %d\n", res->val);
    else
        printf("No cycle\n");

    free(node5);
    
    return 0;
}