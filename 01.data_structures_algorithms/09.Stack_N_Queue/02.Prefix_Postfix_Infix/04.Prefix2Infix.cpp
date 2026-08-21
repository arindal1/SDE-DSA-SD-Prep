#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c) {
    return isalnum(static_cast<unsigned char>(c));
}

bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

string prefixToInfix(const string& s) {
    stack<string> st;
    int i = static_cast<int>(s.size()) - 1;

    while (i >= 0) {
        unsigned char ch = static_cast<unsigned char>(s[i]);

        if (isspace(ch)) {
            --i;
            continue;
        }

        if (isOperand(ch)) {
            st.push(string(1, s[i]));
        } else if (isOperator(ch)) {
            if (st.size() < 2)
                throw runtime_error("Invalid expression: insufficient operands for operator.");
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push("(" + t1 + s[i] + t2 + ")");
        } else {
            throw runtime_error(string("Invalid character in expression: '") + s[i] + "'");
        }
        --i;
    }

    if (st.size() != 1)
        throw runtime_error("Invalid expression: leftover operands/operators.");

    return st.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    try {
        cout << "Infix: " << prefixToInfix(s) << "\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}
