#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int heapSize, int root) {
    int largest = root;
    int left    = 2*root + 1;
    int right   = 2*root + 2;

    if (left < heapSize && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < heapSize && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, heapSize, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n/2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    heapSort(arr);

    for (int x : arr)
        cout << x << " ";
    cout << "\n";
    return 0;
}