#include <bits/stdc++.h>
using namespace std;

// Simulation of the API; we store the first bad version:
int FIRST_BAD;

// Mocked API:
bool isBadVersion(int version) {
    return version >= FIRST_BAD;
}

int firstBadVersion(int n) {
    int low = 1, high = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
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

    int n;
    // Read total number of versions and the first bad version index
    // Format: n FIRST_BAD
    cin >> n >> FIRST_BAD;

    int result = firstBadVersion(n);
    cout << result << "\n";
    return 0;
}
