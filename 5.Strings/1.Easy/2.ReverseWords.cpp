#include <bits/stdc++.h>
using namespace std;

void trimSpaces(string &s) {
    int n = s.size();
    int i = 0; // read pointer
    int j = 0; // write pointer

    while (i < n && s[i] == ' ') ++i;

    for (; i < n; ++i) {
        if (s[i] == ' ') {
            if (j > 0 && s[j - 1] == ' ') continue;
            s[j++] = ' ';
        } else {
            s[j++] = s[i];
        }
    }

    if (j > 0 && s[j - 1] == ' ') --j;

    s.resize(j);
}

void reverseWordsInPlace(string &s) {
    trimSpaces(s);
    if (s.empty()) return;

    reverse(s.begin(), s.end());

    int n = s.size();
    int start = 0;
    for (int i = 0; i <= n; ++i) {
        if (i == n || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    reverseWordsInPlace(s);
    cout << s << "\n";
    return 0;
}
