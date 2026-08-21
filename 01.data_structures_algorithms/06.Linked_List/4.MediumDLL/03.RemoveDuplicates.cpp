#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

public:
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* Arr2LL(vector<int> &arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); ++i) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void PrintLL(Node* head) {
    Node* temp = head;

    while (temp) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " <-> ";
        temp = temp->next;
    }
    cout << "\n";
}

Node* deleteDuplicates(Node* head) {
    if (head == nullptr)
        return head;

    Node* temp = head;

    while (temp != nullptr && temp->next != nullptr) {
        Node* front = temp->next;

        while (front != nullptr && front->data == temp->data) {
            Node* del = front;
            front = front->next;
            delete del;
        }

        temp->next = front;
        if (front != nullptr)
            front->prev = temp;
        temp = temp->next;
    }
    
    return head;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5};

    Node* head = Arr2LL(arr);
    PrintLL(head);

    head = deleteDuplicates(head);
    PrintLL(head);
}