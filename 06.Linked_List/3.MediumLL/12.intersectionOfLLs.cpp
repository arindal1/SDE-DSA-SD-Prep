#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;

    while (temp1 != temp2) {
        temp1 = (temp1 == nullptr) ? headB : temp1->next;
        temp2 = (temp2 == nullptr) ? headA : temp2->next;
    }
    return temp1;  // intersection node or nullptr
}

// Utility: build list from vector
ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* tail = head;
    for (int i = 1; i < vals.size(); i++) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
    }
    return head;
}

// Utility: print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

// Example demo
int main() {
    // Creating intersection manually:
    // A: 4 -> 1 -> 8 -> 4 -> 5
    // B:      5 -> 6 -> 1 ↘
    //                      8 -> 4 -> 5

    ListNode* common = buildList({8, 4, 5});

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->val << "\n";
    else
        cout << "No intersection.\n";

    return 0;
}
