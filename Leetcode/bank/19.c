#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p,*q;
    int num=0,tar,i=1;
    p = head;
    while(p!=NULL){
        q = p;
        p = p->next;
        num++;
    }
    if(n == 1){
        q = NULL;
        free(q->next);
    }
    p = head;
    tar = num-n+1;
    while(i<tar-1){
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    p = head;
    return head;
}
// ---------------------- 辅助函数：创建新节点 ----------------------
struct ListNode* createNode(int val) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
// ---------------------- 辅助函数：尾部插入节点 ----------------------
struct ListNode* insertAtTail(struct ListNode *head, int val) {
    struct ListNode *newNode = createNode(val);
    if (head == NULL) {
        return newNode;
    }
    struct ListNode *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// ---------------------- 辅助函数：打印链表 ----------------------
void printList(struct ListNode *head) {
    struct ListNode *current = head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

// ---------------------- 辅助函数：释放链表内存 ----------------------
void freeList(struct ListNode *head) {
    struct ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// ---------------------- 测试主函数 ----------------------
int main() {
    // 测试用例1：题目示例
    struct ListNode *head1 = NULL;
    head1 = insertAtTail(head1, 1);
    head1 = insertAtTail(head1, 2);
    head1 = insertAtTail(head1, 3);
    head1 = insertAtTail(head1, 4);
    head1 = insertAtTail(head1, 5);
    
    printf("原链表1：");
    printList(head1);
    head1 = removeNthFromEnd(head1, 2);
    printf("删除倒数第2个节点后：");
    printList(head1);  // 预期输出：[1, 2, 3, 5]
    freeList(head1);
    
    // 测试用例2：删除头节点（链表长度为1）
    struct ListNode *head2 = createNode(1);
    printf("\n原链表2：");
    printList(head2);
    head2 = removeNthFromEnd(head2, 1);
    printf("删除倒数第1个节点后：");
    printList(head2);  // 预期输出：[]
    freeList(head2);
    
    // 测试用例3：删除头节点（链表长度为2）
    struct ListNode *head3 = NULL;
    head3 = insertAtTail(head3, 1);
    head3 = insertAtTail(head3, 2);
    printf("\n原链表3：");
    printList(head3);
    head3 = removeNthFromEnd(head3, 2);
    printf("删除倒数第2个节点后：");
    printList(head3);  // 预期输出：[2]
    freeList(head3);
    
    return 0;
}