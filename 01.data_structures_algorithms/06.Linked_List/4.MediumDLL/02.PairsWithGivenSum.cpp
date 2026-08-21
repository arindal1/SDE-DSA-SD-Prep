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

// Build a doubly linked list from vector (head->...->tail).
Node* Arr2LL(const vector<int> &arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    head->prev = nullptr; // explicit
    Node* tail = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        Node* node = new Node(arr[i], nullptr, tail);
        tail->next = node;
        tail = node;
    }
    return head;
}

// Print result pairs: each pair on its own line
void PrintPairs(const vector<vector<int>> &res) {
    if (res.empty()) {
        cout << "No pairs found\n";
        return;
    }
    for (const auto &p : res) {
        if (p.size() == 2) cout << p[0] << " " << p[1] << "\n";
    }
}

vector<vector<int>> SumFind(Node* head, int target) {
    vector<vector<int>> res;
    if (!head) return res;

    Node* right = head;
    while (right->next) right = right->next;

    Node* left = head;

    while (left != right && left->prev != right) {
        int sum = left->data + right->data;
        if (sum == target) {
            res.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if (sum < target) {
            left = left->next;
        } else { // sum > target
            right = right->prev;
        }
    }
    return res;
}

void FreeList(Node* head) {
    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    vector<int> arr = {1, 2, 4, 5, 6, 8, 9};
    int target = 7;

    Node* head = Arr2LL(arr);

    vector<vector<int>> res = SumFind(head, target);

    PrintPairs(res);

    FreeList(head);
    return 0;
}
