#include<bits/stdc++.h>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> mpp;
    for (char c : s)
        mpp[c]++;
    for (int i = 0; i < s.size(); i++) {
        if (mpp[s[i]] == 1)
            return i;
    }
    return -1;
}

int main() {
    string s = "abbsba";

    cout << firstUniqChar(s);
    return 0;
}