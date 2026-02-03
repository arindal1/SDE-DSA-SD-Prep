# Binary Search Trees -> In-depth Notes & Guide 🧭🌳

Below is a friendly, structured, and **developer-focused** markdown guide to Binary Search Trees (BSTs).
It includes problem statement, intuition, brute force vs optimal approaches, algorithms, full C++ reference code, test cases, complexity analysis, tips & tricks, variations (AVL, RB), and FAQs. I made it informative **and** a little fun -> sprinkled with emojis and pop-culture metaphors where it helps. If you meant *a specific* code snippet, paste it and I’ll adapt/annotate that exact code. For now, here's a polished, correct implementation and notes you can drop into a repo or study from. 🚀



# Problem statement

A **Binary Search Tree (BST)** is a binary tree where for every node:

* All nodes in the left subtree have **values < node.value**
* All nodes in the right subtree have **values > node.value**

Typical tasks:

* Insert, search, delete elements.
* Query kth smallest, predecessor/successor.
* Validate if a binary tree is a BST.
* Serialize/deserialize a BST.
* Use BST for ordered data operations (like a map/set).

Use-cases: ordered data storage with efficient search, dynamic sets, in-memory indexes.



# Quick intuition & properties

* BST keeps elements in sorted order via structure.
* *Inorder traversal* of BST → sorted sequence.
* Balanced BST → operations O(log n). Unbalanced (degenerate linked-list-like) → O(n).
* Works great when you need ordered operations + frequent inserts/deletes without paying the overhead of self-balancing trees (if data is random or small).

Pop-culture analogy:

> Think of the BST like a well-organized bookshelf -> every shelf (node) has smaller volumes (left) and larger ones (right). Inorder reading gives you volumes in ascending order -> no chaos.



# Brute force vs Optimal

**Brute force (no tree):**

* Keep unsorted array/vector.

  * Search: O(n)
  * Insert: O(1) append (but queries slow)
  * Delete: O(n) to find + shift
* Sorting every time leads to O(n log n) per heavy operation -> terrible.

**BST (optimal when balanced):**

* Search/Insert/Delete: O(h) where h = tree height.

  * Balanced: h ≈ log n → **O(log n)**.
  * Unbalanced: h ≈ n → **O(n)**.

When you need guaranteed log n, use **AVL** or **Red-Black trees** (self-balancing). But plain BST is simpler to implement and often performs fine with random inserts.



# Core BST operations -> Algorithms & pseudocode

I'll describe the core operations with intuition, then show code later.



## Insert (recursive)

**Idea:** Compare value with current node. Go left if smaller, right if larger. Insert at null.

**Pseudocode**:

```
function insert(node, val):
    if node == null:
        return new Node(val)
    if val < node.val:
        node.left = insert(node.left, val)
    else if val > node.val:
        node.right = insert(node.right, val)
    // duplicates: typically ignore or handle per problem
    return node
```



## Search (recursive / iterative)

**Idea:** Binary search on tree: compare and go left/right.

**Complexity:** O(h)



## Delete

Deleting a node has 3 cases:

1. Leaf node -> remove directly.
2. Node with one child -> replace node with its child.
3. Node with two children -> find inorder successor (smallest in right subtree) or predecessor (largest in left subtree), copy its value and delete that successor recursively.

**Pseudocode** (delete by successor):

```
function delete(node, key):
    if node == null: return null
    if key < node.val: node.left = delete(node.left, key)
    else if key > node.val: node.right = delete(node.right, key)
    else:
        if node.left == null: return node.right
        if node.right == null: return node.left
        successor = min(node.right)
        node.val = successor.val
        node.right = delete(node.right, successor.val)
    return node
```



## Traversals

* **Inorder:** left → node → right → yields sorted order.
* **Preorder:** node → left → right → useful for copying tree, prefix serialization.
* **Postorder:** left → right → node → useful for deletion.
* **Level-order:** BFS using queue.



## Validate BST

**Idea:** Ensure every node value lies inside valid bounds ((min, max)). Recurse with updated bounds:

* left subtree: max = node.val
* right subtree: min = node.val



## K-th smallest

Do an inorder traversal but stop when you've visited k nodes. Or augment nodes with subtree sizes for O(h) query time.



## Lowest Common Ancestor (LCA) in BST

**Idea:** For nodes p and q:

* If both values < node.val → go left
* If both > node.val → go right
* Else node is LCA.



## Floor & Ceil

* **Floor(x):** greatest value ≤ x. Walk tree: if node.val == x return x; if node.val > x → go left; else set candidate = node.val and go right.
* **Ceil(x):** smallest value ≥ x. Mirror logic.



## Serialize / Deserialize

Common method: preorder traversal with markers for nulls (e.g., `#`), or store as inorder+preorder with structure. For BST, preorder alone (with markers) suffices for exact reconstruction if nulls are used.



