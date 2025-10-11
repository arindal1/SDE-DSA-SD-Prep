#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.size(), sign = 1;
    long res = 0;

    while (i < n && s[i] == ' ') i++;

    if (i < n && (s[i] == '+' || s[i] == '-'))
        sign = (s[i++] == '-') ? -1 : 1;

    while (i < n && isdigit(static_cast<unsigned char>(s[i]))) {
        res = res * 10 + (s[i] - '0');

        if (res > INT_MAX)
            return (sign == 1) ? INT_MAX : INT_MIN;

        i++;
    }

    return static_cast<int>(res * sign);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter strings to convert to integers (Ctrl+D to stop):\n";
    string line;
    while (getline(cin, line)) {
        try {
            cout << "\"" << line << "\" -> " << myAtoi(line) << "\n";
        } catch (...) {
            cout << "Error occurred!\n";
        }
    }
    return 0;
}