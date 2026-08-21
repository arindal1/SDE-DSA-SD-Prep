#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int countLength(ListNode* meetingNode) {
    int length = 1;
    ListNode* temp = meetingNode->next;

    while (temp != meetingNode) {
        length++;
        temp = temp->next;
    }
    return length;
}

int countCycleLength(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return 0;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return countLength(slow);
        }
    }
    return 0;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create cycle: tail connects to node 2
    head->next->next->next->next->next = head->next;

    int len = countCycleLength(head);
    if (len)
        cout << "Cycle length: " << len << " ✅" << endl;
    else
        cout << "No cycle detected ❌" << endl;

    return 0;
}
