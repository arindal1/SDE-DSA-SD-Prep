#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(const string &s, const string &t) {
        if (s.size() != t.size()) return false;
        vector<int> lastS(256, 0), lastT(256, 0);

        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char cs = static_cast<unsigned char>(s[i]);
            unsigned char ct = static_cast<unsigned char>(t[i]);

            if (lastS[cs] != lastT[ct]) return false;

            lastS[cs] = i + 1;
            lastT[ct] = i + 1;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    if (!(cin >> s >> t)) {
        cout << "Input error\n";
        return 0;
    }

    Solution sol;
    cout << (sol.isIsomorphic(s, t) ? "true\n" : "false\n");
    return 0;
}