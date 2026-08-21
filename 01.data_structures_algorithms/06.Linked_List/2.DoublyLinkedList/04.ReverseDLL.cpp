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

Node* ReverseStack (Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    stack<int> st;
    Node* temp = head;

    while (temp) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

Node* ReverseSwap (Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* temp = head;
    Node* prev = nullptr;

    while (temp) {
        prev = temp->back;

        temp->back = temp->next;
        temp->next = prev;

        temp = temp->back;
    }

    return prev->back;
}

int main() {
    vector<int> arr = {12, 22, 24, 14, 5};

    Node* head = Arr2LL (arr);

    PrintLL(head);

    head = ReverseSwap(head);
    cout << "\n";

    PrintLL(head);
}