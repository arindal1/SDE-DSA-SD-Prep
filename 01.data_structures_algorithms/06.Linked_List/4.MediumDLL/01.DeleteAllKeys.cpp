#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* Arr2LL(const vector<int> &arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (size_t i = 1; i < arr.size(); ++i) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void PrintLL(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "  ";
        head = head->next;
    }
    cout << "\n";
}

Node* RemoveKs(Node* head, int key) {
    Node* temp = head;

    while (temp != nullptr) {
        Node* nxt = temp->next;

        if (temp->data == key) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }

            delete temp;
        }

        temp = nxt;
    }

    return head;
}

int main() {
    vector<int> arr = {12, 22, 24, 14, 22, 5};
    int key = 22;

    Node* head = Arr2LL(arr);

    Node* newhead = RemoveKs(head, key);

    PrintLL(newhead);

    // free remaining nodes to avoid leak
    while (newhead) {
        Node* nxt = newhead->next;
        delete newhead;
        newhead = nxt;
    }

    return 0;
}
