#include<bits/stdc++.h>

using namespace std;

bool found = false;
int p[105];
bool used[105];

void backtrack(int i, int n) {
    if (found)
        return;
    if (i == 0) {
        found = true;
        for (int k = 1; k <= n; ++k) {
            cout << p[k] << (k == n ? "" : " ");
        }
        cout << "\n";
        return;
    }

    for (int val = 1; val <= n; ++val) {
        if (!used[val]) {
            if (i == n || abs(val - p[i + 1]) % i == 0) {
                p[i] = val;
                used[val] = true;
                backtrack(i - 1, n);
                used[val] = false; 
                if (found)
                    return;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    found = false;
    for (int i = 0; i <= n; ++i) {
        used[i] = false;
    }
    backtrack(n, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}