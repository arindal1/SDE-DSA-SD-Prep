
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* temp = head;
        int len = 1;
        while (temp->next != nullptr) {
            len++;
            temp = temp->next;
        }
        temp->next = head;
        k = k % len;
        int end = len - k;

        while (end--)
            temp = temp->next;

        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};