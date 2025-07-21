#include <bits/stdc++.h>
using namespace std;

bool canWePlace(const vector<int>& stalls, int d, int k) {
    int count = 1;
    int last  = stalls[0];
    for (int x : stalls) {
        if (x - last >= d) {
            count++;
            last = x;
            if (count == k) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n    = stalls.size();
    int low  = 1;
    int high = stalls[n-1] - stalls[0];
    int best = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canWePlace(stalls, mid, k)) {
            best = mid;       // feasible, try larger
            low  = mid + 1;
        } else {
            high = mid - 1;   // not feasible, decrease d
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; ++i) {
        cin >> stalls[i];
    }

    cout << aggressiveCows(stalls, k) << "\n";
    return 0;
}
