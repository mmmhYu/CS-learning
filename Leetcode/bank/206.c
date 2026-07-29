#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*//尝试头插
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p = head,*q,*h = NULL;
    while(p != NULL){
        q = malloc(sizeof(struct ListNode));
        q->val = p->val;
        q->next = h;
        h = q;
        p = p->next;
    }
    return h;
}*/

//递归算法
/*struct ListNode* reverseList(struct ListNode* head,struct ListNode* n){
    if(!head)
        return head;
    head = head->next;
    n = head->next;
    return reverseList(head,n);
    struct ListNode *p;
    p = malloc(sizeof(struct ListNode));
    p->val = head->val;
    p->next = n;
}*/

/*错误：
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *cur = head;
    struct ListNode *rev = NULL,*temp;
    while(cur != NULL){
        printf("%d\n",cur->val);
        temp = rev;
        rev = cur;
        rev->next = temp;
        cur = cur->next;
    }
    return rev;
}*/

//正确cur（自创）：
/*struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *cur = head;
    struct ListNode *rev = NULL,*temp;
    while(cur != NULL){
        temp = cur;
        cur = cur->next;
        temp->next = rev;
        rev = temp;
    }
    return rev;
}*/

//标准prev cur：
/*struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *cur = head;
    struct ListNode *prev = NULL,*temp;
    while(cur != NULL){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}*/
//犯错的原因（只有一个元素1了）：
//没有保存当前节点，直接把第一个节点next指向NULL了 导致循环做了一次就结束了

//尝试一下递归
/*struct ListNode *helper(struct ListNode *prev,struct ListNode *cur){
    if(cur == NULL){
        return prev;
    }
    struct ListNode *next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
    return helper(prev,cur);
}
struct ListNode* reverseList(struct ListNode* head){
    return helper(NULL,head);
}*/

//更为巧妙的递归
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = head->next,*temp;
    if(prev != NULL){   
        return reverseList(prev);
        prev->next = head;
    }
    return prev;
}

/*
if(cur == NULL)
    return prev;
temp = cur->next;
cur->next = prev;
prev = cur;
cur = next;
return helper(prev,cur);
*/

//数组
/*struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *rev = NULL,*tail = NULL,*p = head,*q;
    int a[20],i = 0;
    while(p != NULL){
        a[i++] = p->val;
        p = p->next;
    }
    
    if(i == 0)
        return NULL;
    else{
        while(i>0){
            q = malloc(sizeof(struct ListNode*));
            q->val = a[--i];
            q->next = NULL;
            if(rev == NULL){
                rev = q;
            }
            else{
                tail->next = q;
            }
            tail = q;
        }
    }
    return rev;
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




