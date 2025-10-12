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

Node* InsertK (Node* head, int val, int k) {
    if (head == nullptr) {
        Node* newNode = new Node (val);
        return newNode;
    }

    Node* temp = head;
    Node* prev = nullptr;

    if (k == 1) {
        
    }

    int cnt = 0;
    while (temp) {
        cnt++;
        if (cnt == k) {
            temp->next = front;
            temp->back = prev;
        }
        temp = temp->next;
    }
    prev = temp->back;
    Node* newNode = new Node (val, temp, prev);
    temp->back = newNode;

    return head;
}

int main() {
    vector<int> arr = {12, 22, 24, 14, 5};
    int val = 777, k = 2;

    Node* head = Arr2LL (arr);

    PrintLL(head);

    head = InsertK(head, val), k;
    cout << "\n";

    PrintLL(head);
}