class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dum = new ListNode(-1);
        ListNode* temp = dum;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            } else {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
        }

        if (list1 != nullptr)
            temp->next = list1;
        else temp->next = list2;
        
        return dum->next;
    }
};