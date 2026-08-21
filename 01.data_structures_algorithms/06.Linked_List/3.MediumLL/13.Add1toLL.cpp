#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = nullptr;
    ListNode* front = nullptr;

    while (temp != nullptr) {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

ListNode* addition(ListNode* head) {
    head = reverseList(head);

    ListNode* temp = head;
    int carry = 1;

    while (temp && carry) {
        int sum = temp->val + carry;
        temp->val = sum % 10;
        carry = sum / 10;

        if (!temp->next && carry) {
            temp->next = new ListNode(carry);
            carry = 0;
        }
        temp = temp->next;
    }
    head = reverseList(head);
    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = addition(head);

    printList(head);
}
