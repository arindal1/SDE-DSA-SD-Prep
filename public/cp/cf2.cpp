#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') pos.push_back(i);
    }

    if (pos.empty()) {
        cout << (n + 2) / 3 << "\n";
        return;
    }

    long long total = pos.size();

    int prefix_k = pos[0];
    total += prefix_k / 3;

    for (int i = 0; i < (int)pos.size() - 1; i++) {
        int gap_k = pos[i+1] - pos[i] - 1;
        if (gap_k >= 3) {
            total += (gap_k - 1) / 3;
        }
    }

    int suffix_k = n - 1 - pos.back();
    total += suffix_k / 3;

    cout << total << "\n";
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