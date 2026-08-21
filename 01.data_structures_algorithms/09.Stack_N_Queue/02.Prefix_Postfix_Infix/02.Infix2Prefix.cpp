#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPrefix(string s) {
    // 1) reverse the string
    reverse(s.begin(), s.end());
    // 2) swap parentheses
    for (char &ch : s) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    stack<char> st;
    string out;

    for (char ch : s) {
        if (isspace(static_cast<unsigned char>(ch))) continue;

        // operand
        if (isalnum(static_cast<unsigned char>(ch))) {
            out += ch;
        }
        // left parenthesis (which was ')' before swap)
        else if (ch == '(') {
            st.push(ch);
        }
        // right parenthesis (which was '(' before swap)
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                out += st.top();
                st.pop();
            }
            if (st.empty()) return "Invalid Expression"; // mismatched
            st.pop(); // discard '('
        }
        // operator
        else {
            while (!st.empty() && st.top() != '(') {
                int pc = prec(ch), pt = prec(st.top());
                // KEY: pop on higher precedence, or equal precedence when ch == '^'
                if (pt > pc || (pt == pc && ch == '^')) {
                    out += st.top();
                    st.pop();
                } else break;
            }
            st.push(ch);
        }
    }

    // pop remaining operators
    while (!st.empty()) {
        if (st.top() == '(' || st.top() == ')')
            return "Invalid Expression";
        out += st.top();
        st.pop();
    }

    // 4) reverse the postfix-result to get prefix
    reverse(out.begin(), out.end());
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    cout << "Prefix: " << infixToPrefix(s) << "\n";
    return 0;
}
