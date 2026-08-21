#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x=0) : val(x), next(nullptr) {}
};

// Remove nth node from end (1 <= n). Returns new head.
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return nullptr;

    // Dummy simplifies deleting head node
    ListNode dummy(0);
    dummy.next = head;
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    // Move fast n steps forward (from dummy -> moves n times lands n nodes ahead of dummy)
    for (int i = 0; i < n; ++i) {
        if (fast->next == nullptr) {
            // n is larger than length; invalid input.
            // Option A: return original list unchanged.
            // Option B: treat as delete head: here we return head unchanged.
            return head;
        }
        fast = fast->next;
    }

    // Now move both until fast is at the last node
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow->next is the node to delete
    ListNode* nodeToDelete = slow->next;
    slow->next = nodeToDelete->next;
    delete nodeToDelete;

    return dummy.next;
}

// ----------- Helpers for testing ----------
ListNode* buildList(const vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int x : v) {
        ListNode* node = new ListNode(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

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

void freeList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

// Example interactive main
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;              // number of nodes
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    int k;                                  // n-th from end to remove
    cin >> k;

    ListNode* head = buildList(vals);
    head = removeNthFromEnd(head, k);
    printList(head);
    freeList(head);
    return 0;
}
