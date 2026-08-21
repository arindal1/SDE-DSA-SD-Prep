#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(const string &s) {
    if (s.empty()) return "";

    string t;
    t.reserve(2 * s.size() + 3);
    t.push_back('^');
    for (char c : s) {
        t.push_back('#');
        t.push_back(c);
    }
    t.push_back('#');
    t.push_back('$');

    int n = static_cast<int>(t.size());
    vector<int> p(n, 0);
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * center - i;

        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
            p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter lines (each line will be processed; EOF to stop):\n";
    string line;
    while (getline(cin, line)) {
        string ans;
        try {
            ans = longestPalindrome(line);
        } catch (...) {
            ans = "";
        }
        cout << "Input: \"" << line << "\"\n";
        cout << "Longest palindrome: \"" << ans << "\"\n\n";
    }
    return 0;
}
