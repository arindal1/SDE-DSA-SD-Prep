#include <bits/stdc++.h>
using namespace std;

long long sumByD(const vector<int>& arr, int d) {
    long long total = 0;
    for (int x : arr)
        total += (x + d - 1) / d;
    return total;
}

int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size();
    if (n > limit) 
        return -1;

    int low  = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans   = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long total = sumByD(arr, mid);
        if (total <= limit) {
            ans  = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, limit;
    cin >> n >> limit;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << smallestDivisor(arr, limit) << "\n";
    return 0;
}