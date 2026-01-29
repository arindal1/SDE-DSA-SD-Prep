#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_val = 2e9, max_val = -2e9;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        min_val = min(min_val, a[i]);
        max_val = max(max_val, a[i]);
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    if (a == b) {
        cout << -1 << "\n";
        return;
    }

    int max_k = 2e9; 
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            int current_dist = max(abs(a[i] - min_val), abs(a[i] - max_val));
            max_k = min(max_k, current_dist);
        }
    }

    cout << max_k << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}