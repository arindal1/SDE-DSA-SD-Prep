#include <bits/stdc++.h>

using namespace std;

void sortArr(vector<int> &arr, int k) {
    int n = arr.size(), i = 0;
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq;

    while (i < n) {
        pq.push(arr[i]);

        if (pq.size() > k) {
            res.push_back(pq.top());
            pq.pop();
        }

        i++;
    }

    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }

    cout << "[ ";
    for (int j = 0; j < n; ++j) {
        cout << res[j] << " ";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    sortArr(arr, k);
}