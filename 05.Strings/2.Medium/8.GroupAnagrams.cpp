#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    mp.reserve(strs.size()); 

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(move(s));
    }

    vector<vector<string>> result;
    result.reserve(mp.size());
    for (auto& kv : mp) {
        result.push_back(move(kv.second));
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto ans = groupAnagrams(strs);

    for (auto& group : ans) {
        cout << "[ ";
        for (auto& w : group) cout << w << " ";
        cout << "]\n";
    }
    return 0;
}
