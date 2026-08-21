#include <bits/stdc++.h>
using namespace std;

int findMax(const vector<int>& v) {
    return *max_element(v.begin(), v.end());
}

long long calculateTotalHours(const vector<int>& v, int k) {
    long long total = 0;
    for (int x : v) {
        total += (x + k - 1) / k;
    }
    return total;
}

int minimumRateToEatBananas(const vector<int>& v, int h) {
    int low = 1, high = findMax(v);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long hours = calculateTotalHours(v, mid);
        if (hours <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; ++i) {
        cin >> piles[i];
    }

    int k = minimumRateToEatBananas(piles, h);
    cout << k << "\n";
    return 0;
}