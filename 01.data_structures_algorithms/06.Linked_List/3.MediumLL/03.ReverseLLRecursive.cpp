/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base condition — if list is empty or has only one node
        if (head == nullptr || head->next == nullptr)
            return head;

        // Step 1: Recurse for the remaining list
        ListNode* newHead = reverseList(head->next);

        // Step 2: Adjust the links
        ListNode* front = head->next;
        front->next = head;

        // Step 3: Mark the current node as the new tail
        head->next = nullptr;

        // Step 4: Return new head
        return newHead;
    }
};
