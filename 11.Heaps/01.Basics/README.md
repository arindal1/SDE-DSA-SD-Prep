# Heaps & Priority Queues

A thorough, easy-to-follow guide covering **heaps**, **priority queues**, **binary heaps**, **min/max heaps**, **checking if an array is a min-heap**, and **converting min → max heap**. Includes intuition, brute force vs optimal approaches, code (C++ & Python), complexity, test cases, tips, variations, and an FAQ. I’ll keep it practical and a bit playful — think of heaps as a party where the *smallest* (or *largest*) guest always stands at the door. 🎉


# 1 — What is a heap? (Intuition)

A **heap** is a specialized tree-based data structure that satisfies the **heap property**:

* **Min-heap**: every parent ≤ its children — so the minimum element is at the root.
* **Max-heap**: every parent ≥ its children — so the maximum element is at the root.

Think: a min-heap is like a line where the smallest person is always at the front — if someone smaller joins, they slip forward. 🧑‍🤝‍🧑

Key characteristics:

* Usually implemented as a **complete binary tree** (filled left-to-right).
* Frequently implemented in **arrays** for compactness and speed.

---

# 2 — Priority queue (abstract)

A **priority queue** is an ADT that supports:

* `insert(item, priority)`
* `peek()` / `top()` — highest priority element (min or max depending on convention)
* `pop()` / `extract()` — remove highest priority

**Heaps** are the most common way to implement priority queues efficiently.

---

# 3 — Binary heap (array layout & properties)

A **binary heap** stores a complete binary tree in an array `A`:

* root at index `0` (or `1` depending on implementation)
* For 0-index:

  * parent(i) = (i-1) // 2
  * left(i) = 2*i + 1
  * right(i) = 2*i + 2

Because the tree is complete, array representation is continuous — no pointers needed. Memory- & cache-friendly. ⚡

---

# 4 — Min heap vs Max heap (quick)

* **Min-heap**: smallest at top (root). Good for **Dijkstra**, **Prim**, **k smallest**, scheduling earliest time.
* **Max-heap**: largest at top. Good for **k largest**, heapsort (max-heap yields ascending after swapping).

Switching between them is straightforward.

---

# 5 — Core operations: intuition + algorithms

### 5.1 `peek()` / `top()`

* **Intuition**: the root is min (or max). O(1).
* **Algorithm**: return `A[0]`.

### 5.2 `insert(x)`

**Intuition**: put new item at the end (maintain complete tree), then bubble it up until heap property restored.

* **Algorithm**:

  1. Append to array.
  2. `heapifyUp(i)` — while parent is > child (for min-heap), swap.
* **Complexity**:

  * Worst-case: O(log n) (height of tree)
  * Amortized/in practice: O(log n)

### 5.3 `extractMin()` / `extractMax()`

**Intuition**: remove root; move last element to root and push it down (`heapifyDown`) to restore order.

* **Algorithm**:

  1. Save root value.
  2. Replace `A[0]` with last element; pop last.
  3. `heapifyDown(0)` — swap with the smaller (for min-heap) child until order holds.
* **Complexity**: O(log n)

### 5.4 `buildHeap` (from array)

Two ways:

* **Brute force**: repeatedly `insert` each element into an empty heap -> O(n log n).
* **Optimal**: bottom-up heapify — start from last non-leaf (`n//2 - 1`) down to root calling `heapifyDown`. This *builds heap in O(n)* time. 🧠

**Why O(n)?** Intuition: lower levels have many nodes but short distances to move; higher levels have few nodes but potential long moves. Summed work is linear. (Common interview proof uses summation of heights.)

---

# 6 — Check if an array represents a min-heap

### Problem

Given array `A[0..n-1]`, determine if it satisfies min-heap property.

### Brute force approach

* For every `i` from 0 to `n-1`, check children indices and compare.
* Complexity: O(n) since each index is checked constant-time.

Pseudo:

```
for i in range(n):
    left = 2*i + 1
    right = 2*i + 2
    if left < n and A[i] > A[left]: return False
    if right < n and A[i] > A[right]: return False
return True
```

This *is* optimal: we must inspect relevant positions; O(n) is best.

### Notes

