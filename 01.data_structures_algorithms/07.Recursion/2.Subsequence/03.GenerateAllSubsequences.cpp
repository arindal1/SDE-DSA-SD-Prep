#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(string &s, int index, string ¤t, vector<string> &result) {
        if (index == s.size()) {
            result.push_back(current);
            return;
        }

        helper(s, index + 1, current, result);
        current.push_back(s[index]);
        helper(s, index + 1, current, result);
        current.pop_back();
    }

    vector<string> getSubsequences(string s) {
        vector<string> result;
        string current = "";    
        helper(s, 0, current, result);
        return result;
    }
};

int main() {
    string s = "abc";
    Solution sol;

    vector<string> subsequences = sol.getSubsequences(s);

    for (auto &subseq : subsequences) {
        cout << "\"" << subseq << "\"" << endl;
    }

    return 0;
}
