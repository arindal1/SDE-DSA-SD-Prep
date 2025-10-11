#include <bits/stdc++.h>
using namespace std;

int maxDepth(const string &s) {
    int maxi = 0, ctr = 0;
    for (char ch : s) {
        if (ch == '(')
            maxi = max(maxi, ++ctr);
        else if (ch == ')')
            ctr--;
    }
    return maxi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    cout << maxDepth(s) << "\n";
}