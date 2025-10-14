#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ListNode* node = new ListNode(x);
        if (!head) { head = tail = node; }
        else { tail->next = node; tail = node; }
    }

    ListNode* mid = middleNode(head);
    if (!mid) cout << "List is empty\n";
    else cout << "Middle node value: " << mid->val << "\n";

    // cleanup: free nodes
    ListNode* cur = head;
    while (cur) {
        ListNode* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    return 0;
}
