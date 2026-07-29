#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
 };

/*struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *rl=(struct ListNode*)malloc(sizeof(struct ListNode)),*l1,*l2,*p=rl;
    l1 = list1;
    l2 = list2;
    if(l1==NULL && l2==NULL){
        return NULL;
    }
    while(l1!=NULL || l2!=NULL){
        if(l1 == NULL){
            while(l2!=NULL){
                p->val = l2->val;
                l2 = l2->next;
                if(l2 == NULL){
                    p->next = NULL;
                    break;
                }
                    
                p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = p->next;
            }
            
            break;
        }
        else if(l2 == NULL){
            while(l1!=NULL){
                p->val = l1->val;
                l1 = l1->next;
                if(l1 == NULL){
                    p->next = NULL;
                    break;
                }
                p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = p->next;
            }
            break;
        }
        if(l1->val <= l2->val){
            p->val = l1->val;
            l1 = l1->next;
        }
        else{
            p->val = l2->val;
            l2 = l2->next;
        }
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = p->next;
    }
    p = NULL;
    return rl;
}*/

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy,*l1,*l2,*p = &dummy,*q;
    l1 = list1;
    l2 = list2;
    dummy.next = NULL;
    while(l1!=NULL && l2!=NULL){
        q = malloc(sizeof(struct ListNode));
        if(l1->val <= l2->val){
            q->val = l1->val;
            q->next = NULL;
            l1 = l1->next;
        }
        else{
            q->val = l2->val;
            q->next = NULL;
            l2 = l2->next;
        }
        p->next = q;
        p = q;
    }    
    p->next = l1?l1:l2;
    return dummy.next;
}


// ------------------- 工具函数 -------------------
// 新建节点
struct ListNode* createNode(int val) {
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 打印链表
void printList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    // 测试用例 1
    // list1: 1 -> 2 -> 4
    // list2: 1 -> 3 -> 4
    struct ListNode *list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);

    struct ListNode *list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    printf("list1: ");
    printList(list1);
    printf("list2: ");
    printList(list2);

    // 合并
    struct ListNode *merged = mergeTwoLists(list1, list2);
    printf("合并后: ");
    struct ListNode *p = merged;
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }

    return 0;
}