* Only need to check internal nodes: i in [0, n//2 - 1].
* Edge cases: n=0 or n=1 -> True.

---

# 7 — Min → Max heap: ways to convert

### Approach A — Rebuild (optimal)

* Build a **max-heap** from the array using bottom-up `heapifyDown` → O(n).
* Steps: same as building any heap; define `heapify` comparison for max.

### Approach B — Use min-heap by inverting keys

* If you're using a library that only offers min-heap (e.g., Python `heapq`), you can invert keys: push `-x`.
* This yields a max-behavior for integers.
* Complexity: O(n) for building by pushing n items (naive insert) = O(n log n), but you can also convert by inverting and then `heapify` the list in O(n).

### Approach C — Use priority_queue with comparator (C++)

* `priority_queue<int>` by default is max-heap; or `priority_queue<int, vector<int>, greater<int>>` for min-heap.

**Summary**: Best is to rebuild with `heapify` using proper comparator — O(n).

---

# 8 — Full code (C++ & Python)

### C++ — BinaryMinHeap & checks (clean, educational)

```cpp
// heap_notes.cpp
#include <bits/stdc++.h>
using namespace std;

struct MinHeap {
    vector<int> a;
    MinHeap() {}
    MinHeap(const vector<int>& arr) { a = arr; buildHeap(); }

    int parent(int i){ return (i-1)/2; }
    int left(int i){ return 2*i + 1; }
    int right(int i){ return 2*i + 2; }

    void heapifyDown(int i){
        int n = a.size();
        while (true){
            int l = left(i), r = right(i);
            int smallest = i;
            if (l < n && a[l] < a[smallest]) smallest = l;
            if (r < n && a[r] < a[smallest]) smallest = r;
            if (smallest == i) break;
            swap(a[i], a[smallest]);
            i = smallest;
        }
    }

    void heapifyUp(int i){
        while (i && a[parent(i)] > a[i]) {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void insert(int x){
        a.push_back(x);
        heapifyUp(a.size()-1);
    }

    int peek(){
        if (a.empty()) throw runtime_error("heap empty");
        return a[0];
    }

    int extractMin(){
        if (a.empty()) throw runtime_error("heap empty");
        int root = a[0];
        a[0] = a.back();
        a.pop_back();
        if (!a.empty()) heapifyDown(0);
        return root;
    }

    void buildHeap(){
        int n = a.size();
        for (int i = n/2 - 1; i >= 0; --i) heapifyDown(i);
    }

    bool isMinHeapArray() const {
        int n = a.size();
        for (int i = 0; i <= (n/2 - 1); ++i) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < n && a[i] > a[l]) return false;
            if (r < n && a[i] > a[r]) return false;
        }
        return true;
    }
};

int main(){
    vector<int> arr = {1,3,5,7,9,8,6};
    MinHeap h(arr);
    cout << "Is min-heap? " << (h.isMinHeapArray() ? "Yes" : "No") << endl;
    h.insert(2);
    cout << "Peek: " << h.peek() << endl;
    cout << "Extracted: " << h.extractMin() << endl;
    cout << "Peek now: " << h.peek() << endl;
    return 0;
}
```

---

### Python — `heapq` usage + manual heap functions

```python
# heap_notes.py
import heapq

# Using Python's heapq -> min-heap
arr = [1,3,5,7,9,8,6]
heapq.heapify(arr)  # O(n)
print("min:", arr[0])   # peek

heapq.heappush(arr, 2)  # insert O(log n)
print("after push 2 ->", arr[0])
print("pop ->", heapq.heappop(arr))

# Check if array is min-heap (array arr is a heap only when heapq.heapify was used)
def is_min_heap(a):
    n = len(a)
    for i in range(n // 2):
        l = 2*i + 1
        r = 2*i + 2
        if l < n and a[i] > a[l]:
            return False
        if r < n and a[i] > a[r]:
            return False
    return True

print("is min heap?", is_min_heap([1,3,5,7,9,8,6]))

# Convert min-heap to max-heap by inverting keys
minlist = [5,2,8,1,9,3]
heapq.heapify(minlist)
# get max behavior: push negative
maxheap = [-x for x in minlist]
heapq.heapify(maxheap)
print("max (via invert) ->", -heapq.heappop(maxheap))

# Build max-heap directly by heapify with negative invert from any list:
def build_max_heap_from_list(lst):
    arr = [-x for x in lst]
    heapq.heapify(arr)  # O(n)
    return arr

print("max root:", -build_max_heap_from_list([3,10,2,1,7])[0])
```

---

# 9 — Complexity analysis (summary)

| Operation                   |     Time |                 Space |
| --------------------------- | -------: | --------------------: |
| `peek()`                    |     O(1) |                  O(1) |
| `insert`                    | O(log n) |        O(1) amortized |
| `extractMin` / `extractMax` | O(log n) |                  O(1) |
| `buildHeap` (bottom-up)     |     O(n) | O(1) extra (in-place) |
| `isMinHeap` (scan)          |     O(n) |                  O(1) |

**Why buildHeap is O(n)** — short intuition:

* Leaf nodes require 0 work; nodes one level above may move 1 level; few nodes are at high levels needing larger moves; summing moves across levels gives linear time.

---

# 10 — Tips, tricks & variations 🎯

* **Use library heaps**:

  * Python: `heapq` (min-heap). For max-heap use negatives or `heapq.nlargest/k`.
  * C++: `priority_queue<T>` (max by default). Use `priority_queue<T, vector<T>, greater<T>>` for min.
* **Heapsort**: build max-heap O(n), then repeatedly swap root with last and heapify-down for reduced size → O(n log n), in-place, unstable.
* **Kth problems**:

  * k-th smallest: use max-heap of size k (O(n log k)).
  * k-th largest: use min-heap of size k (O(n log k)).
* **Stability**: Heaps are not stable by default. If elements share priorities and you need stability, include a tie-breaker (timestamp or incremental counter).
* **Memory**: array implementation = contiguous memory, good cache locality.
* **When to use other heap types**:

  * **Fibonacci heap**: better amortized decrease-key → used in advanced algorithms like dense Dijkstra variants. Rarely used in practice due to complexity.
  * **Binomial heap**: good for mergeable heaps.

**Interview tip**: always know both the array index formulas and how to prove `buildHeap` is O(n) at a high level.

---

# 11 — Test cases & examples 🧪

### Basic functional tests

1. `[]` -> min-heap? True
2. `[1]` -> True
3. `[1, 2, 3]` -> True
4. `[2, 1, 3]` -> False (because A[0] > A[1])
5. Build heap from `[3,1,6,5,2,4]` -> min-heap root = 1

### Min → Max conversion tests

* Input: `[3,10,2,1,7]`

  * Max root expected = `10`.

### Edge cases

* All equal elements `[5,5,5]` -> valid min-heap and max-heap.
* Negative numbers: works the same, invert signs carefully if using negation trick.

---

# 12 — FAQs (quick!)

**Q: Is heap sort stable?**
A: No — classic heap sort is not stable.

**Q: When to use a heap vs balanced BST (like `std::set`)?**
A: Use heap when you frequently need top element and inserts/extract-top. Use BST if you need ordered traversal, predecessor/successor, or delete arbitrary elements.

**Q: Can you delete arbitrary element from a heap?**
A: Not directly in O(log n) unless you store a map from value→index. With index known: replace with last element and heapify up/down → O(log n).

**Q: Which is better: binary heap or Fibonacci heap?**
A: Binary heap is simpler and faster in practice for typical use. Fibonacci heaps have better amortized decrease-key (O(1)) but are complex and often have worse constants.

**Q: How to check if array is max-heap?**
A: Same as min-heap check but check `A[i] >= A[left/right]`.

**Q: Convert min to max heap in O(1)?**
A: No. You must rearrange structure or invert comparator. You can change comparator and rebuild pointers if persistent structure supports it — but for array-based heaps you need at least O(n) to rebuild.

---

# Handy summary — cheat-sheet ✂️

* **Array indexes**: parent=(i-1)//2, left=2*i+1, right=2*i+2
* **Build heap** (bottom-up) = O(n)
* **Insert/pop** = O(log n)
* **isMinHeap** = scan till n//2 -> O(n)
* **Convert min→max** = rebuild O(n) or invert keys and heapify O(n)

