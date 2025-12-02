#include <bits/stdc++.h>

using namespace std;

int distinctChars(string s, int k) {
    int n = s.size(), maxLen = 0;
    int l = 0, r = 0;
    unordered_map<char, int> map;

    while (r < n) {
        map[s[r]]++;

        while (map.size() > k) {
            map[s[l]]--;

            if (map[s[l]] == 0)
                map.erase(s[l]);
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

int main() {
    string s = "aababbcaacc";
    int k = 2;

    cout << distinctChars(s, k);
    return 0;
}