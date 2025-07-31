#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(const string& S) {
    string ans;
    ans.reserve(S.size());
    int balance = 0;
    for (char c : S) {
        if (c == '(') {
            if (balance > 0) 
                ans += c;
            balance++;
        } else {
            balance--;
            if (balance > 0) 
                ans += c;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    cout << removeOuterParentheses(S) << "\n";
    return 0;
}
