## 01.1 - `Node` class (constructor demonstration)

**What it is**

```cpp
class Node {
public:
    int data;
    Node* next;
    Node (int data1, Node* next1) { data = data1; next = next1; }
    Node (int data1) { data = data1; next = nullptr; }
};
```

**Purpose**

* Simple singly-linked list node with two constructors (with/without `next`).

**Notes / tips**

* Consider making members `private` and provide accessors if you need encapsulation.
* Use initializer lists: `Node(int v, Node* n): data(v), next(n){}` — clearer and more efficient.

**Complexity**

* Trivial; constructors are O(1).

## Demo: create a single node and print fields

**Original idea**

* Create `Node* y = new Node(arr[0]);` then print `y`, `y->data`, `y->next`.

**Notes**

* `cout << y` prints the pointer address. `y->next` is `nullptr` initially. Useful for small sanity checks.

---

## 01.2 - `Ar2LL` - Array → Linked List

**Function**

* Create a linked list in the same order as the input array.

**Core idea**

```cpp
Node* Ar2LL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}
```

**Complexity**

* Time: `O(n)` — one pass to build.
* Space: `O(1)` extra (nodes allocated are the list itself).

**Notes / improvements**

* Check `arr.empty()` to avoid `arr[0]` UB.
* Pass `arr` as `const vector<int>&` to avoid copying.
* Consider returning a `pair<Node*, Node*>` with head & tail if you frequently append.

## `printLL` — Print list elements

**Original**

```cpp
void printLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
```

**Purpose**

* Prints all node values in order.

**Complexity**

* Time `O(n)`, Space `O(1)`.

**Tips**

* If you need a newline afterwards, print it.
* For large lists, consider buffering (ostringstream) before printing.

---
---

## 0.2.1 - `insertHead()` — Insert at Beginning

**Purpose:**
Insert a new node **at the start** of a singly linked list.

**Code summary:**

```cpp
Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}
```

**How it works:**

* Creates a new node (`temp`) whose `next` points to the current head.
* Returns the new node as the updated head.

**Complexity:**

* ⏱️ Time → `O(1)`
* 💾 Space → `O(1)`

**Edge case:**

* If the list is empty (`head == nullptr`), it still works — new node becomes head.

---

## 02.2 - `insertTail()` — Insert at End

**Purpose:**
Insert a new node **at the end** (tail) of the linked list.

**Code summary:**

```cpp
Node* insertTail(Node* head, int val) {
    if (head == nullptr)
        return new Node(val);  // handle empty list

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = new Node(val);
    return head;
}
```

**How it works:**

* Traverses to the last node.
* Creates a new node and links it at the end.
* Returns the (unchanged) head.

**Complexity:**

* ⏱️ Time → `O(n)` (must traverse entire list)
* 💾 Space → `O(1)`

**Edge case fix:**
Add handling for `head == nullptr` to correctly initialize an empty list.

---

## 02.3 — Insert at K-th Position

**Purpose:**
Insert a new node **at position `k`** (1-based index) in the linked list.

**Code summary:**

```cpp
Node* insertAtK(Node* head, int val, int k) {
    if (k == 1) return new Node(val, head);  // insert at head

    Node* temp = head;
    int cnt = 1;
    while (temp && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }
    if (!temp) return head;  // if k > length, do nothing

    Node* newNode = new Node(val, temp->next);
    temp->next = newNode;
    return head;
}
```

**How it works:**

* If `k == 1`, simply call `insertHead()`.
* Otherwise, traverse until the `(k−1)`th node.
* Insert a new node after it by adjusting pointers.

**Complexity:**

* ⏱️ Time → `O(k)` ≈ `O(n)`
* 💾 Space → `O(1)`

**Edge cases:**

* If `k > length + 1`, insertion fails gracefully (no crash).
* If list is empty and `k > 1`, no insertion happens.


---
---

## 03.1 - `deleteHead` — Remove first node

* `free(temp)` used with `new`-allocated nodes → **BUG**.

**Corrected**

```cpp
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* nxt = head->next;
    delete head;
    return nxt;
}
```

**Edge cases**

* If list is empty, return `nullptr`.
* If single node, returns `nullptr`.

**Complexity**

* Time `O(1)`, Space `O(1)`.

---

## 03.2 - `deleteTail` — Remove last node


```cpp
Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* cur = head;
    while (cur->next->next != nullptr) {
        cur = cur->next;
    }
    delete cur->next;
    cur->next = nullptr;
    return head;
}
```

**Complexity**

* Time `O(n)` (must traverse to node before tail), Space `O(1)`.

**Improvements**

* Maintain a `tail` pointer in the list structure for O(1) tail delete/append.

---

## 03.3 - `deleteK` — Delete k-th node (1-based)


```cpp
Node* deleteKth(Node* head, int k) {
    if (head == nullptr || k <= 0) return head;
    if (k == 1) {
        Node* nxt = head->next;
        delete head;
        return nxt;
    }
    Node* prev = nullptr;
    Node* cur = head;
    int idx = 1;
    while (cur != nullptr && idx < k) {
        prev = cur;
        cur = cur->next;
        ++idx;
    }
    if (cur == nullptr) {
        return head;
    }
    prev->next = cur->next;
    delete cur;
    return head;
}
```

**Complexity**

* Time `O(k)` worst `O(n)`, Space `O(1)`.

**Notes**

* Always handle `k <= 0` and `k > length`.

---
---

## 04 - ListLength - returns/counts nodes

```cpp
int countNodes(Node* head) {
    int cnt = 0;
    while (head) { ++cnt; head = head->next; }
    return cnt;
}
```

**Complexity**

* Time `O(n)`, Space `O(1)`.

---
---

## 05 - `searchLL` — find value in list


```cpp
bool contains(Node* head, int val) {
    while (head) {
        if (head->data == val) return true;
        head = head->next;
    }
    return false;
}
```

**Complexity**

* Time `O(n)`, Space `O(1)`.

---
---


* **Always** pair `new` with `delete` and `new[]` with `delete[]`. Do **not** use `free()` on `new` memory.
* Prefer RAII containers/wrappers in C++: e.g., `std::unique_ptr<Node>` if you want automatic freeing, or better — write a small `LinkedList` class that owns nodes and in destructor frees them.
* Use `nullptr` instead of `NULL`.
* Validate inputs (empty arrays) before dereferencing.
* Prefer `const vector<int>&` for functions that only read arrays.

---
