#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    public:
    Node (int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node (int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* Ar2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int searchLL (Node* head, int val) {
    Node* temp = head;

    while (temp) {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    int val = 1;

    Node* head = Ar2LL (arr);
    cout << searchLL(head, val);
}