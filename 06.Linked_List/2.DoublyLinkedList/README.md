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

## 🧠 **Tips & Notes**

* Always check for **null pointers** before deleting.
* When deleting, always **disconnect both `next` and `back` pointers**.
* Don’t forget to `delete` the target node to prevent **memory leaks**.
* You can modify `PrintLL` to print in reverse using `back` pointers — useful for debugging DLLs.

---
