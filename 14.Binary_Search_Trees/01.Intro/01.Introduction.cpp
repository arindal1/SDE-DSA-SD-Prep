// bst_reference.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root = nullptr;

    // Recursive insert
    Node* insertRec(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->val) node->left = insertRec(node->left, val);
        else if (val > node->val) node->right = insertRec(node->right, val);
        // if equal, ignoring duplicates. Adjust if duplicates allowed.
        return node;
    }
    void insert(int val) { root = insertRec(root, val); }

    // Iterative insert (alternative)
    void insertIter(int val) {
        if (!root) { root = new Node(val); return; }
        Node* cur = root;
        while (true) {
            if (val < cur->val) {
                if (!cur->left) { cur->left = new Node(val); return; }
                cur = cur->left;
            } else if (val > cur->val) {
                if (!cur->right) { cur->right = new Node(val); return; }
                cur = cur->right;
            } else {
                // duplicate - skip
                return;
            }
        }
    }

    // Search
    bool search(int val) { return searchRec(root, val); }
    bool searchRec(Node* node, int val) {
        if (!node) return false;
        if (node->val == val) return true;
        if (val < node->val) return searchRec(node->left, val);
        return searchRec(node->right, val);
    }

    // Find minimum node in subtree
    Node* minNode(Node* node) {
        if (!node) return nullptr;
        while (node->left) node = node->left;
        return node;
    }

    // Delete node
    Node* deleteRec(Node* node, int key) {
        if (!node) return nullptr;
        if (key < node->val) node->left = deleteRec(node->left, key);
        else if (key > node->val) node->right = deleteRec(node->right, key);
        else {
            // Found node to delete
            if (!node->left) {
                Node* r = node->right;
                delete node;
                return r;
            }
            else if (!node->right) {
                Node* l = node->left;
                delete node;
                return l;
            } else {
                // two children: replace with inorder successor
                Node* succ = minNode(node->right);
                node->val = succ->val;
                node->right = deleteRec(node->right, succ->val);
            }
        }
        return node;
    }
    void remove(int key) { root = deleteRec(root, key); }

    // Traversals
    void inorder(Node* node, vector<int>& out) {
        if (!node) return;
        inorder(node->left, out);
        out.push_back(node->val);
        inorder(node->right, out);
    }
    vector<int> inorder() {
        vector<int> out; inorder(root, out); return out;
    }

    void preorder(Node* node, vector<int>& out) {
        if (!node) return;
        out.push_back(node->val);
        preorder(node->left, out);
        preorder(node->right, out);
    }
    vector<int> preorder() {
        vector<int> out; preorder(root, out); return out;
    }

    void postorder(Node* node, vector<int>& out) {
        if (!node) return;
        postorder(node->left, out);
        postorder(node->right, out);
        out.push_back(node->val);
    }
    vector<int> postorder() {
        vector<int> out; postorder(root, out); return out;
    }

    vector<int> levelOrder() {
        vector<int> res;
        if (!root) return res;
        queue<Node*> q; q.push(root);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            res.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return res;
    }

    // Validate BST - use bounds
    bool validateBST() { return validateBSTRec(root, LLONG_MIN, LLONG_MAX); }
    bool validateBSTRec(Node* node, long long low, long long high) {
        if (!node) return true;
        if (node->val <= low || node->val >= high) return false;
        return validateBSTRec(node->left, low, node->val)
            && validateBSTRec(node->right, node->val, high);
    }

    // kth smallest (simple inorder)
    bool kthSmallest(int k, int &result) {
        int cnt = 0;
        return kthRec(root, k, cnt, result);
    }
    bool kthRec(Node* node, int k, int &cnt, int &result) {
        if (!node) return false;
        if (kthRec(node->left, k, cnt, result)) return true;
        cnt++;
        if (cnt == k) { result = node->val; return true; }
        return kthRec(node->right, k, cnt, result);
    }

    // LCA for values p and q
    Node* lca(int p, int q) {
        return lcaRec(root, p, q);
    }
    Node* lcaRec(Node* node, int p, int q) {
        if (!node) return nullptr;
        if (p < node->val && q < node->val) return lcaRec(node->left, p, q);
        if (p > node->val && q > node->val) return lcaRec(node->right, p, q);
        // diverging or equal -> node is LCA
        return node;
    }

    // floor: greatest <= x
    bool floorVal(int x, int &ans) {
        Node* cur = root; bool found = false;
        while (cur) {
            if (cur->val == x) { ans = cur->val; return true; }
            if (cur->val < x) { ans = cur->val; found = true; cur = cur->right; }
            else cur = cur->left;
        }
        return found;
    }

    // ceil: smallest >= x
    bool ceilVal(int x, int &ans) {
        Node* cur = root; bool found = false;
        while (cur) {
            if (cur->val == x) { ans = cur->val; return true; }
            if (cur->val > x) { ans = cur->val; found = true; cur = cur->left; }
            else cur = cur->right;
        }
        return found;
    }

    // Serialize (preorder) with '#' as null marker
    void serializeRec(Node* node, ostringstream &out) {
        if (!node) { out << "# "; return; }
        out << node->val << ' ';
        serializeRec(node->left, out);
        serializeRec(node->right, out);
    }
    string serialize() {
        ostringstream out;
        serializeRec(root, out);
        return out.str();
    }

    // Deserialize (from tokens using recursion)
    Node* deserializeRec(istringstream &in) {
        string token;
        if (!(in >> token)) return nullptr;
        if (token == "#") return nullptr;
        int val = stoi(token);
        Node* node = new Node(val);
        node->left = deserializeRec(in);
        node->right = deserializeRec(in);
        return node;
    }
    void deserializeFromString(const string &s) {
        istringstream in(s);
        // free old tree? skipping here for brevity (production: free memory)
        root = deserializeRec(in);
    }

    // Destructor helper - free nodes
    void freeRec(Node* node) {
        if (!node) return;
        freeRec(node->left);
        freeRec(node->right);
        delete node;
    }
    ~BST() { freeRec(root); root = nullptr; }
};

// Example main with tests
int main() {
    BST tree;
    vector<int> inputs = {50, 30, 70, 20, 40, 60, 80};
    for (int v : inputs) tree.insert(v);

    cout << "Inorder (sorted): ";
    for (int x : tree.inorder()) cout << x << ' ';
    cout << '\n';

    cout << "Search 60: " << (tree.search(60) ? "found" : "not found") << '\n';
    cout << "Search 25: " << (tree.search(25) ? "found" : "not found") << '\n';

    cout << "Level-order: ";
    for (int x : tree.levelOrder()) cout << x << ' ';
    cout << '\n';

    cout << "Delete 50 (root with two children)\n";
    tree.remove(50);
    cout << "Inorder after delete: ";
    for (int x : tree.inorder()) cout << x << ' ';
    cout << '\n';

    int kth;
    if (tree.kthSmallest(3, kth)) cout << "3rd smallest: " << kth << '\n';
    else cout << "k out of range\n";

    Node* ancestor = tree.lca(20, 40);
    if (ancestor) cout << "LCA(20,40): " << ancestor->val << '\n';

    string ser = tree.serialize();
    cout << "Serialized tree: " << ser << '\n';

    // Deserialize example
    BST newt;
    newt.deserializeFromString(ser);
    cout << "Deserialized inorder: ";
    for (int x : newt.inorder()) cout << x << ' ';
    cout << '\n';

    return 0;
}
