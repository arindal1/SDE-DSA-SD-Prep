#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x=0): val(x), next(nullptr) {}
};

// Reverse a linked list and return new head.
ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur  = head;
    while (cur != nullptr) {
        ListNode* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// Returns the last node of the first half (for even and odd length lists).
ListNode* endOfFirstHalf(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    // Move fast by 2 and slow by 1. Stop when fast reaches end.
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;

    // 1. Find end of first half
    ListNode* firstHalfEnd = endOfFirstHalf(head);

    // 2. Reverse second half
    ListNode* secondHalfStart = reverseLinkedList(firstHalfEnd->next);

    // 3. Compare first half and reversed second half
    ListNode* p1 = head;
    ListNode* p2 = secondHalfStart;
    bool result = true;
    while (p2 != nullptr) {           // only need to compare length of second half
        if (p1->val != p2->val) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 4. Restore the list (reverse the second half again and attach)
    firstHalfEnd->next = reverseLinkedList(secondHalfStart);

    return result;
}

// --- Helper functions for testing ---
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

void freeList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {
        {},                // empty
        {1},               // single
        {1,2},             // not palindrome
        {1,2,1},           // odd palindrome
        {1,2,2,1},         // even palindrome
        {1,2,3,2,1},       // odd palindrome
        {1,2,3,4,2,1},     // not palindrome
    };

    for (auto &t : tests) {
        ListNode* head = buildList(t);
        cout << "List: ";
        printList(head);
        cout << "Is palindrome? " << (isPalindrome(head) ? "Yes" : "No") << '\n';
        cout << "After check, list restored: ";
        printList(head);
        cout << "-----------------------------\n";
        freeList(head);
    }

    // Interactive test (optional)
    /*
    int n;
    if (cin >> n) {
        vector<int> vals(n);
        for (int i = 0; i < n; ++i) cin >> vals[i];
        ListNode* h = buildList(vals);
        cout << (isPalindrome(h) ? "Palindrome\n" : "Not palindrome\n");
        printList(h); // restored
        freeList(h);
    }
    */

    return 0;
}
