#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *helper(struct ListNode *prev,struct ListNode *cur){
    struct ListNode *tmp;
    if(!cur)
        return prev;
    tmp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = tmp;
    return helper(prev,cur);
}

struct ListNode* reverseList(struct ListNode* head){
    return  helper(NULL,head);
}


/*struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *cur = head,*prev = NULL,*temp;
    while(cur != NULL){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}*/

struct ListNode* createNode(int val) {
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 尾插构建链表
struct ListNode* buildList(int arr[], int len) {
    if (len == 0) return NULL;
    struct ListNode *head = createNode(arr[0]);
    struct ListNode *p = head;
    for (int i = 1; i < len; i++) {
        p->next = createNode(arr[i]);
        p = p->next;
    }
    return head;
}

// 打印链表
void printList(struct ListNode *head) {
    struct ListNode *p = head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

// 释放链表内存
void freeList(struct ListNode *head) {
    struct ListNode *p = head, *tmp;
    while (p != NULL) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

// 主函数测试入口
int main() {
    int arr1[] = {1,2,3,6,7,8};
    int len1 = sizeof(arr1)/sizeof(int);
    struct ListNode *h1 = buildList(arr1, len1);
    printf("原链表：");
    printList(h1);
    struct ListNode *rev1 = reverseList(h1);
    printf("反转后：");
    printList(rev1);
    freeList(rev1);
    printf("------------------------\n");
}