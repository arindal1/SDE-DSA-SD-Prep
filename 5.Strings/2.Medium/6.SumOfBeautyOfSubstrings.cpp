#include <bits/stdc++.h>
using namespace std;

int beautySum(string s) {
    int n = static_cast<int>(s.size());
    long long ans = 0;
    
    for (int i = 0; i < n; ++i) {
        array<int, 26> freq = {0};
        for (int j = i; j < n; ++j) {
            ++freq[s[j] - 'a'];

            int mx = 0;
            int mn = INT_MAX;
            for (int k = 0; k < 26; ++k) {
                int f = freq[k];
                if (f > 0) {
                    mx = max(mx, f);
                    mn = min(mn, f);
                }
            }
            if (mn != INT_MAX) ans += (mx - mn);
        }
    }

    if (ans > INT_MAX) return INT_MAX;
    return static_cast<int>(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    cout << beautySum(s) << '\n';
    return 0;
}
