#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c) {
    return isalnum(static_cast<unsigned char>(c)); // A-Z, a-z, 0-9
}

bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

string postfixToPrefix(const string& s) {
    stack<string> st;

    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char ch = static_cast<unsigned char>(s[i]);

        if (isspace(ch)) continue;

        if (isOperand(ch)) {
            st.push(string(1, s[i]));
        } else if (isOperator(ch)) {
            if (st.size() < 2)
                throw runtime_error("Invalid expression: insufficient operands for operator.");
            string t1 = st.top(); st.pop(); // right
            string t2 = st.top(); st.pop(); // left
            st.push(string(1, s[i]) + t2 + t1); // prefix: op + left + right
        } else {
            throw runtime_error(string("Invalid character in expression: '") + s[i] + "'");
        }
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
        cout << "Prefix: " << postfixToPrefix(s) << "\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}
