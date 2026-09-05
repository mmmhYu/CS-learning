struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head){
        if((!head) || !(head->next))
            return head;

        ListNode *p = head,*ans = head->next;

        ListNode *q = p->next;
        p->next = q->next;
        q->next = p;

        while(p->next && p->next->next){
            q = p->next->next;
            p->next->next = q->next;
            q->next = p->next;
            p->next = q;

            p = q->next;
        }

        return ans;
    }
};