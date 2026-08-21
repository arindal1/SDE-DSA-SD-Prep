#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

bool isLeftAssociative(char c) {
    // +, -, *, / are left-associative; ^ is right-associative
    return (c != '^');
}

bool isOperand(char c) {
    return (isalnum(static_cast<unsigned char>(c))); // A-Z, a-z, 0-9
}

string infixToPostfix(const string& s) {
    stack<char> st;
    string out;

    for (char ch : s) {
        if (isspace(static_cast<unsigned char>(ch))) continue; // ignore spaces

        if (isOperand(ch)) {
            out += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            // pop until '('
            while (!st.empty() && st.top() != '(') {
                out += st.top();
                st.pop();
            }
            if (st.empty()) {
                throw runtime_error("Invalid expression: mismatched parentheses");
            }
            st.pop(); // discard '('
        }
        else { // operator
            while (!st.empty() && st.top() != '(') {
                int pc = prec(ch), pt = prec(st.top());
                if (pt > pc || (pt == pc && isLeftAssociative(ch))) {
                    out += st.top();
                    st.pop();
                } else break;
            }
            st.push(ch);
        }
    }

    // pop remaining
    while (!st.empty()) {
        if (st.top() == '(' || st.top() == ')') {
            throw runtime_error("Invalid expression: mismatched parentheses");
        }
        out += st.top();
        st.pop();
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s); // allow spaces
    try {
        cout << "Postfix: " << infixToPostfix(s) << "\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}
