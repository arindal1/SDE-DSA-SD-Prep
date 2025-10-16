#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        // Move fast (2x) and slow (1x)
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 'slow' now points to middle, 'prev' is before middle
        prev->next = slow->next;
        delete slow; // free memory

        return head;
    }
};

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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ListNode* head = buildList(a);

    Solution sol;
    head = sol.deleteMiddle(head);

    printList(head);
    freeList(head);
    return 0;
}