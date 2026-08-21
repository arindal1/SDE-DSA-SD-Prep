#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string url;
    Node* next;
    Node* prev;

    Node(const string &url1, Node* next1 = nullptr, Node* prev1 = nullptr)
        : url(url1), next(next1), prev(prev1) {}
};

class Browser {
    Node* currentPage;

    // Helper: delete forward list starting at 'start' (inclusive).
    // It will unlink nodes and free memory.
    void deleteForward(Node* start) {
        Node* cur = start;
        while (cur) {
            Node* nx = cur->next;
            delete cur;
            cur = nx;
        }
    }

    // Helper: go to the head (first node) from current
    Node* goToHead() const {
        Node* p = currentPage;
        while (p && p->prev) p = p->prev;
        return p;
    }

public:
    // Construct browser with a home page
    Browser(const string &home) {
        currentPage = new Node(home);
    }

    // Destructor: free whole list
    ~Browser() {
        // Move to head, then delete forward
        Node* head = goToHead();
        deleteForward(head);
    }

    // Visit a site: clear forward history, append new node, move current
    void visit(const string &site) {
        // 1) delete forward history (if any)
        if (currentPage->next != nullptr) {
            deleteForward(currentPage->next);
            currentPage->next = nullptr;
        }

        // 2) append new node and move current
        Node* newNode = new Node(site);
        currentPage->next = newNode;
        newNode->prev = currentPage;
        newNode->next = nullptr;
        currentPage = newNode;
    }

    // Move back up to 'steps' times. Return current URL.
    string back(int steps) {
        while (steps > 0 && currentPage->prev != nullptr) {
            currentPage = currentPage->prev;
            --steps;
        }
        return currentPage->url;
    }

    // Move forward up to 'steps' times. Return current URL.
    string forward(int steps) {
        while (steps > 0 && currentPage->next != nullptr) {
            currentPage = currentPage->next;
            --steps;
        }
        return currentPage->url;
    }

    // Optional: for debugging - print full history from head to tail
    void debugPrint() const {
        Node* head = goToHead();
        Node* p = head;
        bool first = true;
        while (p) {
            if (!first) cout << " <-> ";
            cout << p->url;
            first = false;
            p = p->next;
        }
        cout << "\n";
    }
};

// Example usage
int main() {
    string home = "leetcode.com";
    Browser browser(home);

    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");

    cout << browser.back(1) << endl;      // facebook.com
    cout << browser.back(1) << endl;      // google.com
    cout << browser.forward(1) << endl;   // facebook.com

    browser.visit("linkedin.com");
    cout << browser.forward(2) << endl;   // linkedin.com
    cout << browser.back(2) << endl;      // google.com
    cout << browser.back(7) << endl;      // leetcode.com

    return 0;
}
