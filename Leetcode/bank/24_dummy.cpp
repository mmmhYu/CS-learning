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

        ListNode dummy,*p,*q,*pre;
        dummy.next = head;
        pre = &dummy;

        while(pre->next && pre->next->next){
            p = pre->next;
            q = p->next;
            pre->next = q;

            p->next = q->next;
            q->next = p;

            pre = p;
        }

        return dummy.next;
    }
};