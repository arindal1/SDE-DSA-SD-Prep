#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(const vector<int> &arr) {
    int n = arr.size();
    if (n == 0) {
        return true;
    }

    for (int i = 0; i <= (n - 2) / 2; ++i) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < n && arr[i] > arr[leftChild])
            return false;
        if (rightChild < n && arr[i] > arr[rightChild])
            return false;
    }

    return true;
}

int main() {
    vector<int> arr = {10, 20, 30, 21, 23};

    if (isMinHeap(arr))
        cout << "Is a Min Heap";
    else
        cout << "Is not a Min Heap";

    return 0;
}