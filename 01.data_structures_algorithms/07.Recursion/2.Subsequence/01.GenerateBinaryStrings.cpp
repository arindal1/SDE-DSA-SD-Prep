#include <bits/stdc++.h>
using namespace std;

void generate(int n, string curr, vector<string>& result) {
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }

    generate(n, curr + "0", result);

    if (curr.empty() || curr.back() != '1') {
        generate(n, curr + "1", result);
    }
}

int main() {
    int n = 3;
    vector<string> result;

    generate(n, "", result);

    for (string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}