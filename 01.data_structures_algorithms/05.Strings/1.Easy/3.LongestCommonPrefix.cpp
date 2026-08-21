#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
        return "";
    sort(strs.begin(), strs.end());

    string first_string = strs.front();
    string last_string  = strs.back();
    string ans = "";
    int i = 0, n = min(first_string.size(), last_string.size());
    while (i < n && first_string[i] == last_string[i]) {
        ans += first_string[i];
        i++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, strs[i]);
    }

    cout << longestCommonPrefix(strs);
    return 0;
}
