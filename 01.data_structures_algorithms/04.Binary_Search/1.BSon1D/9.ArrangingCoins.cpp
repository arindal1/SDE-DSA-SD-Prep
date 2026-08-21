#include <bits/stdc++.h>
using namespace std;

int arrangeCoins(int n) {
    long long low = 0, high = n, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long needed = mid * (mid + 1) / 2;
        if (needed == n) {
            return (int)mid;
        } else if (needed < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return (int)ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    cout << arrangeCoins((int)n) << "\n";
    return 0;
}