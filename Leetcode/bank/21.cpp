struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy,*p = &dummy;

        if((!list1) && (!list2))
            return nullptr;

        while(list1 && list2){
            if(list1->val <= list2->val){
                p->next = list1;
                list1 = list1->next;
                p = p->next;

            }
            else{
                p->next = list2;
                list2 = list2->next;
                p = p->next;
            }
        }
        
        if(list1){
            p->next = list1;
            list1 = list1->next;
            p = p->next;
        }
        else{
            p->next = list2;
            list2 = list2->next;
            p = p->next;
        }

        return dummy.next;
    }
};