# Full C++ reference code (ready-to-run)

This code contains a `BST` class with:

* insert (recursive + iterative demo)
* search
* deleteNode
* traversals
* validate
* kthSmallest (simple inorder)
* LCA
* floor/ceil
* serialize / deserialize (preorder with `#` tokens)

```cpp
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
```

> Tip: Save as `bst_reference.cpp` and compile with `g++ -std=c++17 bst_reference.cpp -O2 -o bst`.



# Test cases & usage examples

**Simple insert/search/delete**

* Insert: [50,30,70,20,40,60,80]
* `search(60)` → true
* `search(25)` → false
* `remove(50)` (root with two children) → new inorder `[20,30,40,60,70,80]` (50 replaced by inorder successor 60)

**Edge cases**

* Delete leaf node (20) -> works.
* Delete node with one child -> works.
* Search/Remove from empty tree -> should no-op / return false.
* Duplicates: current code ignores duplicates. If duplicates needed, design rule (e.g., `<=` to left or maintain count field).

**Kth smallest**

* On `[20,30,40,60,70,80]`, k=1→20, k=6→80, k=7→out of range.

**Serialize/Deserialize**

* Serializing then deserializing should yield equivalent inorder traversal.



# Complexity analysis

| Operation                   | Average case (balanced) | Worst case (skewed) |
| - | -- | - |
| Search                      | O(log n)                | O(n)                |
| Insert                      | O(log n)                | O(n)                |
| Delete                      | O(log n)                | O(n)                |
| Inorder traversal           | O(n)                    | O(n)                |
| Kth smallest (inorder walk) | O(k + h) ~ O(n) worst   | O(n)                |
| Serialize/Deserialize       | O(n)                    | O(n)                |
| Memory                      | O(n)                    | O(n)                |

Space: recursion depth O(h) for recursive implementations. Iterative versions can reduce recursion depth.



# Tips, tricks & common pitfalls 💡

* **Duplicates:** Decide up front how to handle: ignore, store counts, or insert equal values consistently left/right.
* **Balance matters:** For worst-case inputs (sorted inserts), BST becomes a linked list → O(n). Use randomized insertion order, or use self-balancing trees.
* **Use iterative for deep trees** to avoid stack overflow for extreme skewed trees.
* **Validation pitfalls:** Don’t check only parent-child relation; you must ensure global bounds (min/max).
* **Delete two-child node:** Many forget to reassign `node->right = deleteRec(node->right, succ->val)` after copying successor.
* **Memory leaks:** If you replace root or tree, free nodes or implement destructor to avoid leaks.
* **Augment nodes:** Add a `size` field (size of subtree) to support O(log n) kth-smallest if tree balanced.

Small debugging checklist:

* Is `insert` returning new root when root was null? Common bug: forgetting `root = insertRec(root, val)`.
* Are duplicates causing infinite loops in iterative insert? Ensure loop terminates on equality.
* After delete, are you leaking nodes? Always `delete` removed node.



# Variations & when to use them

* **AVL Tree** -> strictly balanced (height difference ≤ 1). Pros: guaranteed O(log n). Cons: more rotations & complexity.
* **Red-Black Tree** -> looser balance; widely used (C++ `std::map`/`std::set`). Good overall performance.
* **Treap** -> randomized priority, expected O(log n).
* **Splay Tree** -> self-adjusts; amortized complexities.
* **B-Tree / B+ Tree** -> use for external storage / databases.

When to use a plain BST:

* Learning/educational.
* Small n or random input distribution where balancing isn't critical.
* When implementing specific operations where BST shape provides benefits.



# FAQs 🤔

**Q: Is inorder traversal always sorted?**
A: For a *correct* BST, yes -> inorder traversal yields ascending order.

**Q: How to handle duplicates?**
A: Options: store a count in the node, allow duplicates on one side only (`<=` to left), or use multiset-like structure.

**Q: What's better: BST or hash table?**
A: Use hash table for O(1) average lookup with no order guarantee. Use BST when you need ordered operations (range queries, next/prev, kth smallest).

**Q: How to make kth smallest O(log n)?**
A: Augment each node with `size` = count of nodes in subtree. Then use sizes to walk down in O(h) time.

**Q: How to avoid worst-case O(n)?**
A: Insert in random order, or use a self-balancing tree (AVL, Red-Black, Treap).

**Q: Can BST store other data types?**
A: Yes -> templated nodes or store comparable keys/values (e.g., pair<key,value>).



# Quick debugging checklist (TL;DR)

* Insert returns new root when called on root.
* Delete handles 0,1,2 children cases.
* Validate uses global bounds, not just parent-child.
* Use destructor to free memory.
* For deep recursion, prefer iterative or increase stack / balance tree.

