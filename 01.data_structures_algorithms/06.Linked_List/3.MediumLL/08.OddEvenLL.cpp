#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x=0): val(x), next(nullptr) {}
};

// Reorders list: odd-position nodes first, then even-position nodes.
// Example: 1->2->3->4->5  => 1->3->5->2->4
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* oddTail = head;            // tail of odd-indexed nodes
    ListNode* evenHead = head->next;     // head of even-indexed nodes (to attach later)
    ListNode* evenTail = evenHead;       // tail of even-indexed nodes

    while (evenTail && evenTail->next) {
        // Connect next odd
        oddTail->next = evenTail->next;
        oddTail = oddTail->next;

        // Connect next even
        evenTail->next = oddTail->next;
        evenTail = evenTail->next;
    }

    // Attach even list after odd list
    oddTail->next = evenHead;
    return head;
}

// Helper: build linked list from vector
ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* tail = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
    }
    return head;
}

// Helper: print linked list
void printList(ListNode* head) {
    bool first = true;
    while (head) {
        if (!first) cout << " ";
        cout << head->val;
        first = false;
        head = head->next;
    }
    cout << "\n";
}

// Helper: free nodes
void freeList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];

    ListNode* head = buildList(vals);
    head = oddEvenList(head);
    printList(head);
    freeList(head);
    return 0;
}
