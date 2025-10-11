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

Node* insertHead(Node* head, int val) {
    Node* temp = new Node (val, head);
    return temp;
}

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

void printLL (Node* head) {
    Node* temp = head;

    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    vector<int> arr = {12, 51, 22, 31, 7};
    int val = 3;

    Node* head = Ar2LL(arr);
    
    printLL(head);

    head = insertHead(head, val);

    cout << "\n";

    printLL(head);
}