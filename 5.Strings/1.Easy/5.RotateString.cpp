#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(const string &s, const string &goal) {
        if (s.size() != goal.size()) return false;
        // Concatenate and check substring
        string temp = s + s;
        return temp.find(goal) != string::npos;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, goal;
    if (!(cin >> s >> goal)) {
        cerr << "";
        return 1;
    }

    Solution sol;
    cout << (sol.rotateString(s, goal) ? "true\n" : "false\n");
    return 0;
}