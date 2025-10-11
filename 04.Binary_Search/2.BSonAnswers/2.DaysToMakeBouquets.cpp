#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<int>& arr, int d, int m, int k) {
    int bouquets = 0, consec = 0;
    for (int x : arr) {
        if (x <= d) {
            if (++consec == k) {
                bouquets++;
                consec = 0;
                if (bouquets >= m) return true;
            }
        } else {
            consec = 0;
        }
    }
    return false;
}

int minDaysToBouquets(vector<int>& arr, int k, int m) {
    long long needed = 1LL * m * k;
    int n = arr.size();
    if (needed > n) return -1;

    int low  = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (possible(arr, mid, m, k)) {
            ans = mid;
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

    int n, k, m;
    cin >> n >> k >> m;
    vector<int> bloomDays(n);
    for (int i = 0; i < n; ++i) {
        cin >> bloomDays[i];
    }

    int res = minDaysToBouquets(bloomDays, k, m);
    cout << res << "\n";
    return 0;
}