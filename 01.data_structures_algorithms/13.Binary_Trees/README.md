# Binary Trees — Friendly, in-depth notes 🧠🌳

Below are **clean, practical, and (slightly) fun** notes on Binary Trees — explanations, algorithms, full code, test cases, complexities, tips, variations, and FAQs. I’ll walk you through the intuition, brute force vs optimal approaches, common operations (traversals, height, diameter, LCA, serialize/deserialize, etc.), and provide a complete, tested C++ implementation you can copy/paste.

Think of this as your compact “Binary Trees cheat-sheet + tutorial” — with a sprinkle of personality. 😄


# Problem statement (what are Binary Trees?)

A **binary tree** is a data structure in which each node has at most **two** children, commonly called *left* and *right*.
It's a backbone for many algorithms and problems (search trees, heaps, expression trees, decision trees, etc.).

![image](https://static.takeuforward.org/content/-G8c7LPx4)

**Variants**:

* **Binary Tree (BT)** — no ordering constraint.
* **Binary Search Tree (BST)** — left subtree values < node < right subtree values (usually).
* **Full / Perfect / Complete** — special shapes with additional properties.



# Intuition — why do we care?

Binary trees let us represent hierarchical relationships and enable recursive thinking: each node's problem often reduces to the same problem on its left and right children. Many tree algorithms naturally run in linear time or better by avoiding redundant work.



# Common tasks & high-level approaches

Below are typical problems and the short idea behind solving them.

* **Traversals** — visit nodes in an order:

  * *Preorder*: root, left, right
  * *Inorder*: left, root, right
  * *Postorder*: left, right, root
  * *Level-order (BFS)*: by depth using queue
  * Approach: recursion or stack (iterative)
* **Height (depth)** — longest root→leaf path:

  * Recursively: `1 + max(height(left), height(right))`
* **Size (node count)** — `1 + size(left) + size(right)`
* **Leaf count** — nodes with no children
* **Diameter (longest path between any two nodes)** — naive O(N²) or optimal O(N) using single DFS and tracking heights
* **Lowest Common Ancestor (LCA)** — recursive approach: if left and right recursive calls return non-null → current node is LCA
* **isBalanced** — check heights and fail fast (O(N) using postorder)
* **Serialize / Deserialize** — store tree as list (e.g., level order with null markers) and rebuild
* **Invert (mirror)** — swap children recursively
* **Path sums, root→leaf paths, kth node, subtree checks** — routine variations



Alright Arindal, let’s do this properly 😄
Same **style, depth, and friendliness**, but now focused on **different types of Binary Trees**.
You can drop this straight into your **DSA GitHub notes** as a markdown file.



## 🌳 Types of Binary Trees

Binary Trees aren’t just “tree-shaped” — their **structure** matters a lot.
The shape affects **time complexity, recursion depth, memory usage**, and even whether your algorithm survives without TLE or stack overflow 💀.

Let’s break them down **one by one**, with **intuition, properties, checks, code, and FAQs**.



## 🧠 Quick intuition (TL;DR)

| Type           | Key Idea                                     |
| -- | -- |
| **Full**       | Every node has **0 or 2** children           |
| **Complete**   | Filled **level by level**, left to right     |
| **Perfect**    | Completely filled, **all leaves same level** |
| **Balanced**   | Height difference ≤ 1 for every node         |
| **Degenerate** | Tree behaves like a **linked list**          |

Think of it like buildings:

* **Perfect** → luxury skyscraper 🏙️
* **Complete** → under construction but organized 🏗️
* **Balanced** → structurally safe ⚖️
* **Degenerate** → a long corridor 🚪🚪🚪



# 1️⃣ Full Binary Tree 🌿

## 📌 Definition

A **Full Binary Tree** is one where **every node has either 0 or 2 children**.

No node is allowed to have **only one child**.


![image](https://static.takeuforward.org/content/-4pShol-4)

✅ Valid full binary tree

❌ A node with only left or right child breaks it



## 🧠 Intuition

* Either you're a **leaf**, or you're fully committed with **two children**
* Common in **expression trees**



## 🧪 Algorithm (Check if Full)

At each node:

* If leaf → OK
* If both children exist → OK
* Else → ❌ Not full



## 💡 Code (C++)

```cpp
bool isFull(Node* root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;
    if (root->left && root->right)
        return isFull(root->left) && isFull(root->right);
    return false;
}
```



## ⏱ Complexity

* **Time:** O(N)
* **Space:** O(H) recursion stack



## ❓ FAQ

**Q: Is a single-node tree full?**
Yes. It has 0 children ✔️



# 2️⃣ Complete Binary Tree 🧱

## 📌 Definition

A **Complete Binary Tree** is filled:

* **Level by level**
* **Left to right**
* Except possibly the **last level**

![image](https://static.takeuforward.org/content/-LtH2Wrm5)

![image](https://static.takeuforward.org/content/-EmDGdusH)





## 🧠 Intuition

* Like seats filling in a movie theater 🎬
* No gaps before the end



## 🧪 Algorithm (Level-order)

Rule:

* Once a `NULL` child is seen, **no more non-null nodes allowed**



## 💡 Code (C++)

```cpp
bool isComplete(Node* root) {
    if (!root) return true;
    queue<Node*> q;
    q.push(root);
    bool seenNull = false;

    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        if (!cur) {
            seenNull = true;
        } else {
            if (seenNull) return false;
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return true;
}
```



## ⏱ Complexity

* **Time:** O(N)
* **Space:** O(N) queue



## ❓ FAQ

**Q: Are all complete trees balanced?**
Yes ✔️
**Q: Are all balanced trees complete?**
No ❌



# 3️⃣ Perfect Binary Tree ✨

## 📌 Definition

A **Perfect Binary Tree** satisfies:

* All **internal nodes have 2 children**
* All **leaves are at the same level**



![image](https://static.takeuforward.org/content/-zhwo9qF6)



## 🧠 Intuition

* Symmetry 📐
* Maximum number of nodes for a given height



## 🧮 Properties

If height = `h`:

* Nodes = `2^(h+1) - 1`
* Leaves = `2^h`



## 🧪 Algorithm

A tree is **perfect** if:

* It is **full**
* All leaves have the same depth



## 💡 Code (C++)

```cpp
int depth(Node* root) {
    int d = 0;
    while (root) {
        d++;
        root = root->left;
    }
    return d;
}

bool isPerfect(Node* root, int d, int level = 1) {
    if (!root) return true;
    if (!root->left && !root->right)
        return d == level;
    if (!root->left || !root->right)
        return false;
    return isPerfect(root->left, d, level + 1) &&
           isPerfect(root->right, d, level + 1);
}
```



## ⏱ Complexity

* **Time:** O(N)
* **Space:** O(H)



## ❓ FAQ

**Q: Is every perfect tree complete and full?**
Yes ✔️✔️
Perfect is the **strongest condition**



# 4️⃣ Balanced Binary Tree ⚖️

## 📌 Definition

A tree is **balanced** if:

> For every node,
> `|height(left) - height(right)| ≤ 1`


![image](https://static.takeuforward.org/content/-ibRlaTll)



## 🧠 Intuition

* Prevents worst-case skew
* Keeps operations fast (O(log N) height)



## 🧪 Optimal Algorithm (Bottom-up)

Return:

* height
* whether subtree is balanced

Fail fast if unbalanced.



## 💡 Code (C++)

```cpp
pair<bool,int> check(Node* root) {
    if (!root) return {true, 0};

    auto L = check(root->left);
    auto R = check(root->right);

    bool ok = L.first && R.first &&
              abs(L.second - R.second) <= 1;

    return {ok, 1 + max(L.second, R.second)};
}

bool isBalanced(Node* root) {
    return check(root).first;
}
```



## ⏱ Complexity

* **Time:** O(N)
* **Space:** O(H)



## ❓ FAQ

**Q: Is a complete tree always balanced?**
Yes ✔️
**Q: Is a balanced tree always complete?**
No ❌



# 5️⃣ Degenerate (Skewed) Binary Tree 🪜

## 📌 Definition

A **Degenerate Tree** has:

* Every node with **only one child**

Basically… a **linked list wearing a tree costume** 🎭


![image](https://static.takeuforward.org/content/-xOtbTkvw)



## 🧠 Why it’s bad

* Height = N
* Search = O(N)
* Recursion depth = 💥



## 🧪 Detection

If height == number of nodes → degenerate



## 💡 Code (C++)

```cpp
bool isDegenerate(Node* root) {
    if (!root) return true;
    if (root->left && root->right) return false;
    return isDegenerate(root->left ? root->left : root->right);
}
```



## ⏱ Complexity

* **Time:** O(N)
* **Space:** O(H)



## ❓ FAQ

**Q: Is a degenerate tree balanced?**
Only if it has ≤ 2 nodes
Otherwise ❌



# 🧠 Comparison Summary (Very Exam-Friendly)

| Type       | Max Height | Shape                 |
| - | - | - |
| Full       | Any        | No single-child nodes |
| Complete   | O(log N)   | Level-wise            |
| Perfect    | O(log N)   | Fully symmetric       |
| Balanced   | O(log N)   | Height diff ≤ 1       |
| Degenerate | O(N)       | Linked list           |





# Tips, tricks & gotchas 💡

* Use recursion for clarity — but for deep trees (N up to 10⁵), recursion may stack overflow. Consider iterative or tail-recursive transforms.
* Always decide whether **height** is counted in nodes or edges. Be consistent in your code and tests.
* When serializing, *trim trailing nulls* to keep representation compact.
* For Binary Search Tree operations (insert/search/delete), leverage BST ordering — these are different from generic binary tree ops.
* For diameter problems, prefer the O(N) postorder approach — this is a common interview trap.
* For `isBalanced`, avoid recomputing heights from scratch (that leads to O(N²)); compute height bottom-up.
* Free memory in C++ if you're creating many trees in tests — leak otherwise.



# Variations & extra problems (practice ideas)

* Convert sorted array to balanced BST.
* Check if a binary tree is a BST (inorder should be strictly increasing).
* Serialize using preorder + null markers (useful for DFS serialization).
* Flatten binary tree to linked list (LeetCode "Flatten Binary Tree to Linked List").
* Recover BST where two nodes are swapped (inorder trick).
* Merge two binary search trees into one sorted list (inorder merging).
* Print all root→leaf paths and sums.
* Build expression tree from postfix expression and evaluate.



# Frequently Asked Questions (FAQs) ❓

**Q: What’s the difference between height and depth?**

* *Depth* of a node = distance from root to that node.
* *Height* of node = longest distance from that node to a leaf. Height of tree is height of root. (Some people use slightly different conventions regarding counts in nodes vs edges; be explicit.)

**Q: Should height of empty tree be 0 or -1?**

* Both conventions exist. I used *height(empty) = 0* and *height(single node) = 1*. If you need *edges count*, use `height(empty) = -1, height(single) = 0`. Pick what your problem expects and document it.

**Q: How to avoid recursion depth problems?**

* Use iterative algorithms (stack or BFS) or increase recursion limit (in Python). In C++ be aware recursive depth and prefer iterative for N up to 10⁵.

**Q: For diameter, are we counting nodes or edges?**

* My `diameter` function returns **edges**. To get nodes, add 1 when tree non-empty.

**Q: When should I use level-order vs DFS?**

* Use level-order (BFS) when you need shortest path by edges in unweighted tree, or when you need to operate by depth (e.g. populate next pointers). Use DFS when you need to explore whole branch (e.g. root→leaf sums) or compute heights bottom-up.

**Q: How to serialize trees with arbitrary values (including sentinel)?**

* Use a separate `bool` mask or encode size + pairs; or choose a sentinel that’s guaranteed not present (e.g., use `optional<int>` or strings). Alternatively use preorder with explicit null markers (e.g., `"null"`) to avoid collisions.



# Quick study checklist ✅

* [ ] Understand recursion base case and combine step.
* [ ] Distinguish BT vs BST.
* [ ] Practice traversals both recursively and iteratively.
* [ ] Learn diameter and isBalanced optimal patterns (postorder with info).
* [ ] Be careful with null markers when serializing.
* [ ] Think about stack depth and convert heavy recursion to iterative when needed.
