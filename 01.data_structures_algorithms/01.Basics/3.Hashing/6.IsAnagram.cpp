#include <bits/stdc++.h>
using namespace std;

bool isAnagram(const string &a, const string &b) {
    if (a.size() != b.size()) return false;
    int freq[26] = {0};

    for (int i = 0; i < (int)a.size(); i++) {
        freq[a[i] - 'a']++;
        freq[b[i] - 'a']--;
    }
    for (int c = 0; c < 26; c++)
        if (freq[c] != 0)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    cout << (isAnagram(s1, s2) ? "Yes\n" : "No\n");
    return 0;
}
