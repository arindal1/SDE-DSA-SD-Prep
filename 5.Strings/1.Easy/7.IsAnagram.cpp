#include <bits/stdc++.h>
using namespace std;


    // Assumes only lowercase 'a'..'z' in s and t
bool isAnagram(const string &s, const string &t) {
        if (s.size() != t.size()) return false;
        int freq[26] = {0};

        for (int i = 0; i < (int)s.size(); ++i) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for (int c = 0; c < 26; ++c)
            if (freq[c] != 0)
                return false;
        return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    if (!(cin >> s >> t)) {
        cerr << "Please provide two whitespace-separated strings as input.\n";
        return 1;
    }

    Solution sol;
    cout << (sol.isAnagram(s, t) ? "true\n" : "false\n");
    return 0;
}