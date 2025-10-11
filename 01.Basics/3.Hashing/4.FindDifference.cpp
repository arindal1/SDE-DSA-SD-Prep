#include<bits/stdc++.h>

using namespace std;

char findTheDifference(string s, string t) {
    unordered_map<char, int> mpp;
    for (char c : s)
        mpp[c]++;
    for (char c : t)
        mpp[c]++;
    for (auto i : mpp) {
        if (i.second % 2 != 0)
            return i.first;
    }
    return 'a';
}

int main() {
    string s = "apple";
    string t = "atpple";

    cout << findTheDifference(s, t);
    return 0;
}