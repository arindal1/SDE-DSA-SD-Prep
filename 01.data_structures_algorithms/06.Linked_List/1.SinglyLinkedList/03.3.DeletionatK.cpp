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

Node* deleteK (Node* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* temp = head;

    if (k == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

    Node* prev = NULL;
    int cnt = 0;
    while (temp != NULL) {
        cnt ++;
        if (cnt == k) {
            prev->next = prev->next->next;
            free (temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;

    return head;
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
    int k = 3;

    Node* head = Ar2LL(arr);
    
    printLL(head);

    head = deleteK(head, k);

    cout << "\n";

    printLL(head);
}