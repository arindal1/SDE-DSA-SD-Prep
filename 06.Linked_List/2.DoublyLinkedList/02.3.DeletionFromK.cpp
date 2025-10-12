#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node (int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node (int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* Arr2LL (vector<int> &arr) {
    Node* head = new Node (arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node (arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void PrintLL (Node* head) {
    while (head) {
        cout << head->data << "  ";
        head = head->next;
    }
    cout << "\n";
}

Node* DeleteK (Node* head, int k) {
    Node* temp = head;
    Node* prev = nullptr;
    Node* front = nullptr;

    int cnt = 0;
    while (temp != nullptr) {
        cnt++;
        if (cnt == k) {
            break;
        }
        temp = temp->next;
    }
    prev = temp->back;
    front = temp->next;

    if (prev == nullptr && front == nullptr) {
        delete temp;
        return nullptr;
    } else if (prev == nullptr) {
        temp->next = nullptr;
        front->back = nullptr;
        delete temp;
        delete prev;
        return front;
    } else if (front == nullptr) {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        delete front;
    } else {
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }

    return head;
}

int main() {
    vector<int> arr = {12, 22, 24, 14, 5};
    int k = 1;

    Node* head = Arr2LL (arr);

    PrintLL(head);

    head = DeleteK(head, k);
    cout << "\n";

    PrintLL(head);
}