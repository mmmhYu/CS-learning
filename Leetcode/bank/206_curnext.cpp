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

        return sup(nullptr,head);

    }

    ListNode* sup(ListNode* cur,ListNode* next){
        if(!next)
            return cur;

        ListNode *p = next->next;
        next->next = cur;

        return sup(next,p);
    }
};