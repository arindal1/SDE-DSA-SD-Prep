#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(const string &s) {
    int n = static_cast<int>(s.size());
    vector<int> lastIndex(256, -1);
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        unsigned char uc = static_cast<unsigned char>(s[right]);
        if (lastIndex[uc] >= left) {
            left = lastIndex[uc] + 1;
        }
        lastIndex[uc] = right;
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Quick manual tests
    vector<string> tests = {
        "abcabcbb", // 3
        "bbbbb",    // 1
        "pwwkew",   // 3
        "",         // 0
        " ",        // 1 (single space)
        "dvdf",     // 3 ("vdf")
        "anviaj"    // 5 ("nviaj")
    };

    for (auto &t : tests) {
        cout << '"' << t << "\" -> " << lengthOfLongestSubstring(t) << '\n';
    }

    return 0;
}