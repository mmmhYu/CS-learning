#include"LinkList.h"

LNode* reverse(LinkList head){
    LNode *pre = NULL, *cur = head->next;

    if((!head) || !(head->next))
        return NULL;
 
    while(cur){
        LNode *next = cur->next;
        cur->next = pre;

        pre = cur;
        cur = next;
    }

    head->next = pre;
    return head;
}