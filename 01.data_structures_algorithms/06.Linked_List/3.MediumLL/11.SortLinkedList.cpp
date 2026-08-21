#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

// Merge two sorted lists and return head of merged list
ListNode* mergeList(ListNode* list1, ListNode* list2) {
    ListNode dummy(-1);
    ListNode* tail = &dummy;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = (list1 ? list1 : list2);
    return dummy.next;
}

// Top-down merge sort for linked list
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    // Find middle (slow/fast) and previous pointer to cut
    ListNode* midPrev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        midPrev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // split into two lists: head..midPrev and slow..end
    midPrev->next = nullptr;

    ListNode* left = sortList(head);
    ListNode* right = sortList(slow);

    return mergeList(left, right);
}

// Helpers for testing
ListNode* buildList(const vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int x : v) {
        ListNode* node = new ListNode(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ListNode* head = buildList(a);
    head = sortList(head);
    printList(head);
    freeList(head);
    return 0;
}
