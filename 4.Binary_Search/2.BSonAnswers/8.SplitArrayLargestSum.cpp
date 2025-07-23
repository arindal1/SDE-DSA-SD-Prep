#include <bits/stdc++.h>
using namespace std;

int countPartitions(const vector<int>& a, int M) {
    int parts = 1;
    long long curr = 0;
    for (int x : a) {
        if (curr + x <= M)
            curr += x;
        else {
            parts++;
            curr = x;
        }
    }
    return parts;
}

int largestSubarraySumMinimized(vector<int>& a, int k) {
    int n = a.size();
    int low  = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int needed = countPartitions(a, mid);
        if (needed > k)
            low = mid + 1;    // mid too small → more partitions than k
        else
            high = mid - 1;   // mid feasible → try smaller
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << largestSubarraySumMinimized(a, k) << "\n";
    return 0;
}
