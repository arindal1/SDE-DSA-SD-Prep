#include <bits/stdc++.h>
using namespace std;


vector<int> partitionLabels(const string& s) {
    int n = s.size();
    vector<int> last(26, 0);
    for (int i = 0; i < n; ++i)
        last[s[i] - 'a'] = i;

    vector<int> res;
    int start = 0, end = 0;
    for (int i = 0; i < n; ++i) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            res.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s); 

    vector<int> result = partitionLabels(s);
    for (int len : result) {
        cout << len << " ";
    }
    cout << "\n";
    return 0;
}