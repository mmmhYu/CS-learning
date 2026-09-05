#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode *p = (ListNode*)malloc(sizeof(ListNode));
        p = head;
        ListNode *tail = nullptr;

        while(p){
            ListNode *q = (ListNode*)malloc(sizeof(ListNode));
            q = p->next;
            p->next = tail;
            tail = p;
            p = q;
        }

        return tail;
    }

};