#include <bits/stdc++.h>
using namespace std;

string frequencySort(const string &s) {
    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;

    vector<pair<char, int>> vec(freq.begin(), freq.end());
    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    string result;
    result.reserve(s.size());
    for (auto &p : vec) {
        result.append(p.second, p.first);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 1;
    }

    cout << frequencySort(s) << "\n";
    return 0;
}