## 🧱 **1️⃣ Create a Doubly Linked List from Array**

### **Concept**

We create a Doubly Linked List (DLL) using elements of a given array.
Each node contains:

* `data` → value
* `next` → pointer to next node
* `back` → pointer to previous node

### **Algorithm**

1. Create the head node with the first array element.
2. For every next element:

   * Create a new node with `back` pointing to the previous node.
   * Update `prev->next = temp`.
3. Return the `head`.

### **Code Function**

```cpp
Node* Arr2LL(vector<int> &arr);
```

Converts an array into a DLL.

### **Output Example**

Input: `{12, 22, 24, 14, 5}`
Output: `12  22  24  14  5`

---

## 🧹 **2️⃣ Delete Head Node of Doubly Linked List**

### **Concept**

Remove the first node of a DLL and adjust the pointers.

### **Algorithm**

1. If list is empty or has one node, return as is.
2. Move head to `head->next`.
3. Set `head->back = nullptr`.
4. Delete the old head node.

### **Code Function**

```cpp
Node* DeleteHead(Node* head);
```

### **Output Example**

Before: `12  22  24  14  5`
After: `22  24  14  5`

---

## 🔚 **3️⃣ Delete Tail Node of Doubly Linked List**

### **Concept**

Remove the last node and reconnect the previous node’s `next` pointer to `nullptr`.

### **Algorithm**

1. Traverse to the last node using a temp pointer.
2. Let `prev = temp->back`.
3. Set `prev->next = nullptr`.
4. Delete the tail node.

### **Code Function**

```cpp
Node* DeleteTail(Node* head);
```

### **Output Example**

Before: `12  22  24  14  5`
After: `12  22  24  14`

---

## ⚙️ **4️⃣ Delete K-th Node from Doubly Linked List**

### **Concept**

Remove the node at position `k` from the DLL.

### **Algorithm**

1. Traverse to the `k-th` node.
2. Store pointers to its previous (`prev`) and next (`front`) nodes.
3. Handle cases:

   * **Only one node**: delete and return `nullptr`.
   * **Deleting head**: move head to `front`, set `front->back = nullptr`.
   * **Deleting tail**: set `prev->next = nullptr`.
   * **Deleting middle node**: connect `prev->next = front` and `front->back = prev`.
4. Delete target node and return updated head.

### **Code Function**

```cpp
Node* DeleteK(Node* head, int k);
```

### **Output Example**

Input: `k = 1`
Before: `12  22  24  14  5`
After: `22  24  14  5`

---

## 🧩 **Complexity Analysis**

| Operation        | Time Complexity | Space Complexity |
| ---------------- | --------------- | ---------------- |
| Create DLL       | O(n)            | O(1)             |
| Delete Head      | O(1)            | O(1)             |
| Delete Tail      | O(n)            | O(1)             |
| Delete K-th Node | O(k)            | O(1)             |

---

## 🧩 **5️⃣ Insert at Head of Doubly Linked List**

### **Concept**

Inserts a new node at the **beginning** of the DLL.

### **Algorithm**

1. If the list is empty → create a new node and return it as the head.
2. Create a new node and link:

   * `newNode->next = head`
   * `head->back = newNode`
3. Return `newNode` as the new head.

### **Code Function**

```cpp
Node* InsertHead(Node* head, int val);
```

### **Example**

Input: `12 22 24 14 5`, val = `777`
Output: `777 12 22 24 14 5`

### **Complexity**

* Time: **O(1)**
* Space: **O(1)**

---

## 🔚 **6️⃣ Insert at Tail of Doubly Linked List**

### **Concept**

Inserts a new node at the **end** of the DLL.

### **Algorithm**

1. If the list is empty → create a new node and return.
2. Traverse till the last node (`temp->next == nullptr`).
3. Create a new node:

   * `temp->next = newNode`
   * `newNode->back = temp`
4. Return `head`.

### **Code Function**

```cpp
Node* InsertTail(Node* head, int val);
```

### **Example**

Input: `12 22 24 14 5`, val = `777`
Output: `12 22 24 14 5 777`

### **Complexity**

* Time: **O(n)**
* Space: **O(1)**

---

## ⚙️ **7️⃣ Insert at K-th Position (Under Construction)**

### **Concept**

Inserts a new node at the **K-th position** in a DLL.

### **Steps** ✅

1. Handle `k == 1` separately (use `InsertHead`).
2. Traverse the list to the `(k-1)`th node.
3. Create a new node:

   ```cpp
   Node* newNode = new Node(val);
   newNode->next = prev->next;
   newNode->back = prev;
   if (prev->next) prev->next->back = newNode;
   prev->next = newNode;
   ```
4. Return head.


```cpp
head = InsertK(head, val, k);
```

### **Complexity**

* Time: **O(k)**
* Space: **O(1)**

---

## 🔄 **8️⃣ Reverse Doubly Linked List**

### **Two Approaches**

---

### 🧠 **Approach 1: Using Stack**

Stores node values in a stack, then rewrites them in reverse order.

#### **Algorithm**

1. Traverse and push all `data` values to stack.
2. Traverse again, popping stack values into each node.

#### **Code Function**

```cpp
Node* ReverseStack(Node* head);
```

#### **Complexity**

* Time: **O(n)**
* Space: **O(n)**

---

### ⚡ **Approach 2: In-place Pointer Swap (Optimal)**

#### **Algorithm**

1. Traverse through the list.
2. For each node, **swap its `next` and `back` pointers**.
3. Move `temp` backward (`temp = temp->back`).
4. At the end, `prev->back` becomes the new head.

#### **Code Function**

```cpp
Node* ReverseSwap(Node* head);
```

#### **Complexity**

* Time: **O(n)**
* Space: **O(1)**

---

### **Example**

Input: `12 22 24 14 5`
Output: `5 14 24 22 12`

---


## 🧠 **Tips & Notes**

* Always check for **null pointers** before deleting.
* When deleting, always **disconnect both `next` and `back` pointers**.
* Don’t forget to `delete` the target node to prevent **memory leaks**.
* You can modify `PrintLL` to print in reverse using `back` pointers — useful for debugging DLLs.
* For `InsertK()`, ensure to **check boundary conditions** (`k == 1`, `k > length`).
* Use **in-place reversal** (`ReverseSwap`) for efficiency.
* `ReverseStack` is easier to understand but uses extra memory.

---
