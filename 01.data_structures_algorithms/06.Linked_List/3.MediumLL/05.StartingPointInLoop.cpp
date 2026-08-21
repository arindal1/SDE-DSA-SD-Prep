#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    // Detect cycle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // Find start node
    if (slow == fast) {
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return nullptr;
}

int main() {
    // Create linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle: tail connects to node 2
    head->next->next->next->next = head->next;

    ListNode* cycleNode = detectCycle(head);
    if (cycleNode)
        cout << "Cycle starts at node with value: " << cycleNode->val << " ✅" << endl;
    else
        cout << "No cycle detected ❌" << endl;

    return 0;
}
