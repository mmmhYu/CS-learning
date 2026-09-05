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
        ListNode *cur = nullptr,*next = head;

        while(next){
            ListNode *p = next->next;

            next->next = cur;
            cur = next;
            next = p;
        }

        return cur;

    }
};