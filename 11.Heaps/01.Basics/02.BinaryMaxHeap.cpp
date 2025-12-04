#include <bits/stdc++.h>
using namespace std;

class BinaryHeap {
public:
    int capacity;
    int size;
    int *arr;

    BinaryHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }

    void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    // Insert into max-heap
    void Insert(int x) {
        if (size == capacity) {
            cout << "Heap Overflow" << endl;
            return;
        }

        arr[size] = x;
        int k = size;
        size++;

        // Bubble up while parent is smaller (for max-heap)
        while (k != 0 && arr[parent(k)] < arr[k]) {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    // Heapify for max-heap (push down)
    void Heapify(int ind) {
        int li = left(ind);
        int ri = right(ind);
        int largest = ind;

        if (li < size && arr[li] > arr[largest])
            largest = li;
        if (ri < size && arr[ri] > arr[largest])
            largest = ri;

        if (largest != ind) {
            swap(&arr[ind], &arr[largest]);
            Heapify(largest);
        }
    }

    int getMax() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return INT_MIN;
        }
        return arr[0];
    }

    int ExtractMax() {
        if (size <= 0)
            return INT_MIN;

        if (size == 1) {
            size--;
            return arr[0];
        }

        int maxi = arr[0];
        arr[0] = arr[size - 1];
        size--;
        Heapify(0);

        return maxi;
    }

    // For max-heap we usually INCREASE key to bubble it up.
    void IncreaseKey(int i, int val) {
        arr[i] = val;

        // Bubble up while parent is smaller
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    void Delete(int i) {
        // Set to very large, move to root, then extract
        IncreaseKey(i, INT_MAX);
        ExtractMax();
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryHeap h(20);
    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    cout << "Max value is: " << h.getMax() << endl;

    h.Insert(10);
    cout << "Max value is: " << h.getMax() << endl;

    h.IncreaseKey(3, 20);
    cout << "Max value is: " << h.getMax() << endl;

    h.ExtractMax();
    cout << "Max value is: " << h.getMax() << endl;

    h.Delete(0);
    cout << "Max value is: " << h.getMax() << endl;

    return 0;
}
